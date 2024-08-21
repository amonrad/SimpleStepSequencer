//
//  midiInstrument.cpp
//  SimpleStepSequencer
//
//  Created by Anders Monrad on 09/08/2024.
//

#include <stdio.h>
#include "midiInstrument.h"
#include "ofLog.h"

// Constructor for the midiInstrument class
midiInstrument::midiInstrument() : m_midiChannel(1) {
    // List available MIDI ports for debugging purposes
    m_midiOut.listOutPorts();
    
    // Attempt to open the first available MIDI port
        int portIndex = 0;
        if (m_midiOut.openPort(portIndex)) {
            // Log success message if the MIDI port is opened successfully
            ofLog() << "MIDI port opened successfully!";
            
            // Convert the port index to a string
            std::string portName = "Port " + ofToString(m_midiOut.getPort());
            
            // Construct the description string with MIDI port and channel info
            description = "Sending MIDI to " + portName + " at channel " + std::to_string(m_midiChannel) + ".";
        } else {
            // Log failure message if the MIDI port could not be opened
            ofLog() << "Failed to open MIDI port!";
            description = "Failed to open MIDI port.";
        }
}

// Destructor for the midiInstrument class
midiInstrument::~midiInstrument() {
    // Close the MIDI port when the midiInstrument instance is destroyed
    m_midiOut.closePort();
}

// Method to play a sound via MIDI
void midiInstrument::playSound(int whichInstrument) {
    // Determine the MIDI note to play based on the whichInstrument parameter
    // Note values typically range from 0 to 127; this example uses a base note of 60 (Middle C)
    int note = 60 + whichInstrument;
    int velocity = 64; // Default velocity for the note (range 0 to 127)

    // Send a Note On message to the specified MIDI channel with the calculated note and velocity
    m_midiOut.sendNoteOn(m_midiChannel, note, velocity);
    // Log the note and channel information for debugging
    ofLog() << "Sent MIDI Note On: " << note << " on channel " << m_midiChannel;

    // Optionally send a Note Off message to stop the note after a short delay
    m_midiOut.sendNoteOff(m_midiChannel, note, velocity);
}



/*
//
//  midiInstrument.cpp
//  SimpleStepSequencer
//
//  Created by Anders Monrad on 09/08/2024.
//

#include <stdio.h>
#include "midiInstrument.h"
#include "ofLog.h"

midiInstrument::midiInstrument() : m_midiChannel(1) {
    m_midiOut.listOutPorts(); // List available MIDI ports for debugging
    if (m_midiOut.openPort(0)) { // Open the first available MIDI port
        ofLog() << "MIDI port opened successfully!";
    } else {
        ofLog() << "Failed to open MIDI port!";
    }
}

midiInstrument::~midiInstrument() {
    m_midiOut.closePort(); // Close the MIDI port when done
}

void midiInstrument::playSound(int whichInstrument) {
    int note = 60 + whichInstrument; // Example note value based on whichInstrument
    int velocity = 64;               // Example velocity

    m_midiOut.sendNoteOn(m_midiChannel, note, velocity); // Send a Note On message
    ofLog() << "Sent MIDI Note On: " << note << " on channel " << m_midiChannel;

    // Optionally send a Note Off message after a short delay
    m_midiOut.sendNoteOff(m_midiChannel, note, velocity);
}
*/
