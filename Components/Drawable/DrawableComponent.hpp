/* 
 * File:   DrawableComponent.hpp
 * Author: bombpersons
 *
 * Created on June 18, 2011, 6:51 PM
 */

#ifndef DRAWABLECOMPONENT_HPP
#define	DRAWABLECOMPONENT_HPP

#include "../../Component.hpp"

namespace Dokuro2 {

    class DrawableComponent : public Component {
    public:
        DrawableComponent();
        virtual ~DrawableComponent();
        
        /* Post Update */
        virtual void PostUpdate(Entity* _entity, float _time);
        
        /* Drawing */
        virtual void Draw(Entity* _entity, float _time);
        
    private:

    };

}

#endif	/* DRAWABLECOMPONENT_HPP */

