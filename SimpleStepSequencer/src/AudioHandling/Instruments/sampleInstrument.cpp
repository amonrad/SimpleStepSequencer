//
//  sampleInstrument.cpp
//  SimpleStepSequencer
//
//  Created by Anders Monrad on 09/08/2024.
//

#include <stdio.h>
#include "sampleInstrument.h"

// Constructor for the sampleInstrument class
sampleInstrument::sampleInstrument() {
    
    description = "This is a sample instrument that plays kick, snare, and hi-hat sounds.";
        // Initialize ofSoundPlayer objects here if needed
    
    // Load sound files into the ofSoundPlayer instances
    m_kick.load("kick.wav");    // Load kick drum sound file
    m_snare.load("snare.wav");  // Load snare drum sound file
    m_hihat.load("hihat.wav");  // Load hi-hat sound file
}

// Destructor for the sampleInstrument class
sampleInstrument::~sampleInstrument() {
    // Perform cleanup if necessary (e.g., releasing resources)
    // Currently empty as ofSoundPlayer handles its own resources
}

// Implementation of the playSound method from the instrument interface
void sampleInstrument::playSound(int whichInstrument) {
    // Play the sound based on the value of whichInstrument
    // 0 - play hi-hat sound
    // 1 - play snare drum sound
    // other values - play kick drum sound
    if (whichInstrument == 0) {
        m_hihat.play();  // Play the hi-hat sound
    } else if (whichInstrument == 1) {
        m_snare.play();  // Play the snare drum sound
    } else {
        m_kick.play();   // Play the kick drum sound
    }
}


/*
//
//  sampleInstrument.cpp
//  SimpleStepSequencer
//
//  Created by Anders Monrad on 09/08/2024.
//

#include <stdio.h>
#include "sampleInstrument.h"

sampleInstrument::sampleInstrument() {
    m_kick.load("kick.wav");
    m_snare.load("snare.wav");
    m_hihat.load("hihat.wav");
}

sampleInstrument::~sampleInstrument() {
    // Cleanup if necessary
}

void sampleInstrument::playSound(int whichInstrument) {
    if (whichInstrument == 0) {
        m_hihat.play();
    } else if (whichInstrument == 1) {
        m_snare.play();
    } else {
        m_kick.play();
    }
}
*/
