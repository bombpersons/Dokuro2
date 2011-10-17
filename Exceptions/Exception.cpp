/* 
 * File:   Exception.cpp
 * Author: bombpersons
 * 
 * Created on June 16, 2011, 4:54 PM
 */

#include "Exception.hpp"

namespace Dokuro2 {

    Exception::Exception(Level::Level _level, const string& _message) {
        message = _message;
        
        // Write to the log
        Tracer::Trace(_level) << _message << endl;
    }

    Exception::~Exception() {
    }
    
    /* ------------------------- Get Message -------------------------------- */
    const string& Exception::GetMessage() const {
        return message;
    }
}

