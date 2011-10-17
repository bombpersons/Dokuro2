/* 
 * File:   InputManager.cpp
 * Author: bombpersons
 * 
 * Created on June 19, 2011, 1:58 PM
 */

#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "InputManager.hpp"

namespace Dokuro2 {

    /* //////////////////////////// Input Map /////////////////////////////// */
    InputMap::InputMap() {
    }
    
    InputMap::~InputMap() {
    }
    
    /* ------------------------ Return default values ----------------------- */
    float InputMap::GetValue() {
        return 0.0f;
    }
    
    sf::Vector2f InputMap::GetValues() {
        return sf::Vector2f(0.0f, 0.0f);
    }
    
    bool InputMap::GetClicked() {
        return false;
    }
    
    bool InputMap::GetReleased() {
        return false;
    }
    
    void InputMap::Update() {
    }
    
    /* /////////////////////////////// KeyMap /////////////////////////////// */
    KeyMap::KeyMap(sf::Keyboard::Key _code) {
        key = _code;
        oldPress = false;
    }
    
    KeyMap::~KeyMap() {
    }
    
    /* ------------------------------ Get input ----------------------------- */
    float KeyMap::GetValue() {
        float result = 0.0f;
        if (sf::Keyboard::IsKeyPressed(key))
            result += 1.0f;
        
        return result;
    }
    
    bool KeyMap::GetClicked() {
        return clicked;
    }
    
    bool KeyMap::GetReleased() {
        return released;
    }
    
    void KeyMap::Update() {
        clicked = (!oldPress && sf::Keyboard::IsKeyPressed(key));
        released = (oldPress && !sf::Keyboard::IsKeyPressed(key));
        
        oldPress = sf::Keyboard::IsKeyPressed(key);
    }
    
    /* ////////////////////////////// Axis ////////////////////////////////// */
    AxisMap::AxisMap(InputMap* _up, InputMap* _down) {
        up = _up;
        down = _down;
    }
    
    AxisMap::~AxisMap() {
        if (up)
            delete up;
        if (down)
            delete down;
    }
    
    float AxisMap::GetValue() {
        float result = 0;
        if (up)
            result += up->GetValue();
        if (down)
            result -= down->GetValue();
        
        return result;
    }
    
    void AxisMap::Update() {
        if (up)
            up->Update();
        if (down)
            down->Update();
    }
    
    /* ////////////////////// 2D Axis Map /////////////////////////////////// */
    Axis2DMap::Axis2DMap(AxisMap* _x, AxisMap* _y) {
        if (!_x || !_y) {
            Tracer::Trace(Level::NotGood) << "Axis2DMap Created with one or more null axes. " << endl;
        }
        
        x = _x;
        y = _y;
    }
    
    Axis2DMap::~Axis2DMap() {
        if (x)
            delete x;
        if (y)
            delete y;
    }
    
    
    sf::Vector2f Axis2DMap::GetValues() {
        sf::Vector2f result;
        if (x)
            result.x = x->GetValue();
        if (y)
            result.y = y->GetValue();
        return result;
    }
    
    void Axis2DMap::Update() {
        if (x)
            x->Update();
        if (y)
            y->Update();
    }
    
    /* /////////////////////////////// Input Manager //////////////////////// */
    InputManager::InputManager() {
    }

    InputManager::~InputManager() {
        // Delete all of the input maps
        for (unordered_multimap<string, InputMap*>::iterator it = inputs.begin(); it != inputs.end(); ++it) {
            delete (*it).second;
        }
    }
    
    /* ------------------------------ Map an input -------------------------- */
    void InputManager::MapInput(string _name, InputMap* _map) {
        // Check if the map is null
        if (!_map) {
            Tracer::Trace(Level::Bad) << "Cannot map a null InputMap!" << endl;
            return;
        }
        
        // Add this to the map
        pair<string, InputMap*> p(_name, _map);
        inputs.insert(p);
        
        Tracer::Trace(Level::Successful) << "\"" << _name << "\" Successfully mapped." << endl;
    }
    
    /* ---------------------------- Get value for an input ------------------ */
    float InputManager::GetValue(string _name) {
        // Get start and end iterators for all the inputs that match this key.
        auto range = inputs.equal_range(_name);
        
        if (range.first == inputs.end()) {
            Tracer::Trace(Level::NotGood) << "\"" << _name << "\" has not been mapped!" << endl;
            return 0.0f;
        }
        
        // Iterate through the range and average them
        int count = 0;
        float sum = 0.0f;
        for (unordered_multimap<string, InputMap*>::iterator it = range.first; it != range.second; ++it) {
            ++count;
            sum += (*it).second->GetValue();
        }
        float result = sum / count;
        
        return result;
    }
    
    /* ---------------- Get a 2d axis --------------------------------------- */
    sf::Vector2f InputManager::GetValues(string _name) {
        // Get start and end iterators for all the inputs that match this key.
        auto range = inputs.equal_range(_name);
        
        if (range.first == inputs.end()) {
            Tracer::Trace(Level::NotGood) << "\"" << _name << "\" has not been mapped!" << endl;
            return sf::Vector2f();
        }
        
        // Iterate through the range and average them
        int count = 0;
        sf::Vector2f sum;
        for (unordered_multimap<string, InputMap*>::iterator it = range.first; it != range.second; ++it) {
            ++count;
            sum += (*it).second->GetValues();
        }
        sf::Vector2f result = sum / (float)count;
        
        return result;
    }    
    
    /* --------------------------- Get whether there has been a click ------- */
    bool InputManager::GetClicked(string _name) {
        // Get start and end iterators for all the inputs that match this key.
        auto range = inputs.equal_range(_name);
        if (range.first == inputs.end()) {
            Tracer::Trace(Level::NotGood) << "\"" << _name << "\" has not been mapped!" << endl;
            return false;
        }
        
        // Iterate through them until we get one that is true
        for (unordered_multimap<string, InputMap*>::iterator it = range.first; it != range.second; ++it) {
            if ((*it).second->GetClicked())
                return true;
        }
        return false;
    }
    
    /* ------------------- Get whether or not a key has been released ------- */
    bool InputManager::GetReleased(string _name) {
        // Get start and end iterators for all the inputs that match this key.
        auto range = inputs.equal_range(_name);
        if (range.first == inputs.end()) {
            Tracer::Trace(Level::NotGood) << "\"" << _name << "\" has not been mapped!" << endl;
            return false;
        }
        
        // Iterate through them until we get one that is true
        for (unordered_multimap<string, InputMap*>::iterator it = range.first; it != range.second; ++it) {
            if ((*it).second->GetReleased())
                return true;
        }
        return false;
    }
    
    /* -------------------------- Update ------------------------------------ */
    void InputManager::Update() {
        for (unordered_multimap<string, InputMap*>::iterator it = inputs.begin(); it != inputs.end(); ++it) {
            (*it).second->Update();
        }
    }
}
