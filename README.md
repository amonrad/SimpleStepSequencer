# SimpleStepSequencer


## Overview

SimpleStepSequencer is a macOS-specific application built using openFrameworks and the ofxMidi addon. This project implements a simple step sequencer that interacts with MIDI devices and processes sound streams, enabling users to create and control MIDI sequences - or alternatively plays sounds via a samplePlayer.


## Features

- **Mac-Specific Application**: Designed and tested for macOS.
- **openFrameworks Integration**: Utilizes openFrameworks v0.12.0 for graphics and audio processing.
- **Interchangeable Instruments**: The `metronome` class allows the selection of different instrument types — either `midiInstrument` for MIDI device control or `sampleInstrument` for sample-based audio playback, during its construction.
- **ofxMidi Addon**: Leverages the ofxMidi addon to manage MIDI input and output.
- **MIDI Device Management**: Connect and control MIDI devices through the application.
- **Sound Stream Processing**: Create and manage sound streams for audio sequencing.
- **Automatic Resource Cleanup**: Ensures all resources like MIDI devices and sound streams are properly cleaned up during program exit.


## Requirements

- **Platform**: macOS (tested on macOS Monterey).
- **Programming Language**: C++.
- **Framework**: openFrameworks v0.12.0.
- **External Addon**: ofxMidi addon for openFrameworks.


## Project Structure

This project is part of the openFrameworks directory structure. The project is located at:

```bash
of_v0.12.0_osx_release/apps/myApps/SimpleStepSequencer
```

Ensure that you place the SimpleStepSequencer folder within this directory path when working with the project.

The Source Code is organized as follows: 

src/
├── Main.cpp
├── ofApp.h
├── ofApp.cpp
├── factory.h
├── factory.cpp
├── GuiHandling/
│   ├── guiManager.h
│   ├── guiManager.cpp
│   ├── customGui.h
│   ├── customGui.cpp
│   ├── sequencerGui.h
│   ├── sequencerGui.cpp
├── Instruments/
│   ├── instrument.h          # Abstract base class
│   ├── musicPlayer.h
│   ├── musicPlayer.cpp
│   ├── sampleInstrument.h
│   ├── sampleInstrument.cpp
│   ├── midiInstrument.h
│   ├── midiInstrument.cpp
├── AudioHandling/
│   ├── audioManager.h
│   ├── audioManager.cpp
│   ├── metronome.h
│   ├── metronome.cpp


## Installation

1. **Download and Install openFrameworks**:
   - Download the macOS version of openFrameworks v0.12.0 from the [official openFrameworks website](https://openframeworks.cc/download/).
   - Follow the setup instructions for macOS as outlined in the openFrameworks documentation.

2. **Install the ofxMidi Addon**:
   - Clone the ofxMidi addon into the `addons` directory of your openFrameworks installation:

```bash
cd of_v0.12.0_osx_release/addons/
git clone https://github.com/danomatika/ofxMidi.git
```

3. **Clone the repository**:
- Place the repository in the correct openFrameworks directory structure:

```bash
cd of_v0.12.0_osx_release/apps/myApps/
git clone https://github.com/yourusername/SimpleStepSequencer.git
```

4. **Open the Project**:
- Use the openFrameworks Project Generator to import the SimpleStepSequencer project. Ensure that ofxMidi is included as an addon.
- Open the generated Xcode project file (.xcodeproj).


5. **Build and Run**:
- Build the project in Xcode.
- Run the application directly within Xcode.

## Usage

### Running the Application

- Basic usage: Launch the application from Xcode or by running the compiled binary directly.

### Instrument Selection in the Metronome

- The metronome class supports two types of instruments, selectable during its construction:
    
    - MIDI Instrument: Controls external MIDI devices by sending MIDI messages to a specified MIDI port and channel.
    - Sample Instrument: Plays pre-recorded audio samples (e.g., kick, snare, hi-hat) using the sampleInstrument class.
    
- The specific instrument type (midiInstrument or sampleInstrument) must be selected when the metronome object is created. This choice cannot be changed at runtime.

### Command Line Options

- `--input`: Specify the MIDI input device.
- `--output`: Specify the sound output stream.
- `--help`: Show help information.

Example:

```bash
./SimpleStepSequencer --input "midi_device" --output "sound_stream"
``

## Contributing

Contributions are welcome! If you'd like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature/bugfix: `git checkout -b feature-name`.
3. Commit your changes: `git commit -m 'Add some feature'`.
4. Push the branch to your fork: `git push origin feature-name`.
5. Open a pull request on GitHub.

Please ensure that your code follows the project's coding standards.


## License

This project is licensed under the MIT License


## Acknowledgments

- **openFrameworks** - The open-source toolkit that powers this project.
- **ofxMidi** - The addon used for MIDI integration within openFrameworks.


