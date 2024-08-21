// sequencerGui.h
// SimpleStepSequencer
//
// Created by Anders Monrad on 06/08/2024.
//

/*
The sequencerGui class is responsible for managing and rendering the graphical user
interface for a sequencer. It includes functionality for setting up the GUI, handling
interactions, and drawing both the GUI and any graphical elements. The class also utilizes
a framebuffer (ofFbo) for optimizing rendering performance. Key features include the
ability to highlight specific ticks, handle mouse interactions, and update the display
based on internal states. The private members and methods provide additional
functionalities for managing the state and appearance of GUI elements.
*/

// These directives are used to prevent multiple inclusions of the same header file, which
// helps avoid redefinition errors and improves compilation efficiency:
#ifndef sequencerGui_h
#define sequencerGui_h

#include "ofMain.h"  // Includes the core OpenFrameworks classes and functions

// Class definition for sequencerGui
class sequencerGui {
public:
    // Constructor
    sequencerGui();
    
    // Destructor
    ~sequencerGui();

    // Member functions
    void setup(int quarters, int _tuplets);       // Initializes the GUI with specified parameters
    void setupFramebuffer();                      // Sets up the framebuffer for off-screen rendering
    void update(int _highlightTick);              // Updates the GUI state, potentially highlighting ticks
    void checkBox(const ofPoint& mouseClick);    // Handles mouse click events for checkboxes
    void draw();                                 // Renders the GUI to the screen
    void refreshFramebuffer();                   // Refreshes the framebuffer to ensure updates
    bool isTickHighlighted(int _tick, int whichTrack); // Checks if a specific tick is highlighted
    bool isFramebufferReady();                   // Checks if the framebuffer is ready for drawing
    
private:
    
    // Define a struct to store rectangles with a flag
    struct m_rectangleWithFlag {
        ofRectangle rect;  // Rectangle representing a GUI element or region
        bool flag;         // Boolean flag associated with the rectangle
    };
    
    // Function to set the color of a rectangle based on its index
    ofColor setRectangleColor(int numberInVector);
    
    // Function to draw a diagonal cross inside a rectangle
    void drawDiagonalCross(const m_rectangleWithFlag& item);
    
    // Vector of vectors to store rectangles with flags for different tracks
    std::vector<m_rectangleWithFlag> m_beats[3];
    
    ofFbo m_frameBuffer;  // Framebuffer object for off-screen rendering and optimization
    bool m_guiChanged = false;  // Flag to indicate if the GUI has been modified
    
    int m_highlightTick = -1;  // Tick to be highlighted, default is -1 (no highlight)
    int m_tuplets;  // Number of tuplets used in the GUI
    
};

#endif /* sequencerGui_h */
