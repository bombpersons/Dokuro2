/* 
 * File:   StaticSpriteComponent.cpp
 * Author: bombpersons
 * 
 * Created on June 18, 2011, 7:11 PM
 */

#include "StaticSpriteComponent.hpp"

namespace Dokuro2 {
    
    REGISTER_BINDING_DEC(StaticSpriteComponent)
    
    StaticSpriteComponent::StaticSpriteComponent(tr1::shared_ptr<sf::Texture> _image) {
        AddName("StaticSpriteComponent");
        Init(_image);
    }
    
    StaticSpriteComponent::~StaticSpriteComponent() {
    }
    
    /* ------------------------------ Bind ---------------------------------- */
    void StaticSpriteComponent::BindStaticSpriteComponent(HSQUIRRELVM _vm) {
    }
    
    /* ----------------------------- Init ----------------------------------- */
    void StaticSpriteComponent::Init(tr1::shared_ptr<sf::Texture> _image) {
        image = _image;
        sprite.SetTexture(*_image.get());
    }
}

