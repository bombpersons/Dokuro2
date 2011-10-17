/* 
 * File:   ScreenComponent.cpp
 * Author: bombpersons
 * 
 * Created on June 17, 2011, 10:20 PM
 */

#include "ScreenComponent.hpp"

namespace Dokuro2 {

    ScreenComponent::ScreenComponent() {
        AddName("ScreenComponent");
        Init();
    }

    ScreenComponent::~ScreenComponent() {
        // Delete the renderimage we created
        delete image;
    }
    
    /* ------------------------- Init --------------------------------------- */
    void ScreenComponent::Init() {
        SetClearColor(sf::Color(255, 0, 0, 255));
    }
    
    /* ---------------------------- OnAdd ----------------------------------- */
    void ScreenComponent::OnAdd(Entity* _entity) {
        Component::OnAdd(_entity);
        FixEntity(_entity);
    }
    
    void ScreenComponent::OnBeenAdded(Entity* _entity) {
        Component::OnBeenAdded(_entity);
        FixEntity(_entity);
    }
    
    /* --------------------------- OnRemove --------------------------------- */
    void ScreenComponent::OnRemove(Entity* _entity) {
        Component::OnRemove(_entity);
        UnFixEntity(_entity);
    }
    
    /* ---------------------------- OnBeenRemoved --------------------------- */
    void ScreenComponent::OnBeenRemoved(Entity* _entity) {
        Component::OnBeenRemoved(_entity);
        UnFixEntity(_entity);
    }
    
    /* -------------------------- Draw -------------------------------- */
    void ScreenComponent::Draw(Entity* _entity, float _time){
        // Display the image
        image->Display();
        
        // Set the position of the sprite
        sprite.SetPosition(_entity->GetPosition());
        sprite.SetOrigin(_entity->GetCenter());
        sprite.SetRotation(_entity->GetRotation());
        sprite.SetScale(_entity->GetScale());
        
        // Draw the image to the original render target
        sprite.SetTexture(image->GetTexture(), true);
        target->Draw(sprite);
        
        // Clear the image
        image->Clear(clearColor);
    }
    
    /* -------------------------- ChangeSize -------------------------------- */
    void ScreenComponent::ChangeSize(int _width, int _height) {
        image->Create(_width, _height, false);
    }
    
    /* ------------------------- Fix Entity --------------------------------- */
    void ScreenComponent::FixEntity(Entity* _entity) {
        // Check if the render target is there
        if (!_entity->GetRenderTarget())
            return;
        
        // Take a copy of the current render target
        target = _entity->GetRenderTarget();
        
        // Create a render image and set that as the current render target
        image = new sf::RenderTexture();
        ChangeSize(target->GetWidth(), target->GetHeight());
        _entity->SetRenderTarget(image);
    }
    
    /* -------------------------- UnFix Entity ------------------------------ */
    void ScreenComponent::UnFixEntity(Entity* _entity) {
        // Set the normal render target back
        _entity->SetRenderTarget(target);
    }
    
    /* -------------------------- Get clear color --------------------------- */
    sf::Color& ScreenComponent::GetClearColor() {
        return clearColor;
    }
    
    /* --------------------------- Set clear color -------------------------- */
    void ScreenComponent::SetClearColor(sf::Color _color) {
        clearColor = _color;
    }
}
