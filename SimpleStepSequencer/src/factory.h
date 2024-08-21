// factory.h
// SimpleStepSequencer
//
// Created by Anders Monrad on 14/08/2024.
//

/*
The factory class is a utility class that provides methods for creating instances of
various objects related to the application, typically using a factory design pattern. It
simplifies object creation by encapsulating the instantiation logic. Methods within this
class, such as createSequencerGui(), createCustomGui(), createMetronome(),
createSampleInstrument(), and createMidiInstrument(), return pointers to newly created
objects of the specified types. This approach centralizes object creation and allows for
easy management and modification of object construction across the application.
*/

// These directives are used to prevent multiple inclusions of the same header file, which
// helps avoid redefinition errors and improves compilation efficiency:
#ifndef factory_h
#define factory_h

#include <memory>  // For std::unique_ptr

// Forward declarations
// Declaring classes without including their headers to reduce compilation dependencies

/*
From Stack Overflow:
    Use forward declarations (as in your example) whenever possible. This reduces compile
    times, but more importantly minimizes header and library dependencies for code that
    doesn't need to know and doesn't care for implementation details. In general, no code
    other than the actual implementation should care about implementation details.
*/

class audioManager;
class guiManager;
class sequencerGui;
class metronome;
class customGui;
class musicPlayer;
class instrument;
class midiInstrument;  // Note: Fixed class name from m_midiInstrument to midiInstrument
class sampleInstrument;

class factory {
public:
    // Factory method to create an instance of audioManager
    // Returns a unique pointer to an audioManager object, ensuring proper memory management
    static std::unique_ptr<audioManager> createAudioManager(int sampleRate, int bufferSize);

    // Factory method to create an instance of guiManager
    // Returns a unique pointer to a guiManager object
    static std::unique_ptr<guiManager> createGuiManager();
    
    // Factory method to create a metronome instance
    // Takes a raw pointer to a sequencerGui and returns a unique pointer to a metronome object
    // Note: Using raw pointers here; consider using std::unique_ptr for better memory management
    static std::unique_ptr<metronome> createMetronome(sequencerGui* seqGui, int sampleRate);

    // Factory method to create a sequencerGui instance
    // Returns a unique pointer to a sequencerGui object
    static std::unique_ptr<sequencerGui> createSequencerGui();

    // Factory method to create a customGui instance
    // Takes a raw pointer to a metronome and returns a unique pointer to a customGui object
    // Note: Using raw pointers here; consider using std::unique_ptr for better memory management
    static std::unique_ptr<customGui> createCustomGui(metronome* metronome);
    
    // Factory methods to create MusicPlayer and Instrument instances
    // Creates a MusicPlayer instance with a unique pointer to an Instrument
    static std::unique_ptr<musicPlayer> createMusicPlayer(std::unique_ptr<instrument> instrument);

    // Factory method to create a MidiInstrument instance
    // Returns a unique pointer to an instrument object that is specifically a MidiInstrument
    static std::unique_ptr<instrument> createMidiInstrument();

    // Factory method to create a SampleInstrument instance
    // Returns a unique pointer to an instrument object that is specifically a sampleInstrument
    static std::unique_ptr<instrument> createSampleInstrument();
};

#endif /* factory_h */
