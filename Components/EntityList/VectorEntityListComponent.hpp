/* 
 * File:   VectorEntityListComponent.hpp
 * Author: bombpersons
 *
 * Created on June 18, 2011, 4:38 PM
 */

#ifndef VECTORENTITYLISTCOMPONENT_HPP
#define	VECTORENTITYLISTCOMPONENT_HPP

#include "NonMapEntityListComponent.hpp"

#include "../../Exceptions/Exception.hpp"

#include <vector>
using namespace std;

namespace Dokuro2 {

    class VectorEntityListComponent : public NonMapEntityListComponent {
    public:
        VectorEntityListComponent();
        
        /* EntityListComponent Interface */
        virtual void Reset();
        virtual Entity* GetNext();
        virtual Entity* Peek();
        
        /* NonMapEntityListComponent Interface */
        virtual void Add(Entity* _entity);
        virtual Entity* GetIndex(int _i);
        virtual void RemoveAt(int _i);
        
    protected:
        vector<Entity*> entities;
        vector<Entity*>::iterator currentIt;
    };

}

#endif	/* VECTORENTITYLISTCOMPONENT_HPP */

