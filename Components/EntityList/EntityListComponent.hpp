/* 
 * File:   EntityListComponent.hpp
 * Author: bombpersons
 *
 * Created on June 18, 2011, 4:18 PM
 */

#ifndef ENTITYLISTCOMPONENT_HPP
#define	ENTITYLISTCOMPONENT_HPP

#include "../../Component.hpp"
#include "../../Entity.hpp"

namespace Dokuro2 {
    /* Abstract class for an entity list */
    class EntityListComponent : public Component {
    public:
        EntityListComponent();
        virtual ~EntityListComponent();
        
        /* Pure virtual functions to access a list */
        virtual void Reset(); // Reset the internal iterator
        virtual Entity* GetNext(); // Increment the internal iterator and return
                                   // the next entity.
        virtual Entity* Peek(); // Get the entity at the iterator.
        
        /* Pre, Post, Update methods */
        virtual void PreUpdate(Entity* _entity, float _time);
        virtual void Update(Entity* _entity, float _time);
        virtual void PostUpdate(Entity* _entity, float _time);
        
        /* Send Events to entities in this list */
        virtual void HandleEvent(sf::Event& _event);
        
    protected:
    };

}

#endif	/* ENTITYLISTCOMPONENT_HPP */

