/* 
 * File:   EntityListComponent.cpp
 * Author: bombpersons
 * 
 * Created on June 18, 2011, 4:23 PM
 */

#include "EntityListComponent.hpp"

namespace Dokuro2 {

    EntityListComponent::EntityListComponent() {
        AddName("EntityListComponent");
        Init();
    }

    EntityListComponent::~EntityListComponent() {
        // Delete all of the entities contained.
        Reset();
        for (Entity* entity = GetNext(); entity != NULL; entity = GetNext()) {
            delete entity;
        }        
    }
    
    /* ---------------------- Empty functions ------------------------------- */
    void EntityListComponent::Reset() {}
    Entity* EntityListComponent::GetNext() {return NULL;}
    Entity* EntityListComponent::Peek() {return NULL;}
    
    /* ------------------------ Update -------------------------------------- */
    void EntityListComponent::PreUpdate(Entity* _entity, float _time) {
        Component::PreUpdate(_entity, _time);
        Reset();
        for (Entity* entity = GetNext(); entity != NULL; entity = GetNext()) {
            entity->PreUpdate(_time);
        }
    }
    
    void EntityListComponent::Update(Entity* _entity, float _time) {
        Component::Update(_entity, _time);
        Reset();
        for (Entity* entity = GetNext(); entity != NULL; entity = GetNext()) {
            entity->Update(_time);
        }
    }
    
    void EntityListComponent::PostUpdate(Entity* _entity, float _time) {
        Component::PostUpdate(_entity, _time);
        Reset();
        for (Entity* entity = GetNext(); entity != NULL; entity = GetNext()) {
            entity->PostUpdate(_time);
        }
    }
    
    /* ---------------------------- Handle Events --------------------------- */
    void EntityListComponent::HandleEvent(sf::Event& _event) {
        Component::HandleEvent(_event);
        Reset();
        for (Entity* entity = GetNext(); entity != NULL; entity = GetNext()) {
            entity->HandleEvent(_event);
        }
    }
}