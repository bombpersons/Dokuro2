/* 
 * File:   VectorEntityListComponent.cpp
 * Author: bombpersons
 * 
 * Created on June 18, 2011, 4:38 PM
 */

#include "VectorEntityListComponent.hpp"

namespace Dokuro2 {

    VectorEntityListComponent::VectorEntityListComponent() {
        AddName("VectorEntityListComponent");
        Init();
    }
    
    /* ------------------ EntityListComponent Interface --------------------- */
    void VectorEntityListComponent::Reset() {
        currentIt = entities.begin();
    }
    
    Entity* VectorEntityListComponent::GetNext() {
        Entity* entity = Peek();
        ++currentIt;
        return entity;
    }
    
    Entity* VectorEntityListComponent::Peek() {
        Entity* entity = NULL;
        if (currentIt != entities.end()) {
            entity = (*currentIt);
        }
        return entity;
    }
    
    /* ------------------ NonMapEntityListComponent ------------------------- */
    void VectorEntityListComponent::Add(Entity* _entity) {
        NonMapEntityListComponent::Add(_entity);
        
        entities.push_back(_entity);
    }
    
    Entity* VectorEntityListComponent::GetIndex(int _i) {
        if (_i >= entities.size() || _i < 0)
            throw Exception(Level::Bad, "Index Out Of Bounds!");
        
        return entities[_i];
    }
    
    void VectorEntityListComponent::RemoveAt(int _i) {
        if (_i >= entities.size() || _i < 0)
            throw Exception(Level::Bad, "Index Out Of Bounds!");
        
        // Call the OnRemove function
        (*(entities.begin() + _i))->OnRemove(parent);
        
        // Erase it from the vector
        entities.erase(entities.begin() + _i);
    }
}