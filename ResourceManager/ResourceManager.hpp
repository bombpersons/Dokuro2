/* 
 * File:   ResourceManager.hpp
 * Author: bombpersons
 *
 * Created on May 30, 2011, 7:14 PM
 */

#ifndef RESOURCEMANAGER_HPP
#define	RESOURCEMANAGER_HPP

#include "../Sqrat/sqrat.h"

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "ResourceMap.hpp"

#include "../Exceptions/Exception.hpp"

namespace Dokuro2 {
    /* Typedefs */
    typedef tr1::shared_ptr<sf::Texture> ImageResource;
    
    /* Map image filenames to names */
    class ImageMap : public ResourceMap<sf::Texture> {
    public:
        ImageMap() {}
        tr1::shared_ptr<sf::Texture> LoadResource(string _filename) {
            sf::Texture* image = new sf::Texture();
            if (!image->LoadFromFile(_filename)) {
                throw Exception(Level::Fatal, "Image \"" + _filename + "\" could not be found.");
            }
            
            return tr1::shared_ptr<sf::Texture>(image);
        }
    };
    
    /* Map font filenames to names */
    class FontMap : public ResourceMap<sf::Font> {
    public:
        FontMap() {}
        tr1::shared_ptr<sf::Font> LoadResource(string _filename) {
            sf::Font* font = new sf::Font();
            if (!font->LoadFromFile(_filename)) {
                throw Exception(Level::Fatal, "Font \"" + _filename + "\" could not be found.");
            }
            
            return tr1::shared_ptr<sf::Font>(font);
        }
    };
    
    /* Manages Resources in the Dokuro engine */
    class ResourceManager : public sf::NonCopyable {
    public:
        ResourceManager();
        virtual ~ResourceManager();

        /* Bind to squirrel */
        static void Bind(HSQUIRRELVM _vm);  
        
        /* Images */
        void MapImage(string _name, string _filename);
        tr1::shared_ptr<sf::Texture> GetImage(string _name);
        
        /* Fonts */
        void MapFont(string _name, string _filename);
        tr1::shared_ptr<sf::Font> GetFont(string _name);
        
        // Update the resource manager
        void Update();
        
    private:
        ImageMap images;
        FontMap fonts;
    };

}

#endif	/* RESOURCEMANAGER_HPP */

