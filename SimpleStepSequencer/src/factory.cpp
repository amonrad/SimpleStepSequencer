//
//  Factory.cpp
//  SimpleStepSequencer
//
//  Created by Anders Monrad on 14/08/2024.
//

#include <stdio.h>              // Includes standard I/O operations; not strictly necessary here
#include "factory.h"           // Header file containing the declarations of factory methods
#include "audioManager.h"      // Includes the full definition of the audioManager class
#include "guiManager.h"        // Includes the full definition of the guiManager class
#include "metronome.h"         // Includes the full definition of the metronome class
#include "sequencerGui.h"      // Includes the full definition of the sequencerGui class
#include "customGui.h"         // Includes the full definition of the customGui class
#include "musicPlayer.h"       // Includes the full definition of the MusicPlayer class
#include "midiInstrument.h"    // Includes the full definition of the MidiInstrument class
#include "sampleInstrument.h"  // Includes the full definition of the sampleInstrument class

// Factory method to create audioManager
std::unique_ptr<audioManager> factory::createAudioManager(int sampleRate, int bufferSize) {
    // Creates and returns a unique pointer to a new audioManager object
    // The audioManager is initialized with sampleRate and bufferSize
    return std::make_unique<audioManager>(sampleRate, bufferSize);
}

// Factory method to create guiManager
std::unique_ptr<guiManager> factory::createGuiManager() {
    // Creates and returns a unique pointer to a new guiManager object
    return std::make_unique<guiManager>();
}

// Factory method to create a Metronome instance
std::unique_ptr<metronome> factory::createMetronome(sequencerGui* seqGui, int sampleRate) {
    // Creates and returns a unique pointer to a new metronome object
    // The metronome is initialized with a raw pointer to sequencerGui and sampleRate
    return std::make_unique<metronome>(seqGui, sampleRate);
}

// Factory method to create a SequencerGui instance
std::unique_ptr<sequencerGui> factory::createSequencerGui() {
    // Creates and returns a unique pointer to a new sequencerGui object
    return std::make_unique<sequencerGui>();
}

// Factory method to create a CustomGui instance
std::unique_ptr<customGui> factory::createCustomGui(metronome* metronome) {
    // Creates and returns a unique pointer to a new customGui object
    // The customGui is initialized with a raw pointer to metronome
    return std::make_unique<customGui>(metronome);
}

// Factory method to create a MusicPlayer instance with an Instrument
std::unique_ptr<musicPlayer> factory::createMusicPlayer(std::unique_ptr<instrument> instrument) {
    // Creates and returns a unique pointer to a new musicPlayer object
    // The musicPlayer is initialized with a unique pointer to an instrument
    // std::move is used to transfer ownership of the instrument to musicPlayer
    return std::make_unique<musicPlayer>(std::move(instrument));
}

// Factory method to create a MidiInstrument instance
std::unique_ptr<instrument> factory::createMidiInstrument() {
    // Creates and returns a unique pointer to a new midiInstrument object
    // midiInstrument is derived from instrument
    return std::make_unique<midiInstrument>(); // Fixed class name from m_midiInstrument to midiInstrument
}

// Factory method to create a sampleInstrument instance
std::unique_ptr<instrument> factory::createSampleInstrument() {
    // Creates and returns a unique pointer to a new sampleInstrument object
    // sampleInstrument is derived from instrument
    return std::make_unique<sampleInstrument>();
}
