//
//  musicPlayer.cpp
//  SimpleStepSequencer
//
//  Created by Anders Monrad on 09/08/2024.
//

#include "musicPlayer.h"

// Constructor implementation
// The constructor takes a unique pointer to an instrument and initializes the musicPlayer
// with it. The unique pointer ensures that the musicPlayer class owns the instrument
// and that it will be automatically cleaned up when the musicPlayer is destroyed.
musicPlayer::musicPlayer(std::unique_ptr<instrument> instr)
: m_instrument(std::move(instr)) {
    // The unique pointer is moved to m_instrument, transferring ownership
    // from the caller to the musicPlayer instance.
}

// Method to play a sound using the specified instrument.
// This method calls the playSound function on the instrument, passing the
// whichInstrument parameter to select the appropriate sound or functionality.
void musicPlayer::play(int whichInstrument) {
    // Delegates the sound playback to the instrument
    m_instrument->playSound(whichInstrument);
}



/*
//
//  musicPlayer.cpp
//  SimpleStepSequencer
//
//  Created by Anders Monrad on 09/08/2024.
//

#include "musicPlayer.h"

musicPlayer::musicPlayer(std::unique_ptr<instrument> instr)
: m_instrument(std::move(instr)) {
    // Constructor implementation
}

void musicPlayer::play(int whichInstrument) {
    m_instrument->playSound(whichInstrument);
}
*/
