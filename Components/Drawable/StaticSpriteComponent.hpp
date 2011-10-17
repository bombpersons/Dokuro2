/* 
 * File:   StaticSpriteComponent.hpp
 * Author: bombpersons
 *
 * Created on June 18, 2011, 7:11 PM
 */

#ifndef STATICSPRITECOMPONENT_HPP
#define	STATICSPRITECOMPONENT_HPP

#include "SpriteComponent.hpp"
#include "../../Entity.hpp"

#include <SFML/Graphics.hpp>

namespace Dokuro2 {

    class StaticSpriteComponent : public SpriteComponent {
    public:
        StaticSpriteComponent(tr1::shared_ptr<sf::Texture> _image);
        virtual ~StaticSpriteComponent();
        
        /* Bind */
        static void BindStaticSpriteComponent(HSQUIRRELVM _vm);
        
        /* Init */
        virtual void Init(tr1::shared_ptr<sf::Texture> _image);
        
    protected:
        tr1::shared_ptr<sf::Texture> image; // The image belonging to the sprite 
        
    private:
        REGISTER_BINDING_DEF
    };

}

#endif	/* STATICSPRITECOMPONENT_HPP */

