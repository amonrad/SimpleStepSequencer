// audioManager.h
// SimpleStepSequencer
//
// Created by Anders Monrad on 14/08/2024.
//

/*
The audioManager.cpp file defines the implementation for the audioManager class, handling
audio setup, processing, and cleanup. It configures audio settings using OpenFrameworks,
integrates with a metronome instance, and ensures proper resource management. The class
manages the audio stream and provides methods to process and clean up audio resources.
*/

// These directives are used to prevent multiple inclusions of the same header file, which
// helps avoid redefinition errors and improves compilation efficiency:
#ifndef audioManager_h
#define audioManager_h

#include "ofSoundStream.h" // OpenFrameworks sound stream header for audio processing
#include "metronome.h"     // Header for the Metronome class
#include <memory>         // For using std::unique_ptr

class audioManager {
public:
    // Constructor: Initializes audioManager with sample rate and buffer size
    audioManager(int sampleRate, int bufferSize);
    
    // Destructor: Cleans up resources
    ~audioManager();

    // Sets up the audio manager with a pointer to a sequencerGui
    void setup(sequencerGui* seqGui);
    
    // Processes audio buffer; to be called during audio processing
    void processAudio(ofSoundBuffer& buffer);
    
    // Cleans up resources before exiting
    void exit();
    
    // Provides access to the metronome instance
    metronome* getMetronome();

private:
    int m_sampleRate;  // Sample rate for audio processing
    int m_bufferSize;  // Buffer size for audio processing

    std::unique_ptr<metronome> m_metronome;  // Unique pointer to manage the metronome instance
    ofSoundStream m_soundStream;             // OpenFrameworks sound stream for audio input/output
};

#endif /* audioManager_h */
