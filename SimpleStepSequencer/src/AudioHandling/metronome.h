//
//  metronome.h
//  SimpleStepSequencer
//
//  Created by Anders Monrad on 06/08/2024.
//

/*
The metronome class manages rhythmic timing and audio playback for a step sequencer. It
synchronizes with a sequencerGui to update and display rhythm information, controls
playback with a musicPlayer, and processes audio buffers. Key functionalities include
setting up rhythm and tempo, updating rhythm details, toggling metronome activity, and
drawing current rhythm information on-screen.
*/

// These directives are used to prevent multiple inclusions of the same header file, which
// helps avoid redefinition errors and improves compilation efficiency:
#ifndef metronome_h
#define metronome_h

#include "ofMain.h"          // Includes OpenFrameworks core functionalities
#include "sequencerGui.h"    // Forward declaration of sequencerGui class
#include "musicPlayer.h"     // Forward declaration of musicPlayer class
#include "factory.h"         // Forward declaration of factory class (though not used directly here)
#include <memory>            // For std::unique_ptr

class metronome {
    
public:
    // Sets up the metronome with initial tempo, beat amount, and tuplets
    void setup(int initialTempo, int initialBeatAmount, int initialTupletAmount);
    
    // Updates the sequencer GUI (if necessary) based on metronome state
    void updateSeqGui();
    
    // Updates the metronome's internal state
    void update();
    
    // Processes audio data to generate metronome ticks
    void audioOut(ofSoundBuffer &buffer);
    
    // Toggles the metronome on or off
    void toggleOnOff(bool _onOff);
    
    // Sets the tempo of the metronome
    void setTempo(float bpm);
    
    // Updates the rhythm configuration of the metronome
    void updateRhythm(int quarters, int subdivision);
    
    // Draws the metronome's visual representation
    void draw();
    
    // Defines a struct to hold rhythm information
    struct m_rhythm {
        int m_bar;          // Current bar in the rhythm
        int m_quarterNote;  // Position within the bar
        int m_tuplet;       // Tuplet configuration
    };
    
    // Public member to access rhythm data
    m_rhythm m_myRhythm;
    
    // Constructor that initializes metronome with a pointer to a sequencerGui instance
    metronome(sequencerGui* seqGuiPtr, int sampleRate);
    
    // Destructor to handle cleanup
    ~metronome();
    
private:
    bool m_isSetup = false;         // Flag to indicate if metronome is set up
    bool m_onOff = false;           // Flag to indicate if metronome is active
    int m_bufferCounter;            // Counter to keep track of audio buffer samples
    int m_sampleRate;               // Sample rate for audio processing
    float m_samplesPerTick;         // Number of samples per metronome tick
    float m_tempo;                  // Tempo in beats per minute
    int m_tick;                     // Current tick count
    int m_subdivision;              // Subdivision of beats
    int m_subDivisionInOneBar;      // Number of subdivisions per bar
    int m_beatsToTheBar;            // Number of beats in one bar
    string m_instrumentDescription; // String to contain instrument-description
    
    std::unique_ptr<musicPlayer> m_musicPlayer; // Pointer to a musicPlayer instance
    
    sequencerGui* m_seqGuiPtr;     // Pointer to the sequencerGui instance used for GUI updates
};

#endif /* metronome_h */
