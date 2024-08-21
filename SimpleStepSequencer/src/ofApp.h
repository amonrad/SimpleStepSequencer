/*
The ofApp class in openFrameworks is a user-defined class that extends ofBaseApp to
implement the core functionalities of an application. It includes methods for setup
(setup()), updating (update()), drawing (draw()), handling input events (keyPressed(),
mousePressed(), etc.), and performing cleanup (exit()). This class serves as the main
entry point for defining and controlling the application's behavior.
*/

#pragma once  // Ensures the file is included only once during compilation, preventing redefinition errors.

#include "ofMain.h"        // Includes core openFrameworks functionality.
#include "audioManager.h"  // Includes the header for the audioManager class.
#include "guiManager.h"    // Includes the header for the guiManager class.

// The ofApp class inherits from ofBaseApp, which provides basic app lifecycle methods
// like setup, update, draw, etc. This is the main application class that controls the app's behavior.
class ofApp : public ofBaseApp {
public:
    // Called once when the application starts. Used to initialize the app.
    void setup() override;

    // Called every frame before draw(). Used to update variables and logic.
    void update() override;

    // Called every frame after update(). Used to render the app's visuals.
    void draw() override;

    // Called when the application is about to exit. Used for cleanup tasks.
    void exit() override;

    // Called when the mouse is pressed. Used to handle mouse press events.
    void mousePressed(int x, int y, int button) override;

    // Called periodically by the sound stream to fill the sound buffer.
    // This is where audio processing occurs.
    void audioOut(ofSoundBuffer & buffer) override;

private:
    // Unique pointers to the audioManager and guiManager instances.
    // These manage the audio and GUI components of the app, respectively.
    std::unique_ptr<audioManager> m_audioManager;
    std::unique_ptr<guiManager> m_guiManager;

    // The sample rate for the audio processing. Defines the number of samples per second.
    int m_sampleRate = 44100;

    // The size of the audio buffer. Defines the number of samples processed at a time.
    int m_bufferSize = 512;
};
