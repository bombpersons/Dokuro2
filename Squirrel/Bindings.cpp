/* 
 * File:   Bindings.cpp
 * Author: bombpersons
 * 
 * Created on August 9, 2011, 2:34 PM
 */

#include "Bindings.hpp"

namespace Dokuro2 {
    
    Bindings::Bindings() {
    }

    Bindings::~Bindings() {
    }
    
    /* ---------------------------- Bind ------------------------------------ */
    void Bindings::Bind(HSQUIRRELVM _vm) {
        for (list<BindFunction>::iterator it = GetList().begin(); it != GetList().end(); ++it) {
            (*it)(_vm);
        }
    }
    
    /* --------------------------- Add Binding ------------------------------ */
    void Bindings::AddBinding(BindFunction _func) {
        GetList().push_back(_func);
    }
    
    /* ---------------------------- Get List -------------------------------- */
    list<BindFunction>& Bindings::GetList() {
        static list<BindFunction> theList;
        return theList;
    }
    
    /*////////////////////////////// BindRegisterer //////////////////////////*/
    BindingRegisterer::BindingRegisterer(BindFunction _func) {
        Bindings::AddBinding(_func);
    }
}