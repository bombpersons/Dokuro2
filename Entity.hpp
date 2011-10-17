/* 
 * File:   Entity.hpp
 * Author: bombpersons
 *
 * Created on June 16, 2011, 4:05 PM
 */

#ifndef ENTITY_HPP
#define	ENTITY_HPP

#include "Exceptions/Exception.hpp"
#include "Component.hpp"

#include "ResourceManager/ResourceManager.hpp"
#include "InputManager/InputManager.hpp"

#include <vector>
#include <map>
using namespace std;

#include <SFML/Graphics.hpp>

#include "Sqrat/sqrat.h"
#include "Squirrel/Bindings.hpp"

namespace Dokuro2 {

    class Entity : public sf::NonCopyable {
    public:
        Entity();
        Entity(vector<Component*> _components);
        virtual ~Entity();
        
        /* Bind to squirrel */
        static void BindEntity(HSQUIRRELVM _vm);
        
        /* Initialization */
        virtual void Init();
        
        /* Update Functions */
        virtual void PreUpdate(float _time);
        virtual void Update(float _time);
        virtual void PostUpdate(float _time);
        
        /* Handle Event */
        virtual void HandleEvent(const sf::Event& _event);        
        
        /* On functions */
        virtual void OnAdd(Entity* _parent); // Called when added to a list.
        virtual void OnRemove(Entity* _parent); // Called when removed from a list.
        
        /* Adding Components */
        virtual void AddComponent(Component* _comp);
        virtual void SwapComponent(string _name, Component* _comp);
        virtual void RemoveComponent(string _name);
        virtual Component* GetComponent(string _name);
        
        /* ------------------------------------------------------------- Gets */
        /* Get the render target */
        virtual sf::RenderTarget* GetRenderTarget();
        /* Get the resource manager */
        virtual ResourceManager* GetResourceManager();
        /* Get the input manager */
        virtual InputManager* GetInputManager();
        /* Get the root window */
        virtual sf::Window* GetRootWindow();
        
        /* ------------------------------------------------------------- Sets */
        /* Set the render target */
        virtual void SetRenderTarget(sf::RenderTarget* _target);
        /* Set the resource manager */
        virtual void SetResourceManager(ResourceManager* _resource);
        /* Set the input manager */
        virtual void SetInputManager(InputManager* _input);
        /* Set the root window */
        virtual void SetRootWindow(sf::Window* _window);
        
        /* Position and Orientation */
        virtual sf::Vector2f GetPosition();
        virtual void SetPosition(sf::Vector2f _pos);
        virtual sf::Vector2f GetCenter();
        virtual void SetCenter(sf::Vector2f _cen);
        virtual float GetRotation();
        virtual void SetRotation(float _rot);
        virtual sf::Vector2f GetScale();
        virtual void SetScale(sf::Vector2f _scale);
        
        /* Check for update dependencies */
        virtual bool CheckUpdateDependencies(Component* _comp);
        
        /* Get the iterator for a component name */
        virtual vector<Component*>::iterator GetComponentIterator(string _name);
        
        /* Get the component list */
        virtual vector<Component*>& GetComponentList();
        
        friend class Component;
protected:        
        sf::Vector2f position; // The position of the entity
        sf::Vector2f center; // The center of the entity
        float rotation; // The rotation of the entity
        sf::Vector2f scale; // The scale of the entity
        
        sf::RenderTarget* target; // The target to render to
        ResourceManager* resource; // The resource manager
        InputManager* input;  // The input manager
        Entity* parent; // The parent of this entity
        sf::Window* rootWindow; // The root window
        
        /* Storing Components */
        vector<Component*> components;
        
        REGISTER_BINDING_DEF
    };

}

#endif	/* ENTITY_HPP */

