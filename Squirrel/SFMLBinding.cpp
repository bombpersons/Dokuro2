/* 
 * File:   SFMLBinding.cpp
 * Author: bombpersons
 * 
 * Created on August 5, 2011, 7:16 PM
 */

#include "SFMLBinding.hpp"

namespace Dokuro2 {
    
    REGISTER_BINDING_DEC(SFMLBinding)
    
    SFMLBinding::SFMLBinding() {
    }

    SFMLBinding::~SFMLBinding() {
    }

    /* ----------------------------- Bind --------------------------------------- */
    void SFMLBinding::BindSFMLBinding(HSQUIRRELVM _vm) {
        /* Vector2f */
        Sqrat::Class<sf::Vector2f> vector2(_vm);
        vector2.Var("x", &sf::Vector2f::x);
        vector2.Var("y", &sf::Vector2f::y);
        Sqrat::RootTable(_vm).Bind("Vector2f", vector2);
    }

}