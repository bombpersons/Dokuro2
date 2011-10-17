/* 
 * File:   GameComponent.hpp
 * Author: bombpersons
 *
 * Created on June 17, 2011, 5:50 PM
 */

#ifndef GAMECOMPONENT_HPP
#define	GAMECOMPONENT_HPP

#include "../Component.hpp"

namespace Dokuro2 {
    
    /* This component is the main rendering part of the game. This will draw to
       to the screen. */
    class GameComponent : public Component {
    public:
        GameComponent(int _width, int _height, int _depth, bool _fullscreen=false);
        virtual ~GameComponent();
        
        /* Init */
        virtual void Init(int _width, int _height, int _depth, bool _fullscreen=false);
        
        /* Change the size of the screen */
        virtual void ChangeSize(int _width, int _height, int _depth, bool _fullscreen=false);
        
        /* Draw to the screen */
        virtual void Draw(Entity* _entity);
        
    private:

    };

}

#endif	/* GAMECOMPONENT_HPP */

