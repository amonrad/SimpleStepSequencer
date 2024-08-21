//
//  midiInstrument.h
//  SimpleStepSequencer
//
//  Created by Anders Monrad on 09/08/2024.
//

/*
The midiInstrument class implements the instrument interface and provides functionality for
sending MIDI messages to control external MIDI devices.
*/

// These directives are used to prevent multiple inclusions of the same header file, which
// helps avoid redefinition errors and improves compilation efficiency:
#ifndef midiInstrument_h
#define midiInstrument_h

#include "instrument.h"
#include "ofxMidi.h"

class midiInstrument : public instrument {
public:
    // Constructor for the midiInstrument class
    midiInstrument();

    // Destructor for the midiInstrument class
    ~midiInstrument() override;

    // Overrides the pure virtual function from the instrument interface
    // to send a MIDI message to play a specific sound.
    void playSound(int whichInstrument) override;

private:
    ofxMidiOut m_midiOut;   // MIDI output object for sending MIDI messages
    int m_midiChannel;      // MIDI channel used to send messages (typically 1-16)
};

#endif /* midiInstrument_h */



/*
//
//  midiInstrument.h
//  SimpleStepSequencer
//
//  Created by Anders Monrad on 09/08/2024.
//

#ifndef midiInstrument_h
#define midiInstrument_h

#include "instrument.h"
#include "ofxMidi.h"

class midiInstrument : public instrument {
public:
    midiInstrument();
    ~midiInstrument() override;

    void playSound(int whichInstrument) override;

private:
    ofxMidiOut m_midiOut; // MIDI output object
    int m_midiChannel;    // MIDI channel to send messages on
};
*/
//#endif /* midiInstrument_h */
