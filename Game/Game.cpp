/* 
 * File:   Game.cpp
 * Author: bombpersons
 * 
 * Created on June 17, 2011, 5:38 PM
 */

#include "Game.hpp"

namespace Dokuro2 {

    Game::Game(int _width, int _height, int _depth, bool _fullscreen) {
        Init(_width, _height, _depth, _fullscreen);
    }

    Game::~Game() {
        // Delete things we allocated
        if (target)
            delete target;
        if (resource)
            delete resource;
        if (input)
            delete input;
    }
    
    /* ---------------------------- Init ------------------------------------ */
    void Game::Init(int _width, int _height, int _depth, bool _fullscreen) {
        // Set default values.
        running = false; // Not running by default
        SetClearColor(sf::Color(255, 199, 0));
        target = NULL;
        resource = NULL;
        input = NULL;
        
        // Create a resource manager
        Tracer::Trace(Level::Fine) << "Allocating the resource manager..." << endl;
        SetResourceManager(new ResourceManager());
        Tracer::Trace(Level::Successful) << "Resource manager allocated." << endl;
        
        // Create the input manager
        Tracer::Trace(Level::Fine) << "Allocating the input manager..." << endl;
        SetInputManager(new InputManager());
        Tracer::Trace(Level::Successful) << "Input manager allocated." << endl;
        
        // Change the size of the window
        ChangeSize(_width, _height, _depth, _fullscreen);
        
        // Map any resources
        MapResources();
    }
    
    /* --------------------------- Map Resources ---------------------------- */
    void Game::MapResources() {
    }
    
    /* -------------------------- Change Size ------------------------------- */
    void Game::ChangeSize(int _width, int _height, int _depth, bool _fullscreen) {
        // If the render window is null, create one.
        if (!target) {
            Tracer::Trace(Level::Fine) << "Creating the RenderWindow..." << endl;
            sf::RenderWindow* window = new sf::RenderWindow();
            target = window;
            SetRootWindow(window);
            Tracer::Trace(Level::Successful) << "RenderWindow created." << endl;
        }
        
        // Change the window size
        unsigned int flags = sf::Style::Titlebar | sf::Style::Close;
        if (_fullscreen) {
            flags |= sf::Style::Fullscreen;
            Tracer::Trace(Level::Fine) << "Changed to fullscreen" << endl;
        } else {
            Tracer::Trace(Level::Fine) << "Changed to windowed" << endl;
        }
        Tracer::Trace(Level::Fine) << "Changing screen resolution to " << _width << "x" << _height << " @ " << _depth << " " << (_fullscreen ? "Fullscreen" : "Windowed") << endl; 
        ((sf::RenderWindow*)target)->Create(sf::VideoMode(_width, _height, _depth), "Dokuro2 Game", flags);
        Tracer::Trace(Level::Successful) << "Screen resolution changed to " << _width << "x" << _height << " @ " << _depth << " " << (_fullscreen ? "Fullscreen" : "Windowed") << endl;
    }
    
    /* ------------------------- Update ------------------------------------- */
    void Game::Update(float _time) {
        Entity::Update(_time);
        sf::Event event;
        while (((sf::RenderWindow*)target)->PollEvent(event)) {
            switch (event.Type) {
                case sf::Event::Closed:
                    Close();
                    break;
                    
                default:
                    HandleEvent(event);
                    break;
            }
        }
    }
    
    /* ------------------------------ Run ----------------------------------- */
    void Game::Run() {
        Tracer::Trace(Level::Fine) << "Game is running..." << endl;
        
        running = true;
        while (running) {
            float time = ((sf::RenderWindow*)target)->GetFrameTime() / (float)1000;
            
            // Clear the target
            target->Clear(clearColor);
            
            // Update the resource manager
            if (GetResourceManager())
                GetResourceManager()->Update();
            
            // Update the input manager
            if (GetInputManager())
                GetInputManager()->Update();
            
            // Update and draw
            PreUpdate(time);
            Update(time);
            PostUpdate(time);
            
            // Flip the target
            ((sf::RenderWindow*)target)->Display();
        }
    }
    
    /* -------------------------- Close ------------------------------------- */
    void Game::Close() {
        running = false;
        Tracer::Trace(Level::Successful) << "Game is closing..." << endl;
    }
    
    /* ---------------------------- Set clear color ------------------------- */
    void Game::SetClearColor(sf::Color _color) {
        clearColor = _color;
    }
    
    /* ---------------------- Get clear color ------------------------------- */
    sf::Color& Game::GetClearColor() {
        return clearColor;
    }
}
