/* 
 * File:   SpriteComponent.hpp
 * Author: bombpersons
 *
 * Created on June 20, 2011, 5:11 PM
 */

#ifndef SPRITECOMPONENT_HPP
#define	SPRITECOMPONENT_HPP

#include "DrawableComponent.hpp"
#include "../../Entity.hpp"
#include <SFML/Graphics.hpp>

namespace Dokuro2 {

    class SpriteComponent : public DrawableComponent {
    public:
        SpriteComponent();
        virtual ~SpriteComponent();
        
        /* Draw */
        virtual void Draw(Entity* _entity, float _time);
        
        /* Get the sprite */
        virtual sf::Sprite& GetSprite();
        
    protected:
        sf::Sprite sprite;
    };

}

#endif	/* SPRITECOMPONENT_HPP */

