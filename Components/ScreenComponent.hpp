/* 
 * File:   ScreenComponent.hpp
 * Author: bombpersons
 *
 * Created on June 17, 2011, 10:20 PM
 */

#ifndef SCREENCOMPONENT_HPP
#define	SCREENCOMPONENT_HPP

#include "Drawable/SpriteComponent.hpp"
#include "../Entity.hpp"

#include <SFML/Graphics.hpp>

namespace Dokuro2 {
    /* Makes an entity into a screen. Everything drawn will be drawn onto a 
       separate render image and then that image will be drawn. It's possible 
       to have screens within screens. */
    class ScreenComponent : public SpriteComponent {
    public:
        ScreenComponent();
        virtual ~ScreenComponent();
        
        /* Init */
        virtual void Init();
        
        /* On Add */
        virtual void OnAdd(Entity* _entity);
        
        /* On Been Added */
        virtual void OnBeenAdded(Entity* _entity);
        
        /* On Remove */
        virtual void OnRemove(Entity* _entity);
        
        /* On Been Removed */
        virtual void OnBeenRemoved(Entity* _entity);
        
        /* Draw */
        virtual void Draw(Entity* _entity, float _time);
        
        /* Change the size of the screen */
        virtual void ChangeSize(int _width, int _height);
        
        /* Fix the entity */
        virtual void FixEntity(Entity* _entity);
        
        /* Unfix the entity */
        virtual void UnFixEntity(Entity* _entity);
        
        /* Gets */
        virtual sf::Color& GetClearColor();
        
        /* Sets */
        virtual void SetClearColor(sf::Color _color);
        
    protected:
        sf::RenderTexture* image;
        sf::RenderTarget* target;
       
        sf::Color clearColor; // The clear color
    };

}

#endif	/* SCREENCOMPONENT_HPP */

