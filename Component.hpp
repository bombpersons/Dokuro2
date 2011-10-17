/* 
 * File:   Component.hpp
 * Author: bombpersons
 *
 * Created on June 16, 2011, 3:42 PM
 */

#ifndef COMPONENT_HPP
#define	COMPONENT_HPP

#include "Sqrat/sqrat.h"

#include <list>
#include <string>
#include <fstream>
using namespace std;

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Factory/ComponentFactory.hpp"

#include "Squirrel/Bindings.hpp"

namespace Dokuro2 {
    
    class Entity;
    
    class Component : public sf::NonCopyable {
    public:
        Component();
        virtual ~Component();
        
        /* Bind to squirrel */
        template <class T>
        static Sqrat::ImprovedClass<T, Sqrat::ImprovedNoCopyAllocator<T> > BaseBind(HSQUIRRELVM _vm) {
            Sqrat::ImprovedClass<T, Sqrat::ImprovedNoCopyAllocator<T> > comp(_vm);

            comp.Func("Init", &T::Init);
            comp.Func("PreUpdate", &T::PreUpdate);
            comp.Func("Update", &T::Update);
            comp.Func("PostUpdate", &T::PostUpdate);
            comp.Func("HandleEvent", &T::HandleEvent);
            comp.Func("OnAdd", &T::OnAdd);
            comp.Func("OnBeenAdded", &T::OnBeenAdded);
            comp.Func("OnRemove", &T::OnRemove);
            comp.Func("OnBeenRemoved", &T::OnBeenRemoved);
            comp.Func("OnSwap", &T::OnSwap);
            comp.Func("OnReady", &T::OnReady);
            comp.Func("IsReady", &T::IsReady);
            comp.Func("AddName", &T::AddName);
            comp.Func("AddUpdateDependency", &T::AddUpdateDependency);
            
            return comp;
        }
        static void BindComponent(HSQUIRRELVM _vm);
        
        /* Create an instance of this component from a file */
        static Component* LoadComponentFromFile(ifstream& _in);
        static string GetComponentNameFromFile(ifstream& _in);
        virtual void SaveToFile(ofstream& _out);
        virtual unsigned int SizeOnDisk();
        
        /* Initialization Functions */
        virtual void Init();
        
        /* Update functions */
        virtual void PreUpdate(Entity* _entity, float _time);
        virtual void Update(Entity* _entity, float _time);
        virtual void PostUpdate(Entity* _entity, float _time);
        
        /* Handle any events if we want to. */
        virtual void HandleEvent(const sf::Event& _event);
        
        /* On* functions */
        virtual void OnAdd(Entity* _entity);
        virtual void OnBeenAdded(Entity* _entity);
        virtual void OnRemove(Entity* _entity);
        virtual void OnBeenRemoved(Entity* _entity);
        virtual void OnSwap(Entity* _entity);
        virtual void OnReady(Entity* _entity); 
        
        /* Is functions */
        virtual bool IsReady();
        
        /* Get + Set */
        virtual list<string>& GetNames();
        virtual list<string>& GetUpdateDependencies();
        virtual Entity* GetParentEntity();
    
        /* Add a name. (Always add the name of the class when inheriting)*/
        void AddName(const string& _name);
        
        /* Add an update dependency. */
        void AddUpdateDependency(const string& _name);
        
        Entity* parent; // A reference to the entity that owns this component.
        
    private:
        list<string> names; // This list is used to track the inheritance of this
                            // component.
        list<string> updateDependencies; // A list of other components that need
                                         // to be updated before this one.
        
        REGISTER_COMP_DEF
        REGISTER_BINDING_DEF
    };

}

#endif	/* COMPONENT_HPP */

