#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Set vertical synchronization to ensure the drawing is synchronized with the display's refresh rate
    ofSetVerticalSync(true);
    
    // Set the background color of the window (light gray in this case)
    ofBackground(230, 230, 230);

    // Use the Factory class to create an instance of guiManager
    // This ensures that the creation logic is centralized and consistent
    m_guiManager = factory::createGuiManager();

    // Initialize the GUI manager
    // This may include setting up GUI components and any necessary configuration
    m_guiManager->setup();

    // Use the Factory class to create an instance of audioManager with the specified sample rate and buffer size
    // This ensures that the creation logic is centralized and consistent
    m_audioManager = factory::createAudioManager(m_sampleRate, m_bufferSize);
    
    // Initialize the Audio manager
    // This method likely sets up audio processing and any audio-related configurations
    // Pass the sequencerGui instance to AudioManager to establish a link between the GUI and audio processing
    m_audioManager->setup(m_guiManager->getSequencerGui());

    // Set the metronome pointer in the GUI manager to ensure that the GUI can interact with the metronome
    // Retrieve the metronome instance from the AudioManager and pass it to the GUI manager
    m_guiManager->setMetronome(m_audioManager->getMetronome());
}

//--------------------------------------------------------------
void ofApp::exit(){
    // Clean up resources and perform any necessary shutdown operations
    // Call the exit methods for both AudioManager and GUIManager to ensure a proper cleanup
    m_audioManager->exit();
    m_guiManager->exit();
}

//--------------------------------------------------------------
void ofApp::update(){
    // Update the sound system to handle any changes or processing
    // This might include updating audio playback, processing, or other related tasks
    ofSoundUpdate();
    
    // Update the GUI manager, which may involve processing user input, refreshing the display, etc.
    m_guiManager->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Draw the GUI elements to the screen
    // This method is responsible for rendering the GUI components managed by guiManager
    m_guiManager->draw();
}

//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer &buffer){
    // Process the audio buffer using the AudioManager
    // This method is called to fill the audio buffer with audio data
    // The AudioManager handles the audio processing and provides the necessary data to the buffer
    m_audioManager->processAudio(buffer);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    // Handle mouse press events
    // Pass the mouse position and button information to the GUI manager
    // This allows the GUI manager to respond to user interactions with the GUI elements
    m_guiManager->mousePressed(x, y);
}
