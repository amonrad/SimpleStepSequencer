//
//  sampleInstrument.h
//  SimpleStepSequencer
//
//  Created by Anders Monrad on 09/08/2024.
//

/*
The sampleInstrument class implements the instrument interface.
It uses ofSoundPlayer to play different types of sounds, such as kick, snare, and hi-hat.
*/

// These directives are used to prevent multiple inclusions of the same header file, which
// helps avoid redefinition errors and improves compilation efficiency:
#ifndef sampleInstrument_h
#define sampleInstrument_h

#include "instrument.h"
#include "ofSoundPlayer.h"

class sampleInstrument : public instrument {
public:
    // Constructor for sampleInstrument
    sampleInstrument();

    // Destructor for sampleInstrument
    ~sampleInstrument() override;

    // Overrides the pure virtual function from the instrument interface
    // to play a specific sound based on the whichInstrument parameter.
    void playSound(int whichInstrument) override;

private:
    // ofSoundPlayer instances for different sounds
    ofSoundPlayer m_kick;    // Player for kick drum sound
    ofSoundPlayer m_snare;   // Player for snare drum sound
    ofSoundPlayer m_hihat;   // Player for hi-hat sound
};

#endif /* sampleInstrument_h */
