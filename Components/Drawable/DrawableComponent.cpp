/* 
 * File:   DrawableComponent.cpp
 * Author: bombpersons
 * 
 * Created on June 18, 2011, 6:51 PM
 */

#include "DrawableComponent.hpp"

namespace Dokuro2 {

    DrawableComponent::DrawableComponent() {
        AddName("DrawableComponent");
        Init();
    }

    DrawableComponent::~DrawableComponent() {
    }
    
    /* ---------------------------- Post Update ----------------------------- */
    void DrawableComponent::PostUpdate(Entity* _entity, float _time) {
        Component::PostUpdate(_entity, _time);
        
        /* Call Draw */
        Draw(_entity, _time);
    }
    
    /* ---------------------------- Draw ------------------------------------ */
    void DrawableComponent::Draw(Entity* _entity, float _time) {
    }
}