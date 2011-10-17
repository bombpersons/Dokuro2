/* 
 * File:   Bindings.hpp
 * Author: bombpersons
 *
 * Created on August 9, 2011, 2:34 PM
 */

#ifndef BINDINGS_HPP
#define	BINDINGS_HPP

#include <list>
using namespace std;

#include "../Sqrat/sqrat.h"
#include <iostream>
using namespace std;

#define REGISTER_BINDING_DEF \
static BindingRegisterer bindingRegisterer;

#define REGISTER_BINDING_DEC(NAME) \
BindingRegisterer NAME::bindingRegisterer(&NAME::Bind##NAME);

namespace Dokuro2 {
    
    typedef void(*BindFunction)(HSQUIRRELVM);
    
    class Bindings {
    public:
        /* Bind everything to a vm */
        static void Bind(HSQUIRRELVM _vm);
        
        /* Add to the binding list */
        static void AddBinding(BindFunction _func);
        
        /* Get the list */
        static list<BindFunction>& GetList();
        
    private:
        Bindings();
        virtual ~Bindings();
    };
    
    class BindingRegisterer {
    public:
        BindingRegisterer(BindFunction _func);
        virtual ~BindingRegisterer() {}
        
    private:
    };
}

#endif	/* BINDINGS_HPP */