/* 
 * File:   ComponentFactory.cpp
 * Author: bombpersons
 * 
 * Created on August 7, 2011, 11:12 AM
 */

#include "ComponentFactory.hpp"

namespace Dokuro2 {

    /* @@@@@@@@@@@@@@@@@@@@@@@@@ static instances @@@@@@@@@@@@@@@@@@@@@@@@@@@ */
    unordered_map<string, CompFactoryFunction>& ComponentFactory::GetComponentMap() {
        static unordered_map<string, CompFactoryFunction> factory;
        return factory;
    }
    
    /* ------------------------------ Add a component ----------------------- */
    void ComponentFactory::AddComponent(string _name, CompFactoryFunction _func) {
        if (GetComponentMap().find(_name) != GetComponentMap().end()) {
            throw Exception(Level::Bad, "A component with the name \"" + _name + "\" has already been registered!");
        }
        
        GetComponentMap()[_name] = _func;
    }
    
    /* --------------------------- Create a component from a file ----------- */
    Component* ComponentFactory::GetComponentFromStream(ifstream& _file) {
        // Read the component name
        string name = Component::GetComponentNameFromFile(_file);
        
        // Get the component
        if (GetComponentMap().find(name) == GetComponentMap().end()) {
            throw Exception(Level::Bad, "Component \"" + name + "\" has not been registered!");
        }
        
        // Return it
        return GetComponentMap()[name](_file);
    }
    
    /* //////////////////// ComponentFactoryRegisterer ////////////////////// */
    ComponentFactoryRegisterer::ComponentFactoryRegisterer(string _name, CompFactoryFunction _func) {
        ComponentFactory::AddComponent(_name, _func);
    }
}

