/* 
 * File:   AnimatedSpriteComponent.hpp
 * Author: bombpersons
 *
 * Created on August 21, 2011, 5:35 PM
 */

#ifndef ANIMATEDSPRITECOMPONENT_HPP
#define	ANIMATEDSPRITECOMPONENT_HPP

#include "StaticSpriteComponent.hpp"

#include <string>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

namespace Dokuro2 {

    class AnimatedSpriteComponent : public StaticSpriteComponent {
    public:
        AnimatedSpriteComponent(tr1::shared_ptr<sf::Texture> _image, sf::Vector2i _frameSize, sf::Vector2i _offset, sf::Vector2i _spacing);
        virtual ~AnimatedSpriteComponent();
        
        /* Update */
        virtual void Update(Entity* _entity, float _time);
        
        /* Draw */
        virtual void Draw(Entity* _entity, float _time);
        
        /* A struct that represents an animation */
        struct Animation {
            int start;
            int end;
            float fps;
            bool loop;
        };
        
        /* Pause the animation */
        virtual void Pause();
        
        /* Resume */
        virtual void Resume();
        
        /* Play an animation */
        virtual void Play(string _name);
        
        /* Get an animation */
        virtual Animation& GetAnimation(string _ident);
        
        /* Array operator */
        Animation& operator[] (string _ident);
        
        /* Get the current animation */
        virtual string GetPlayingAnimation();
        
    private:
        /* A hash map to store animations in */
        unordered_map<string, Animation> animMap;
        
        /* Information about the animation */
        string current;
        float currentFrame;
        sf::Vector2i frameSize;
        sf::Vector2i offset;
        sf::Vector2i spacing;
        
        /* Paused or Not */
        bool paused;
    };

}

#endif	/* ANIMATEDSPRITECOMPONENT_HPP */

