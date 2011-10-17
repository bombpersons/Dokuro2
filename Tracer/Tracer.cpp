/* 
 * File:   Tracer.cpp
 * Author: bombpersons
 * 
 * Created on June 19, 2011, 2:30 PM
 */

#include "Tracer.hpp"
#include <iostream>
using namespace std;

namespace Dokuro2 {
    
    REGISTER_BINDING_DEC(Tracer);
    
    /* Static instance of tracer */
    Tracer Tracer::tracer;
    
    /* Static instance of the black hole stream */
    ostream Tracer::blackhole(0);
    
    Tracer::Tracer() {
        // Set the output stream to cout by default
        out = &cout;
        
        // Set the error array
        errors[Level::Successful] = "Success";
        errors[Level::Fine] = "Fine";
        errors[Level::Meh] = "Meh";
        errors[Level::NotGood] = "Not Good";
        errors[Level::Bad] = "Bad!";
        errors[Level::Fatal] = "Fatal!!";
        errors[Level::Apocolyptic] = "WE'RE ALL GOING TO DIE!!!!";
        
        // Set the highest debug level to show
        highest = (Level::Level)0;
    }

    Tracer::~Tracer() {
    }
    
    /* ------------------------- Bind to squirrel --------------------------- */
    void Tracer::BindTracer(HSQUIRRELVM _vm) {
        // Just bind the print function
        sq_setprintfunc(_vm, &Tracer::sqPrint, &Tracer::sqPrint);
    }
    
    /* --------------------------- Set / Get Stream ------------------------- */
    void Tracer::SetStream(ostream& _out) {
        tracer.out = &_out;
    }
    
    ostream& Tracer::Trace(Level::Level _level) {
        ostream* out;
        if (_level >= tracer.highest)
            out = tracer.out;
        else
            out = &blackhole;
        
        (*out) << "[" << tracer.errors[_level] << "] ";
        return *out;
    }
    
    /* --------------------------- Set the level of the tracer -------------- */
    void Tracer::SetLevel(Level::Level _level) {
        tracer.highest = _level;
    }
    
    /* ------------------------- Squirrel Print function -------------------- */
    void Tracer::sqPrint(HSQUIRRELVM vm, const SQChar* s, ...) 
    { 
        // Buffer to write to.
        char buffer[256];
        for (int i = 0; i < 256; ++i) {
            buffer[i] = '\0';
        }
        
        // Arguement list to use
        va_list arglist;
        va_start(arglist, s); 
        vsprintf(buffer, s, arglist); 
        va_end(arglist);
        
        // Write this to the log
        Tracer::Trace(Level::NotGood) << buffer << endl;
    }      
}