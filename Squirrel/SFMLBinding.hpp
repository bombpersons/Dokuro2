/* 
 * File:   SFMLBinding.hpp
 * Author: bombpersons
 *
 * Created on August 5, 2011, 7:16 PM
 */

#ifndef SFMLBINDING_HPP
#define	SFMLBINDING_HPP

#include <list>
using namespace std;

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../Sqrat/sqrat.h"

#include "Bindings.hpp"

namespace Dokuro2 {
    class SFMLBinding {
    public:
        /* Bind SFML types to squirrel */
        static void BindSFMLBinding(HSQUIRRELVM _vm);    
 
    private:
        SFMLBinding();
        virtual ~SFMLBinding();
        
        REGISTER_BINDING_DEF
    };

}

#endif	/* SFMLBINDING_HPP */