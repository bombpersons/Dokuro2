/* 
 * File:   SpriteComponent.cpp
 * Author: bombpersons
 * 
 * Created on June 20, 2011, 5:11 PM
 */

#include "SpriteComponent.hpp"

namespace Dokuro2 {

    SpriteComponent::SpriteComponent() {
        AddName("SpriteComponent");
        Init();
    }

    SpriteComponent::~SpriteComponent() {
    }

    /* --------------------------- Draw ------------------------------------- */
    void SpriteComponent::Draw(Entity* _entity, float _time) {
        // Update the sprite with the position of the entity
        sprite.SetPosition(_entity->GetPosition());
        sprite.SetOrigin(_entity->GetCenter());
        sprite.SetRotation(_entity->GetRotation());
        sprite.SetScale(_entity->GetScale());
        
        if (_entity->GetRenderTarget())
                _entity->GetRenderTarget()->Draw(sprite);
    }
    
    /* ---------------------------- Get the sprite -------------------------- */
    sf::Sprite& SpriteComponent::GetSprite() {
        return sprite;
    }
}
