// customGui.cpp
// SimpleStepSequencer
//
// Created by Anders Monrad on 06/08/2024.
//

#include <stdio.h>    // Includes standard input/output functions (not used here but included by default)
#include "customGui.h"  // Includes the header file for the customGui class
#include "metronome.h"  // Includes the header file for the metronome class

// Constructor that takes a pointer to a metronome instance
customGui::customGui(metronome* metronomePtr) : m_metronomePtr(metronomePtr) {
    
    // Initialize default values for GUI controls
    float initialTempo = 120;           // Default tempo in BPM
    int initialBeatAmount = 4;          // Default number of beats
    int initialTupletAmount = 4;        // Default number of tuplets
    
    // Set up the first GUI panel (m_gui1)
    m_gui1.setup();                     // Initializes the panel
    m_gui1.add(m_onOff.setup("onOff", false));   // Add a toggle button to the panel with default value false
    m_gui1.add(m_tempo.setup("Tempo", initialTempo, 30, 200));  // Add a float slider for tempo control
    m_gui1.setPosition(10, 200);        // Position the panel at coordinates (10, 200)
    
    // Set up the second GUI panel (m_gui2)
    m_gui2.setup();                     // Initializes the panel
    m_gui2.add(m_beats.setup("Beats", initialBeatAmount, 1, 8));  // Add an int slider for beats control
    m_gui2.add(m_tuplets.setup("Tuplets", initialTupletAmount, 2, 8));  // Add an int slider for tuplets control
    
    // Position the second panel to the right of the first panel with padding
    float padding = 10.0f;
    m_gui2.setPosition(m_gui1.getPosition().x + m_gui1.getWidth() + padding, m_gui1.getPosition().y);
    
    // Add listeners to GUI elements to handle user interactions
    m_onOff.addListener(this, &customGui::onToggleChanged);   // Toggle listener
    m_tempo.addListener(this, &customGui::onTempoChanged);    // Tempo slider listener
    m_beats.addListener(this, &customGui::onBeatsChanged);    // Beats slider listener
    m_tuplets.addListener(this, &customGui::onTupletsChanged);  // Tuplets slider listener
    
    // Initialize the metronome with the default values
    metronomePtr->setup(initialTempo, initialBeatAmount, initialTupletAmount);
}

//----------------------------------------------

// Destructor implementation
customGui::~customGui() {
    
    // Add any necessary cleanup code here
    // For example, removing listeners if necessary
}

//----------------------------------------------

void customGui::onToggleChanged(bool & value) {
    
    if (m_metronomePtr) { // Check if the pointer is not null before using it
        m_metronomePtr->toggleOnOff(value); // Update the metronome's on/off state
    }
}

//----------------------------------------------

void customGui::onTempoChanged(float &value) {
    
    if (m_metronomePtr) { // Check if the pointer is not null before using it
        m_metronomePtr->setTempo(value); // Update the metronome's tempo
    }
}

//----------------------------------------------

void customGui::onBeatsChanged(int &value){
    if (m_metronomePtr) { // Ensure metronomePtr is valid before using it
        m_metronomePtr->updateRhythm(value, m_tuplets); // Update rhythm with the new beats value
    }
}

//----------------------------------------------

void customGui::onTupletsChanged(int &value){
    if (m_metronomePtr) { // Ensure metronomePtr is valid before using it
        m_metronomePtr->updateRhythm(m_beats, value); // Update rhythm with the new tuplets value
    }
}

//----------------------------------------------

void customGui::draw() {
    
    m_gui1.draw();  // Draw the first panel
    
    if (!m_onOff) { // If the toggle is off, draw the second panel
        m_gui2.draw();
    }
}
