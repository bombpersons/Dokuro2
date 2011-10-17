/* 
 * File:   Entity.cpp
 * Author: bombpersons
 * 
 * Created on June 16, 2011, 4:05 PM
 */

#include "Entity.hpp"

namespace Dokuro2 {
    
    REGISTER_BINDING_DEC(Entity)

    Entity::Entity() {
        Init();
    }
    
    Entity::Entity(vector<Component*> _components) {
        for (vector<Component*>::iterator it = _components.begin(); it != _components.end(); ++it) {
            AddComponent((*it));
        }
    }
    
    Entity::~Entity() {
        // Delete all the components
        for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
            delete (*it);
        }
    }
    
    /* ----------------------------- Bind ----------------------------------- */
    void Entity::BindEntity(HSQUIRRELVM _vm) {
        // Create a class for this type
        Sqrat::Class<Entity, Sqrat::NoCopy<Entity> > entity(_vm);
        
        // Bind functions
        entity.Func("Init", &Entity::Init);
        entity.Func("PreUpdate", &Entity::PreUpdate);
        entity.Func("Update", &Entity::Update);
        entity.Func("PostUpdate", &Entity::PostUpdate);
        entity.Func("HandleEvent", &Entity::HandleEvent);
        entity.Func("OnAdd", &Entity::OnAdd);
        entity.Func("OnRemove", &Entity::OnRemove);
        entity.Func("AddComponent", &Entity::AddComponent);
        entity.Func("SwapComponent", &Entity::SwapComponent);
        entity.Func("RemoveComponent", &Entity::RemoveComponent);
        entity.Func("GetComponent", &Entity::GetComponent);
        entity.Func("GetRenderTarget", &Entity::GetRenderTarget);
        entity.Func("GetResourceManager", &Entity::GetResourceManager);
        entity.Func("GetInputManager", &Entity::GetInputManager);
        entity.Func("SetRenderTarget", &Entity::SetRenderTarget);
        entity.Func("SetResourceManger", &Entity::SetResourceManager);
        entity.Func("SetInputManager", &Entity::SetInputManager);
        entity.Var("Position", &Entity::position);
        entity.Var("Center", &Entity::center);
        entity.Prop("Rotation", &Entity::GetRotation, &Entity::SetRotation);
        entity.Var("Scale", &Entity::scale);
        entity.Func("SetPosition", &Entity::SetPosition);
        entity.Func("GetPosition", &Entity::GetPosition);
        entity.Func("GetCenter", &Entity::GetCenter);
        entity.Func("SetCenter", &Entity::SetCenter);
        entity.Func("GetRotation", &Entity::GetRotation);
        entity.Func("SetRotation", &Entity::SetRotation);
        entity.Func("GetScale", &Entity::GetScale);
        entity.Func("SetScale", &Entity::SetScale);
        
        // Bind to the vm
        Sqrat::RootTable(_vm).Bind("Entity", entity);
    }
    
    /* ---------------------------- Init ------------------------------------ */
    void Entity::Init() {
        // Set default values
        SetResourceManager(NULL);
        SetRenderTarget(NULL);
        SetInputManager(NULL);
        rootWindow = NULL;
        
        // Set default positions
        SetPosition(sf::Vector2f());
        SetCenter(sf::Vector2f());
        SetRotation(0.0f);
        SetScale(sf::Vector2f(1.0f, 1.0f));
    }
    
    /* ------------------------- Update Functions --------------------------- */
    void Entity::PreUpdate(float _time) {
        // Loop through all the components and update them
        for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
            (*it)->PreUpdate(this, _time);
        }
    }
    
    void Entity::Update(float _time) {
        // Loop through all the components and update them
        for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
            (*it)->Update(this, _time);
        }
    }
    
    void Entity::PostUpdate(float _time) {
        // Loop through all the components and update them
        for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
            (*it)->PostUpdate(this, _time);
        }
    }
    
    /* --------------------------- Handle Event ----------------------------- */
    void Entity::HandleEvent(const sf::Event& _event) {
        // Send the event to all of the components to see if they want to do any
        // thing with it.
        for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
            (*it)->HandleEvent(_event);
        }
    }    
    
    /* ---------------------------- On Functions ---------------------------- */
    void Entity::OnAdd(Entity* _entity) {
        parent = _entity;
        SetRenderTarget(parent->GetRenderTarget());
        SetResourceManager(parent->GetResourceManager());
        SetInputManager(parent->GetInputManager());
        rootWindow = parent->GetRootWindow();
        
        // Call BeenAdded functions on all the components
        for (auto it = components.begin(); it != components.end(); ++it) {
            (*it)->OnBeenAdded(this);
        }
    }
    
    void Entity::OnRemove(Entity* _entity) {
        parent = NULL;
        SetRenderTarget(NULL);
        SetResourceManager(NULL);
        SetInputManager(NULL);
        rootWindow = NULL;
        
        // Call BeenRemoved functions on all the components
        for (auto it = components.begin(); it != components.end(); ++it) {
            (*it)->OnBeenRemoved(this);
        }
    }
    
    /* -------------------------- Adding Components ------------------------- */
    void Entity::AddComponent(Component* _comp) {
        // Check the component isn't NULL
        if (_comp == NULL)
            throw Exception(Level::Bad, "Cannot add null component.");
        
        // Check that the update dependencies for this component are already
        // added.
        if (!CheckUpdateDependencies(_comp))
            throw Exception(Level::Bad, "Update Dependencies have not been met!");
        
        // Add the component to the vector
        components.push_back(_comp);
        
        // Trace
        Tracer::Trace(Level::Meh) << _comp->GetNames().back() << " addded." << endl; 
        
        // Call the OnAdd function
        _comp->OnAdd(this);
    }
    
    void Entity::SwapComponent(string _name, Component* _comp) {
        // Make sure the component isn't null
        if (!_comp)
            throw Exception(Level::Bad, "Cannot add null Component!");
        
        // Check if the component exists with that name
        vector<Component*>::iterator it = GetComponentIterator(_name);
        if (it == components.end())
            throw Exception(Level::Bad, "Component \"" + _name + "\" Couldn't be found.");
        
        // Call the on swap function
        (*it)->OnSwap(this);
        
        // Delete the old component
        delete (*it);
        
        // Insert the new component
        it[0] = _comp;
    }
    
    void Entity::RemoveComponent(string _name) {
        // Check if the component is here
        vector<Component*>::iterator it = GetComponentIterator(_name);
        if (it == components.end())
            throw Exception(Level::Bad, "Component \"" + _name + "\" Couldn't be found.");
        
        // Remove all components with this name
        for (; it != components.end(); it = GetComponentIterator(_name)) {
            // Call the on remove function
            (*it)->OnRemove(this);
            
            // Delete the component
            delete (*it);
            
            // Remove it
            components.erase(it);
        }
    }
    
    Component* Entity::GetComponent(string _name) {
        // Find a component with this name in it's names
        vector<Component*>::iterator it = GetComponentIterator(_name);
        if (it != components.end())
            return (*it);
        
        Tracer::Trace(Level::NotGood) << "Couldn't find " << _name << endl;
        return NULL;
    }
    
    /* ---------------------- Check update dependencies --------------------- */
    bool Entity::CheckUpdateDependencies(Component* _comp) {
        // Check if _comp is null
        if (!_comp)
            throw Exception(Level::Bad, "Cannot check update dependencies of null component!");
        
        // If there are no update dependencies then there is no point in continuing
        if (_comp->GetUpdateDependencies().size() == 0)
            return true;
        
        for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
            for (list<string>::iterator it2 = (*it)->GetNames().begin(); it2 != (*it)->GetNames().end(); ++it2) {
                for (list<string>::iterator it3 = _comp->GetUpdateDependencies().begin(); it3 != _comp->GetUpdateDependencies().end(); ++it3) {
                    if ((*it2) == (*it3))
                        return true;
                }
            }
        }
        return false;
    }
    
    /* --------------------------- Gets a components iterator --------------- */
    vector<Component*>::iterator Entity::GetComponentIterator(string _name) {
        // Find a component with this name in it's names
        for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
            for (list<string>::iterator it2 = (*it)->GetNames().begin(); it2 != (*it)->GetNames().end(); ++it2) {
                if ((*it2) == _name)
                    return it;
            }
        }
        
        return components.end();
    }
    
    /* --------------------------- GetComponentList ------------------------- */
    vector<Component*>& Entity::GetComponentList() {
        return components;
    }
    
    /* ----------------------- Get the render target ------------------------ */
    sf::RenderTarget* Entity::GetRenderTarget() {
        return target;
    }
    
    void Entity::SetRenderTarget(sf::RenderTarget* _target) {
        target = _target;
    }
    
    /* ------------------------ Get the resource manager -------------------- */
    ResourceManager* Entity::GetResourceManager() {
        return resource;
    }
    
    void Entity::SetResourceManager(ResourceManager* _resource) {
        resource = _resource;
    }
    
    /* ---------------------- Get the input manager ------------------------- */
    InputManager* Entity::GetInputManager() {
        return input;
    }
    
    void Entity::SetInputManager(InputManager* _input) {
        input = _input;
    }
    
    /* ---------------------- Get the root window --------------------------- */
    sf::Window* Entity::GetRootWindow() {
        return rootWindow;
    }
    
    void Entity::SetRootWindow(sf::Window* _window) {
        rootWindow = _window;
    }
    
    /* ---------------------- The orientation of the entity ----------------- */
    sf::Vector2f Entity::GetPosition() {
        return position;
    }
    
    void Entity::SetPosition(sf::Vector2f _pos) {
        position = _pos;
    }
    
    sf::Vector2f Entity::GetCenter() {
        return center;
    }
    
    void Entity::SetCenter(sf::Vector2f _cent) {
        center = _cent;
    }
    
    float Entity::GetRotation() {
        return rotation;
    }
    
    void Entity::SetRotation(float _rot) {
        rotation = _rot;
    }
    
    sf::Vector2f Entity::GetScale() {
        return scale;
    }
    
    void Entity::SetScale(sf::Vector2f _scale) {
        scale = _scale;
    }
}

