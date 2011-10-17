/* 
 * File:   NonMapEntityListComponent.cpp
 * Author: bombpersons
 * 
 * Created on June 18, 2011, 5:29 PM
 */

#include "NonMapEntityListComponent.hpp"

namespace Dokuro2 {

    NonMapEntityListComponent::NonMapEntityListComponent() {
        AddName("NonMapEntityListComponent");
        Init();
    }
    
    /* -------------------------- Adding ------------------------------------ */
    void NonMapEntityListComponent::Add(Entity* _entity) {
        // Call the OnAdd function
        _entity->OnAdd(parent);
    }
}