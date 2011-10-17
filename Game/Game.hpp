/* 
 * File:   Game.hpp
 * Author: bombpersons
 *
 * Created on June 17, 2011, 5:38 PM
 */

#ifndef GAME_HPP
#define	GAME_HPP

#include "../Entity.hpp"

namespace Dokuro2 {

    class Game : public Entity {
    public:
        Game(int _width=500, int _height=500, int _depth=32, bool _fullscreen=false);
        virtual ~Game();
        
        /* Initialize */
        virtual void Init(int _width=500, int _height=500, int _depth=32, bool _fullscreen=false);
        
        /* Loading Resources */
        virtual void MapResources();
        
        /* Change the size of the screen */
        virtual void ChangeSize(int _width, int _height, int _depth=32, bool _fullscreen=false);
        
        /* Update */
        virtual void Update(float _time);
        
        /* Run the game */
        virtual void Run();
        
        /* Close the game */
        virtual void Close();
        
        /* Gets */
        virtual sf::Color& GetClearColor();
        
        /* Sets */
        virtual void SetClearColor(sf::Color _color);
        
    private:
        bool running; // Whether or not the game is running
        
        sf::Color clearColor; // The color to clear the screen to
    };

}

#endif	/* GAME_HPP */

