/* 
 * File:   Component.cpp
 * Author: bombpersons
 * 
 * Created on June 16, 2011, 3:42 PM
 */

#include "Component.hpp"
#include "Entity.hpp"

namespace Dokuro2 {
    REGISTER_COMP_DEC(Component);
    REGISTER_BINDING_DEC(Component);
    
    Component::Component() {
        AddName("Component");
        Init();
    }

    Component::~Component() {
    }
    
    /* ----------------------------- Bind ----------------------------------- */
    void Component::BindComponent(HSQUIRRELVM _vm) {
        Sqrat::ImprovedClass<Component, Sqrat::ImprovedNoCopyAllocator<Component> > comp = BaseBind<Component>(_vm);
        Sqrat::RootTable(_vm).Bind("Component", comp);
    }
    
    /* --------------------------- Load component from a file --------------- */
    Component* Component::LoadComponentFromFile(ifstream& _in) {
        // This is a base class, so there isn't anything to read from the file..
        return new Component();
    }
    
    /* -------------------------- Get a component name from a file ---------- */
    string Component::GetComponentNameFromFile(ifstream& _in) {
        string result = "";
        char temp = ' ';
        for (_in.read((char*)&temp, sizeof(char)); temp != '\0'; _in.read(&temp, sizeof(char))) {
            result += temp;
        }
        
        return result;
    }
    
    /* -------------------------- Save the component to a file -------------- */
    void Component::SaveToFile(ofstream& _out) {
        // This is a base class so we don't have anything to save
        return;
    }
    
    /* ------------------------ Get the size on disk ------------------------ */
    unsigned int Component::SizeOnDisk() {
        return 0;
    }
    
    /* ------------------------ Initialization ------------------------------ */
    void Component::Init() {
        
    }
    
    /* ----------------------- Update Functions ----------------------------- */
    void Component::PreUpdate(Entity* _entity, float _time) {
        
    }
    
    void Component::Update(Entity* _entity, float _time) {
        
    }
    
    void Component::PostUpdate(Entity* _entity, float _time) {
        
    }
    
    /* --------------------------- Handle Event ----------------------------- */
    void Component::HandleEvent(const sf::Event& _event) {
    }
    
    /* -------------------------- On* Functions ----------------------------- */
    void Component::OnAdd(Entity* _entity) {
        parent = _entity;
        if (IsReady())
            OnReady(_entity);
    }
    
    void Component::OnBeenAdded(Entity* _entity) {
        if (IsReady())
            OnReady(_entity);
    }
    
    void Component::OnRemove(Entity* _entity) {
        parent = NULL;
    }
    
    void Component::OnBeenRemoved(Entity* _entity) {
    }
    
    void Component::OnSwap(Entity* _entity) {
    }
    
    /* -------- Called when the parent entity has been fully initialized ---- */
    void Component::OnReady(Entity* _entity) {
    }
    
    /* ------------------------ IsReady ------------------------------------- */
    bool Component::IsReady() {
        if (!parent)
            return false;
        
        if (parent->GetResourceManager() && 
            parent->GetInputManager() &&
            parent->GetRenderTarget()) {
            return true;
        }
        
        return false;
    }
    
    /* -------------------------- Get the component name -------------------- */
    list<string>& Component::GetNames() {
        return names;
    }
    
    list<string>& Component::GetUpdateDependencies() {
        return updateDependencies;
    }
    
    /* ------------------------- Get the parent component ------------------- */
    Entity* Component::GetParentEntity() {
        return parent;
    }
    
    /* ---------------------- Add name -------------------------------------- */
    void Component::AddName(const string& _name) {
        names.push_back(_name);
    }
    
    /* ----------------------- Add Update Dependency ------------------------ */
    void Component::AddUpdateDependency(const string& _name) {
        updateDependencies.push_back(_name);
    }
}