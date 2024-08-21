//
//  metronome.cpp
//  SimpleStepSequencer
//
//  Created by Anders Monrad on 06/08/2024.
//

#include <stdio.h>
#include "metronome.h"

// Constructor that takes a pointer to a GUI instance
metronome::metronome(sequencerGui* seqGuiPtr, int _sampleRate) : m_seqGuiPtr(seqGuiPtr), m_sampleRate(_sampleRate) {
    
    // Choose between MIDI or Audio Instrument using the Factory class
    
    // auto instrument = factory::createSampleInstrument();
    // Or use
    auto instrument =  factory::createMidiInstrument();
    
    // Retrieve the description from the instrument
    m_instrumentDescription = instrument->getDescription();
    
    m_musicPlayer = factory::createMusicPlayer(std::move(instrument)); // Create the music player with the instrument
}

//----------------------------------------------

void metronome::setup(int initialTempo, int initialBeatAmount, int initialTupletAmount) {
    // Initialize rhythm and beat settings
    m_subdivision = initialTupletAmount;
    m_beatsToTheBar = initialBeatAmount;
    m_subDivisionInOneBar = m_subdivision * m_beatsToTheBar;
    m_tick = m_subDivisionInOneBar - 1;
    
    // Initialize rhythm struct
    m_myRhythm.m_bar = 0;
    m_myRhythm.m_quarterNote = 0;
    m_myRhythm.m_tuplet = 0;
    
    m_isSetup = true;
    
    setTempo(initialTempo); // Set the tempo
    updateSeqGui(); // Update the GUI
}

//----------------------------------------------

void metronome::updateSeqGui() {
    m_seqGuiPtr->setup(m_beatsToTheBar, m_subdivision); // Update GUI with current beat and subdivision settings
}

//----------------------------------------------

// Destructor implementation
metronome::~metronome() {
    // Clean-up code here (if needed)
}

//----------------------------------------------

void metronome::audioOut(ofSoundBuffer &buffer) {
    if (!m_onOff) {
        buffer.set(0.0f); // Fill the buffer with silence
        m_bufferCounter = 0;
        return; // Skip further processing if metronome is off
    } else {
        // Process audio when metronome is on
        for (int i = 0; i < buffer.size(); i += 2) {
            buffer[i] = 0.0f;     // Set left channel to silence
            buffer[i + 1] = 0.0f; // Set right channel to silence
        }

        m_bufferCounter += buffer.size() / 2.0f;

        // Update metronome state periodically based on buffer size
        if (m_bufferCounter >= m_samplesPerTick) {
            m_bufferCounter -= m_samplesPerTick;
            update(); // Update metronome state
        }
    }
}

//--------------------------------------------------------------

void metronome::toggleOnOff(bool _onOff) {
    m_onOff = _onOff;
    
    if (!m_onOff) {
        m_tick = m_subDivisionInOneBar - 1; // Reset tick count if metronome is turned off
    }
}

//--------------------------------------------------------------

void metronome::setTempo(float bpm) {
    if (m_isSetup) {
        m_tempo = bpm;
        m_samplesPerTick = (m_sampleRate * 60.0) / m_tempo / m_subdivision; // Calculate samples per tick
    }
}

//--------------------------------------------------------------

void metronome::updateRhythm(int quarters, int tuplets) {
    m_beatsToTheBar = quarters;
    m_subdivision = tuplets;
    setTempo(m_tempo); // Update tempo based on new rhythm settings
    updateSeqGui();    // Update the GUI with new rhythm settings
    m_subDivisionInOneBar = m_beatsToTheBar * m_subdivision; // Recalculate subdivisions per bar
    m_tick = m_subDivisionInOneBar - 1; // Reset tick count
}

//----------------------------------------------

void metronome::update() {
    if (m_isSetup) {
        m_tick++; // Increment the tick counter
        
        int localTick = m_tick % m_subDivisionInOneBar; // Calculate local tick position within the bar
        
        // Update rhythm data
        m_myRhythm.m_bar = m_tick / m_subDivisionInOneBar;
        m_myRhythm.m_quarterNote = localTick / m_subdivision;
        m_myRhythm.m_tuplet = localTick % m_subdivision;
        
        // Check if any beats should be played based on the current local tick
        for (int i = 0; i < 3; i++) {
            if (m_seqGuiPtr->isTickHighlighted(localTick, i)) {
                m_musicPlayer->play(i); // Play the beat for the corresponding track
            }
        }
        
        m_seqGuiPtr->update(localTick); // Update the sequencer GUI with the current tick
    }
}

//--------------------------------------------------------------

void metronome::draw() {
    ofSetColor(0, 0, 0); // Set text color to black
    
    // Draw the instrument description on the screen
    ofDrawBitmapString(m_instrumentDescription, 10, 125);
    
    // Draw the current rhythm data on the screen
    ofDrawBitmapString("bar:         " + ofToString(m_myRhythm.m_bar + 1), 50, 150);
    ofDrawBitmapString("quarterNote: " + ofToString(m_myRhythm.m_quarterNote + 1), 50, 160);
    ofDrawBitmapString("tuplet:      " + ofToString(m_myRhythm.m_tuplet + 1), 50, 170);
}
