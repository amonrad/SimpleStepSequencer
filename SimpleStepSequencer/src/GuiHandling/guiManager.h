// guiManager.h
// SimpleStepSequencer
//
// Created by Anders Monrad on 14/08/2024.
//

/*
The guiManager class manages the GUI components of the application, including the setup,
update, draw, and mouse event handling. It utilizes the factory to create and initialize
GUI elements and maintains pointers to these elements. The class ensures that components
are drawn and updated correctly while managing state such as whether the framebuffer
object has been set up. The exit method is included for potential future cleanup
operations.
*/

// These directives are used to prevent multiple inclusions of the same header file, which
// helps avoid redefinition errors and improves compilation efficiency:
#ifndef guiManager_h
#define guiManager_h

#include <memory>              // Includes memory management utilities for smart pointers
#include "customGui.h"         // Includes the definition of the customGui class
#include "sequencerGui.h"      // Includes the definition of the sequencerGui class
#include "metronome.h"         // Include the full definition of the metronome class


// Declaration of the guiManager class
class guiManager {
public:
    // Constructor
    guiManager();
    
    // Destructor
    ~guiManager();

    // Public methods
    void setup();               // Initialize the GUI components
    void update();             // Update the GUI components
    void draw();               // Draw the GUI components
    void exit();               // Clean up resources before exiting

    void mousePressed(int x, int y); // Handle mouse press events
    
    void setMetronome(metronome* metronomePtr); // Set the metronome pointer
    
    sequencerGui* getSequencerGui();  // Retrieve the sequencerGui pointer

private:
    // Private members
    metronome* m_metronome;           // Pointer to the metronome object, raw pointer used for simplicity

    std::unique_ptr<customGui> m_gui; // Smart pointer to manage the customGui instance
    std::unique_ptr<sequencerGui> m_seqGui; // Smart pointer to manage the sequencerGui instance

    bool m_isFboSetup = false;        // Flag to indicate if the framebuffer object (FBO) has been set up
};

#endif /* guiManager_h */
