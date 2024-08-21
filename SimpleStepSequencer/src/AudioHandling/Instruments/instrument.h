//
//  Instrument.h
//  SimpleStepSequencer
//
//  Created by Anders Monrad on 09/08/2024.
//

/*
The instrument class is an abstract base class defining the interface for musical
instruments in the sequencer. It includes a pure virtual function playSound(int
whichInstrument) that derived classes must implement to produce sound. The class also
provides a virtual destructor to ensure proper cleanup of derived objects.
*/

// These directives are used to prevent multiple inclusions of the same header file, which
// helps avoid redefinition errors and improves compilation efficiency:
#ifndef Instrument_h
#define Instrument_h

#include <string> // Include this to use std::string

// Instrument-interface

class instrument {

protected:
    std::string description; // Protected member to hold the description

public:
    virtual void playSound(int whichInstrument) = 0; // Pure virtual function
    virtual ~instrument() = default; // Virtual destructor for proper cleanup
    
    // Function to get the description of the instrument
    std::string getDescription() {
        return description;
    }
};

#endif /* Instrument_h */
