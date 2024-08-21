// audioManager.cpp
// SimpleStepSequencer
//
// Created by Anders Monrad on 14/08/2024.
//

#include <stdio.h>
#include "audioManager.h" // Includes the header for audioManager
#include "factory.h"     // Includes the factory header to create instances

// Constructor implementation
audioManager::audioManager(int sampleRate, int bufferSize)
: m_sampleRate(sampleRate), m_bufferSize(bufferSize) {
    // Initialize member variables with provided sample rate and buffer size
}

//--------------------------------------------------------------

// Destructor implementation
audioManager::~audioManager() {
    exit(); // Ensure any necessary cleanup is performed
}

//--------------------------------------------------------------

void audioManager::setup(sequencerGui* seqGui) {
    // Use the factory to create a metronome instance, passing the sequencerGui pointer
    m_metronome = factory::createMetronome(seqGui, m_sampleRate);

    // Configure settings for the audio stream
    ofSoundStreamSettings settings;
    settings.setOutListener(m_metronome.get());  // Set the metronome as the listener for audio output
    settings.sampleRate = m_sampleRate;          // Set the sample rate
    settings.numOutputChannels = 2;              // Set the number of output channels (stereo)
    settings.numInputChannels = 0;               // No input channels are used
    settings.bufferSize = m_bufferSize;          // Set the buffer size for audio processing

    // Setup the sound stream with the configured settings
    m_soundStream.setup(settings);
}

//--------------------------------------------------------------

void audioManager::processAudio(ofSoundBuffer& buffer) {
    if (m_metronome) {
        // Process audio through the metronome
        m_metronome->audioOut(buffer);
    }
}

//--------------------------------------------------------------

void audioManager::exit() {
    // Perform any necessary cleanup when exiting
    m_soundStream.close(); // Close the sound stream to release resources
}

//--------------------------------------------------------------

metronome* audioManager::getMetronome() {
    return m_metronome.get();  // Return the raw pointer to the metronome instance
}
