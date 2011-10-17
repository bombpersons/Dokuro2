/* 
 * File:   Exception.hpp
 * Author: bombpersons
 *
 * Created on June 16, 2011, 4:54 PM
 */

#ifndef EXCEPTION_HPP
#define	EXCEPTION_HPP

#include <string>
using namespace std;

#include "../Tracer/Tracer.hpp"

namespace Dokuro2 {

    class Exception {
    public:
        Exception(Level::Level _level, const string& _message);
        virtual ~Exception();
        
        /* Get the Message */
        virtual const string& GetMessage() const;
        
    protected:
        string message; // The message
    };

}

#endif	/* EXCEPTION_HPP */

