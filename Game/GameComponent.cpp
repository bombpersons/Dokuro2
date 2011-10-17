/* 
 * File:   GameComponent.cpp
 * Author: bombpersons
 * 
 * Created on June 17, 2011, 5:50 PM
 */

#include "GameComponent.hpp"

namespace Dokuro2 {

    GameComponent::GameComponent(int _width, int _height, int _depth, bool _fullscreen) {
        AddName("GameComponent");
        Init(_width, _height, _depth, _fullscreen);
    }

    GameComponent::~GameComponent() {
    }
    
    /* -------------------------- Change Size ------------------------------- */
    void GameComponent::ChangeSize(int _width, int _height, int _depth, bool _fullscreen) {
        
    }
}