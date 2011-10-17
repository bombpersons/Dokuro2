/* 
 * File:   AnimatedSpriteComponent.cpp
 * Author: bombpersons
 * 
 * Created on August 21, 2011, 5:35 PM
 */

#include "AnimatedSpriteComponent.hpp"

namespace Dokuro2 {

    AnimatedSpriteComponent::AnimatedSpriteComponent(tr1::shared_ptr<sf::Texture> _image, sf::Vector2i _frameSize, sf::Vector2i _offset, sf::Vector2i _spacing) 
        : StaticSpriteComponent(_image) {
        
        frameSize = _frameSize;
        offset = _offset;
        spacing = _spacing;
        
        paused = false;
        current = "";
        currentFrame = 0;
    }

    AnimatedSpriteComponent::~AnimatedSpriteComponent() {
    }
    
    /* ---------------------------- Update ---------------------------------- */
    void AnimatedSpriteComponent::Update(Entity* _entity, float _time) {
        // Check if we are playing, or if the current animation even exists.
        if (paused || animMap.find(current) == animMap.end()) {
            return;
        }
        
        // If the start and end frame are the same, then just set the frame to that
        if (animMap[current].start == animMap[current].end) {
            currentFrame = animMap[current].start;
            return;
        }
        
        /* Increment the frame */
        currentFrame += animMap[current].fps * _time;
        
        // If the currentFrame is under the start frame
        if (currentFrame < animMap[current].start) {
            currentFrame = animMap[current].start;
        }
        
        // If the currentFrame is over the end frame
        if (currentFrame + 1 >= animMap[current].end) {
            if (!animMap[current].loop) {
                currentFrame = animMap[current].end;
                Pause();
            }
            
            while(currentFrame + 1 >= animMap[current].end) {
                currentFrame -= animMap[current].end - animMap[current].start;
            }
        }
    }
    
    /* ----------------------------- Draw ----------------------------------- */
    void AnimatedSpriteComponent::Draw(Entity* _entity, float _time) {
        /* Calculate the clipping rectangle we need to use for this frame */
        int frame = (int)currentFrame;
        sf::Vector2i start = offset;
        
        // How many frames would go across the sheet?
        sf::Vector2i size = sf::Vector2i(sprite.GetTexture()->GetWidth(), sprite.GetTexture()->GetHeight());
        size.x /= (spacing + frameSize).x;
        size.y /= (spacing + frameSize).y;
        
        // We should be able to figure out with row the current frame is on.
        sf::Vector2i coords = sf::Vector2i(frame % size.x, frame / size.x);
        
        // Finally we can pin down the start of the rectangle of this frame
        start.x += (spacing + frameSize).x * coords.x;
        start.y += (spacing + frameSize).y * coords.y;
        sf::IntRect clip = sf::IntRect(start, frameSize);
        
        sprite.SetSubRect(clip);
        
        // Draw the sprite 
        StaticSpriteComponent::Draw(_entity, _time);
    }
    
    /* -------------------------- Pause ------------------------------------- */
    void AnimatedSpriteComponent::Pause() {
        paused = true;
    }
    
    /* ----------------------------- Resume --------------------------------- */
    void AnimatedSpriteComponent::Resume() {
        paused = false;
    }
    
    /* ---------------------------- Play ------------------------------------ */
    void AnimatedSpriteComponent::Play(string _ident) {
        current = _ident;
        Resume();
    }
    
    /* -------------------------- Get an animation -------------------------- */
    AnimatedSpriteComponent::Animation& AnimatedSpriteComponent::GetAnimation(string _ident) {
        if (animMap.find(_ident) == animMap.end())
                animMap[_ident] = Animation();
        return animMap[_ident];
    }    
    
    /* --------------------------- Array operators -------------------------- */
    AnimatedSpriteComponent::Animation& AnimatedSpriteComponent::operator[] (string _ident) {
        return GetAnimation(_ident);
    }
    
    /* ---------------------------- Get Playing Animation ------------------- */
    string AnimatedSpriteComponent::GetPlayingAnimation() {
        return current;
    }
}