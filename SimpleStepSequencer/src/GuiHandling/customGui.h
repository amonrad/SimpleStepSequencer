// customGui.h
// SimpleStepSequencer
//
// Created by Anders Monrad on 06/08/2024.
//

/*
The customGui class manages the user interface for controlling a metronome. It provides
sliders for adjusting tempo, beats, and tuplets, and a toggle switch for enabling or
disabling some functionality. The constructor initializes the GUI elements and sets up
listeners to handle user input. Callback methods update the metronome based on user
interactions. The draw method renders the GUI elements on the screen, conditionally
displaying some panels based on the state of the toggle switch.
*/

// These directives are used to prevent multiple inclusions of the same header file, which
// helps avoid redefinition errors and improves compilation efficiency:
#ifndef customGui_h
#define customGui_h

#include "ofMain.h"    // Includes openFrameworks core functionality
#include "ofxGui.h"    // Includes ofxGui for GUI elements

// Forward declaration of the metronome class
class metronome;

class customGui {
    
public:
    // Draws the GUI elements
    void draw();
    
    // Callback for when a toggle control changes its value
    void onToggleChanged(bool & value);
    
    // Callback for when the tempo slider changes its value
    void onTempoChanged(float & value);
    
    // Callback for when the beats slider changes its value
    void onBeatsChanged(int & value);
    
    // Callback for when the tuplets slider changes its value
    void onTupletsChanged(int & value);
    
    // Constructor that initializes customGui with a metronome pointer
    customGui(metronome* metronomePtr);
    
    // Destructor
    ~customGui();
    
    // Pointer to the metronome instance used by this GUI
    metronome* m_metronomePtr;

    // GUI elements
    ofxFloatSlider m_tempo;    // Slider for tempo control
    ofxIntSlider m_beats;      // Slider for beats control
    ofxIntSlider m_tuplets;    // Slider for tuplets control
    ofxToggle m_onOff;         // Toggle switch for enabling/disabling
    
    // Panels for organizing GUI elements
    ofxPanel m_gui1;           // First GUI panel
    ofxPanel m_gui2;           // Second GUI panel
};

#endif /* customGui_h */
