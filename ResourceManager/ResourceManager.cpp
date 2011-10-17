/* 
 * File:   ResourceManager.cpp
 * Author: bombpersons
 * 
 * Created on May 30, 2011, 7:14 PM
 */

#include "ResourceManager.hpp"

namespace Dokuro2 {
    ResourceManager::ResourceManager() {
    }

    ResourceManager::~ResourceManager() {
    }
    
    /* ------------------------- Squirrel Binding --------------------------- */
    void ResourceManager::Bind(HSQUIRRELVM _vm) {
    }
    
    /* --------------------------- Images ----------------------------------- */
    void ResourceManager::MapImage(string _name, string _filename) {
        images.MapResource(_name, _filename);
    }
    
    tr1::shared_ptr<sf::Texture> ResourceManager::GetImage(string _name) {
        return images.GetResource(_name);
    }
    
    /* --------------------------- Fonts ------------------------------------ */
    void ResourceManager::MapFont(string _name, string _filename) {
        fonts.MapResource(_name, _filename);
    }
    
    tr1::shared_ptr<sf::Font> ResourceManager::GetFont(string _name) {
        return fonts.GetResource(_name);
    }
    
    /* --------------------------- Update ----------------------------------- */
    void ResourceManager::Update() {
        images.Update();
        fonts.Update();
    }
}