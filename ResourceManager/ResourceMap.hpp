/* 
 * File:   ResourceMap.hpp
 * Author: bombpersons
 *
 * Created on May 31, 2011, 2:44 PM
 */

#ifndef RESOURCEMAP_HPP
#define	RESOURCEMAP_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <string>
#include <tr1/unordered_map>
#include <tr1/memory>
using namespace std;
using namespace std::tr1;

#include "../Exceptions/Exception.hpp"
#include "../Tracer/Tracer.hpp"

namespace Dokuro2 {
    
    class ResourceManager;
    
    template <class T>
    class ResourceMap {
    public:
        ResourceMap() {}
        virtual ~ResourceMap() {}
        
        // Set the resource manager
        void SetResourceManager(ResourceManager* _resource) {
            resourceManager = _resource;
        }
        
        // Map resource
        void MapResource(string _name, string _filename) {
            // Debug
            Tracer::Trace(Level::Fine) << "Mapping " << _name << " to " << _filename << " ... " << endl;
            
            // Check if we already have something loaded.
            // If we do, then we can erase it.
            auto it = resource.find(_name);
            if (it != resource.end()) {
                resource.erase(it);
            }
            
            // Insert it to the filename map
            filename[_name] = _filename;
        }
        
        // Get resource
        std::tr1::shared_ptr<T> GetResource(string _name) {
            // First check if this resource is already loaded
            auto it = resource.find(_name);
            if (it != resource.end()) {
                return (*it).second;
            }

            // Try and find the filename in the filename hash table.
            auto it2 = filename.find(_name);
            if (it2 == filename.end()) {
                throw Exception(Level::Fatal, _name + " Could not be found in the resource map.");
            }

            // Load the resource and put it into the hash table
            resource[_name] = LoadResource((*it2).second);
            Tracer::Trace(Level::Successful) << (*it2).second << " loaded as " << _name << endl;
            
            return resource[_name];
        }
        virtual std::tr1::shared_ptr<T> LoadResource(string _filename) = 0;
        
        // Update the resource map (deallocate memory if neccessary)
        void Update() {
            // Check all of the shared pointers in resources.
            for (auto it = resource.begin(); it != resource.end(); ++it) {
                if ((*it).second.unique()) {
                    Tracer::Trace(Level::Fine) << (*it).first << " unloading." << endl;
                    resource.erase(it);
                    Tracer::Trace(Level::Fine) << "Unloaded." << endl; 
                }
            }
        }  
        
    protected:
        // Map of the resource to a string
        std::tr1::unordered_map<string, string> filename; // Maps the name to a filename.
        std::tr1::unordered_map<string, tr1::shared_ptr<T> > resource; // Maps the name to a resource.
        ResourceManager* resourceManager; // The resource manager.
    };

}

#endif	/* RESOURCEMAP_HPP */