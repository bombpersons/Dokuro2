/* 
 * File:   NonMapEntityListComponent.hpp
 * Author: bombpersons
 *
 * Created on June 18, 2011, 5:29 PM
 */

#ifndef NONMAPENTITYLISTCOMPONENT_HPP
#define	NONMAPENTITYLISTCOMPONENT_HPP

#include "EntityListComponent.hpp"

namespace Dokuro2 {

    class NonMapEntityListComponent : public EntityListComponent {
    public:
        NonMapEntityListComponent();
        
        /* Abstract functions */
        virtual void Add(Entity* _entity);
        virtual Entity* GetIndex(int _i) = 0;
        virtual void RemoveAt(int _i) = 0;
        
    protected:
    };

}

#endif	/* NONMAPENTITYLISTCOMPONENT_HPP */

