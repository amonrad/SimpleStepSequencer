/*
The ofMain class in openFrameworks is the core class that manages the application's
lifecycle, including initialization, updating, drawing, and cleanup. It orchestrates the
main loop where application logic is updated and graphics are rendered, and handles event
processing and resource management.
*/

#include "ofMain.h"  // Includes the core openFrameworks header, which provides essential framework functionality.
#include "ofApp.h"   // Includes the header file for your main application class, ofApp.

//========================================================================
int main( ){
     
    // Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
    // ofGLFWWindowSettings allows configuration of window properties like size, mode, and more advanced settings.
    ofGLWindowSettings settings;
     
    // Set the window size to 1200x768 pixels. This defines the resolution of the window when created.
    settings.setSize(1200, 768);
     
    // Set the window mode to OF_WINDOW, which creates a windowed application.
    // You can switch this to OF_FULLSCREEN to create a fullscreen application.
    settings.windowMode = OF_WINDOW;

    // Create the window using the specified settings.
    // ofCreateWindow returns a shared pointer to an ofAppBaseWindow object that manages the window.
    auto window = ofCreateWindow(settings);

    // Start the application, linking the window with the ofApp instance.
    // ofRunApp takes the window to run the application in, and the instance of your main application class.
    ofRunApp(window, make_shared<ofApp>());

    // Start the main event loop, which continuously handles events, updates, and drawing.
    // The loop runs until the application is closed.
    ofRunMainLoop();
}
