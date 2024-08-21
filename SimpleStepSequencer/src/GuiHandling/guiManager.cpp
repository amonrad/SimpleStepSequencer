// guiManager.cpp
// SimpleStepSequencer
//
// Created by Anders Monrad on 14/08/2024.
//

#include <stdio.h>          // Standard I/O functions, not strictly needed here
#include "guiManager.h"     // Includes the header for the guiManager class
#include "factory.h"        // Includes the factory class for creating GUI components
#include "metronome.h"      // Includes the metronome class

// Constructor
guiManager::guiManager() {
    // Default constructor; currently does not perform any actions
}

//--------------------------------------------------------------

// Destructor
guiManager::~guiManager() {
    exit(); // Calls the exit method to perform cleanup
}

//--------------------------------------------------------------

// Setup method
void guiManager::setup() {
    // Initialize the GUI elements using the Factory class
    m_seqGui = factory::createSequencerGui(); // Creates a new sequencerGui instance using the factory
}

//--------------------------------------------------------------

// Set the metronome pointer
void guiManager::setMetronome(metronome* metronomePtr) {
    m_metronome = metronomePtr;  // Assigns the provided metronome pointer to the member variable
    m_gui = factory::createCustomGui(m_metronome);  // Creates a new customGui instance using the factory and the metronome
}

//--------------------------------------------------------------

// Get the sequencerGui pointer
sequencerGui* guiManager::getSequencerGui() {
    return m_seqGui.get();  // Returns the raw pointer to the sequencerGui instance managed by the unique_ptr
}

//--------------------------------------------------------------

// Update method
void guiManager::update() {
    // Check if framebuffer setup is required and if it's not already done
    if (!m_isFboSetup) {
        if (!m_seqGui->isFramebufferReady()) {  // Check if the framebuffer is ready
            m_seqGui->setupFramebuffer();  // Setup framebuffer if it's not ready
            m_isFboSetup = true;  // Mark framebuffer as set up
        }
    }
}

//--------------------------------------------------------------

// Draw method
void guiManager::draw() {
    // Draw the GUI components if they exist
    if (m_seqGui) m_seqGui->draw();         // Draw the sequencerGui if it's initialized
    if (m_gui) m_gui->draw();               // Draw the customGui if it's initialized
    if (m_metronome) m_metronome->draw();   // Draw the metronome if it's initialized
    
}

//--------------------------------------------------------------

// Mouse pressed event handler
void guiManager::mousePressed(int x, int y) {
    if (m_seqGui) {  // Check if sequencerGui is initialized
        ofPoint mousePosition(x, y);  // Create an ofPoint object with mouse coordinates
        m_seqGui->checkBox(mousePosition);  // Check if a checkbox was clicked
    }
}

//--------------------------------------------------------------

// Exit method
void guiManager::exit() {
    // Perform any necessary cleanup
    // Currently empty but can be used to release resources or perform other shutdown tasks
}
