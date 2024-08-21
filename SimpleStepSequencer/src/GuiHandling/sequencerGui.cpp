// sequencerGui.cpp
// SimpleStepSequencer
//
// Created by Anders Monrad on 06/08/2024.
//

#include <stdio.h>
#include "sequencerGui.h"

// Constructor implementation
sequencerGui::sequencerGui() {
    // Default constructor; currently does nothing
}

//--------------------------------------------------------------

// Destructor implementation
sequencerGui::~sequencerGui() {
    // Destructor; currently no specific cleanup required
}

//--------------------------------------------------------------

void sequencerGui::setup(int quarters, int _tuplets) {
    
    int steps = quarters * _tuplets;  // Calculate the total number of steps based on quarters and tuplets
    m_tuplets = _tuplets;  // Store the number of tuplets
    
    // Ensure steps is a positive number
    if (steps <= 0) {
        ofLogError("gui::setup") << "Steps must be greater than 0";
        return;
    }

    // Clear previous data in the vectors to avoid duplications
    for (int i = 0; i < 3; ++i) {
        m_beats[i].clear();
    }

    // Initialize each vector in the array with 'steps' number of RectangleWithFlag objects
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < steps; ++j) {
            // Calculate the position for the rectangle
            float x = 10 + j * 18;
            float y = 20 + (i * 25);
            
            // Setup steps with toggle on for hi-hat beats, otherwise toggle off
            if (i == 0) {
                m_beats[i].push_back({ ofRectangle(x, y, 15, 15), true });
            } else {
                m_beats[i].push_back({ ofRectangle(x, y, 15, 15), false });
            }
            // Add the rectangle to the vector
        }
    }
    m_guiChanged = true;  // Mark GUI as changed
}

//--------------------------------------------------------------

// Setup framebuffer separately to handle OpenFrameworks issue on iOS devices
void sequencerGui::setupFramebuffer() {
    m_frameBuffer.allocate(ofGetWidth(), ofGetHeight());  // Allocate the framebuffer with the current window size
    ofClear(0, 0, 0, 255);  // Clear the framebuffer with black color and full opacity
    m_frameBuffer.end();  // End the framebuffer drawing
    
    refreshFramebuffer();  // Refresh framebuffer to initialize content
}

//--------------------------------------------------------------

bool sequencerGui::isFramebufferReady() {
    return m_frameBuffer.isAllocated();  // Check if the framebuffer has been successfully allocated
}

//--------------------------------------------------------------

// Update function implementation
void sequencerGui::update(int _highlightTick) {
    m_highlightTick = _highlightTick;  // Update the tick to be highlighted
    m_guiChanged = true;  // Mark GUI as changed
}

//--------------------------------------------------------------

bool sequencerGui::isTickHighlighted(int _tick, int whichTrack) {
    // Check bounds to ensure valid access
    if (whichTrack < 0 || whichTrack >= 3 || _tick < 0 || _tick >= m_beats[whichTrack].size()) {
        ofLog() << "Invalid index!";
        return false;  // Return false if the index is out of bounds
    }
    
    // Return whether the specified tick is highlighted
    return m_beats[whichTrack][_tick].flag;
}

//--------------------------------------------------------------

void sequencerGui::draw() {
    if (m_guiChanged) {
        refreshFramebuffer();  // Refresh the framebuffer if the GUI has changed
    }
    ofSetColor(255, 255, 255);  // Set the color to white for drawing the framebuffer
    m_frameBuffer.draw(0, 0);  // Draw the framebuffer to the screen at position (0, 0)
}

//--------------------------------------------------------------

void sequencerGui::checkBox(const ofPoint& mouseClick) {
    // Iterate over each vector in the array of beats
    for (auto& vec : m_beats) {
        // Iterate over each RectangleWithFlag in the current vector
        for (auto& item : vec) {
            // Check if the mouse click is inside the rectangle
            if (item.rect.inside(mouseClick)) {
                // Toggle the boolean flag
                item.flag = !item.flag;
                m_guiChanged = true;  // Mark GUI as changed
            }
        }
    }
}

//--------------------------------------------------------------

void sequencerGui::refreshFramebuffer() {
    m_frameBuffer.begin();  // Begin drawing to the framebuffer
    ofClear(0, 0, 0);  // Clear the framebuffer with black color

    // Iterate over each vector in the array of beats
    for (const auto& vec : m_beats) {
        // Iterate over each RectangleWithFlag in the current vector
        for (size_t i = 0; i < vec.size(); ++i) {
            const auto& item = vec[i];

            // Set color of rectangle based on its index
            ofSetColor(setRectangleColor(i));

            // Draw the rectangle
            ofDrawRectangle(item.rect);

            // Draw a diagonal cross inside the rectangle if the flag is true
            drawDiagonalCross(item);
        }
    }
    m_frameBuffer.end();  // End drawing to the framebuffer
    m_guiChanged = false;  // Mark GUI as unchanged
}

//--------------------------------------------------------------

void sequencerGui::drawDiagonalCross(const m_rectangleWithFlag& item) {
    // Draw diagonal cross if flag is true
    if (item.flag) {
        ofSetColor(0);  // Set the color for the cross (black)

        // Get the rectangle's position and size
        float x = item.rect.getX();
        float y = item.rect.getY();
        float width = item.rect.getWidth();
        float height = item.rect.getHeight();

        ofSetLineWidth(3);  // Set line width for the cross

        // Draw diagonal lines
        ofDrawLine(x, y, x + width, y + height);  // Diagonal from top-left to bottom-right
        ofDrawLine(x, y + height, x + width, y);  // Diagonal from bottom-left to top-right
    }
}

//--------------------------------------------------------------

ofColor sequencerGui::setRectangleColor(int numberInVector) {
    ofColor rectColor;
    
    int addRed = 0;  // Variable to make color grey if not highlighted
    
    // Add red if highlighted
    if (numberInVector == m_highlightTick) {
        addRed = 100;
    }
    
    // Set color based on whether it’s a quarter note or a tuple
    if (numberInVector % m_tuplets == 0) {
        rectColor.set(155 + addRed, 155, 155);  // Lighter color for quarter notes
    } else {
        rectColor.set(120 + addRed, 120, 120);  // Darker color for other steps
    }
    return rectColor;
}
