/* 
 * File:   ComponentFactory.hpp
 * Author: bombpersons
 *
 * Created on August 7, 2011, 11:12 AM
 */

#ifndef COMPONENTFACTORY_HPP
#define	COMPONENTFACTORY_HPP

#include <string>
#include <fstream>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

#define REGISTER_COMP_DEF \
static ComponentFactoryRegisterer registerer;

#define REGISTER_COMP_DEC(NAME) \
ComponentFactoryRegisterer NAME::registerer(#NAME, &NAME::Load ## NAME ## FromFile);

namespace Dokuro2 {
    
    class Component;
    
    // A component factory function
    typedef Component*(*CompFactoryFunction)(ifstream&);
    
    class ComponentFactory {
    public:
        /* Add a component to the map */
        static void AddComponent(string _name, CompFactoryFunction _func);
        
        /* Get a component from a stream */
        static Component* GetComponentFromStream(ifstream& _file);
        
    private:
        static unordered_map<string, CompFactoryFunction>& GetComponentMap();
        
        // These shouldn't ever be used!
        ComponentFactory() {}
        virtual ~ComponentFactory() {}
    };
    
    // Used to register components easier
    class ComponentFactoryRegisterer {
    public:
        ComponentFactoryRegisterer(string _name, CompFactoryFunction _func);
        virtual ~ComponentFactoryRegisterer() {}
        
    protected:
        
    };
}

#include "../Component.hpp"
#include "../Exceptions/Exception.hpp"

#endif	/* COMPONENTFACTORY_HPP */

