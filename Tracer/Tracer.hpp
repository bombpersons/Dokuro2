/* 
 * File:   Tracer.hpp
 * Author: bombpersons
 *
 * Created on June 19, 2011, 2:30 PM
 */

#ifndef TRACER_HPP
#define	TRACER_HPP

#include <cstdarg>
#include <ostream>
using namespace std;

#include <SFML/System.hpp>

#include "../Sqrat/sqrat.h"
#include "../Squirrel/Bindings.hpp"

namespace Dokuro2 {
    
    namespace Level {
        enum Level {
            Meh = 0,
            Fine,
            NotGood,
            Bad,
            Successful,
            Fatal,
            Apocolyptic,
            
            Count, // Keep last. How many items are in the enum.
        };
    }
    
    class Tracer : public sf::NonCopyable {
    public:
        /* Bind to squirrel */
        static void BindTracer(HSQUIRRELVM _vm);
        
        /* Set and Get the output stream */
        static void SetStream(ostream& _out);
        
        /* Get the tracer */
        static ostream& Trace(Level::Level _level);
        
        /* Set the level of the tracer */
        static void SetLevel(Level::Level _level);
        
        /* Squirrel Error Function */
        static void sqPrint(HSQUIRRELVM vm, const SQChar* s, ...);       
        
        /* A black hole stream */
        static ostream blackhole;
        
    protected:
        ostream* out; // The output stream to use to write logs to. 
        string errors[Level::Count]; // The strings to use in error levels
        Level::Level highest; // The highest level debug to show
        
    private:
        /* The static instance of this class */
        static Tracer tracer;

        // Make sure the class isn't able to be create outside of here.
        Tracer();
        Tracer(const Tracer& orig);
        virtual ~Tracer();
        
        REGISTER_BINDING_DEF
    };

}

#endif	/* TRACER_HPP */
