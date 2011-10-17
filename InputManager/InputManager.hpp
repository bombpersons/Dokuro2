/* 
 * File:   InputManager.hpp
 * Author: bombpersons
 *
 * Created on June 19, 2011, 1:58 PM
 */

#ifndef INPUTMANAGER_HPP
#define	INPUTMANAGER_HPP

#include <SFML/System.hpp>

#include <tr1/unordered_map>
using namespace std::tr1;

#include <string>
using namespace std;

#include "../Tracer/Tracer.hpp"

namespace Dokuro2 {
    
    /* Abstract class for an input */
    class InputMap {
    public:
        InputMap();
        virtual ~InputMap();
        
        /* Get the value of this input */
        virtual float GetValue();
        virtual sf::Vector2f GetValues();
        virtual bool GetClicked();
        virtual bool GetReleased();
        
        virtual void Update();
        
    protected:
    };
    
    /* Test for a key press */
    class KeyMap : public InputMap {
    public:
        KeyMap(sf::Keyboard::Key _code);
        virtual ~KeyMap();
        
        virtual float GetValue();
        virtual bool GetClicked();
        virtual bool GetReleased();
        
        virtual void Update();
        
    protected:
        sf::Keyboard::Key key;
        bool oldPress;
        bool clicked;
        bool released;
    };
    
    /* An axis */
    class AxisMap : public InputMap {
    public:
        AxisMap(InputMap* _up, InputMap* _down=NULL); // You can safely use "new" here!
        virtual ~AxisMap();
        
        virtual float GetValue();
        
        virtual void Update();
        
    protected:
        InputMap* up;
        InputMap* down;
    };
    
    /* A 2d axis */
    class Axis2DMap : public InputMap {
    public:
        Axis2DMap(AxisMap* _x, AxisMap* _y);
        virtual ~Axis2DMap();
        
        virtual sf::Vector2f GetValues();
       
        virtual void Update();
        
    protected:
        AxisMap* x;
        AxisMap* y;
        
    };
    
    /* You can use the input manager to query input. It's possible to map names to 
       certain keys to easily change controls in your game. Also, you can easily manage
       players by giving them individual controls. */
    class InputManager : public sf::NonCopyable {
    public:
        InputManager();
        virtual ~InputManager();
        
        /* Map an input */
        void MapInput(string _name, InputMap* _map);
        
        /* Getting input */
        float GetValue(string _name);
        sf::Vector2f GetValues(string _name);
        bool GetClicked(string _name);
        bool GetReleased(string _name);
        
        /* Update the input manager */
        void Update();
        
    protected:
        unordered_multimap<string, InputMap*> inputs;
    };

}

#endif	/* INPUTMANAGER_HPP */

