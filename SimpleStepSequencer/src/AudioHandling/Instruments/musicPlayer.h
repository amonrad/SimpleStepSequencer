//
//  musicPlayer.h
//  SimpleStepSequencer
//
//  Created by Anders Monrad on 09/08/2024.
//

/*
The musicPlayer class is responsible for managing and playing sounds using a specific
instrument.
*/

// These directives are used to prevent multiple inclusions of the same header file, which
// helps avoid redefinition errors and improves compilation efficiency:
#ifndef musicPlayer_h
#define musicPlayer_h

#include "instrument.h"
#include <memory> // For using smart pointers


class musicPlayer {
public:
    // Constructor that initializes the musicPlayer with a given instrument.
    // The instrument is managed using a unique_ptr to ensure proper resource management and ownership.
    musicPlayer(std::unique_ptr<instrument> instr);

    // Method to trigger the playback of a sound on the specified instrument.
    // The 'whichInstrument' parameter allows selecting which sound or instrument to use.
    void play(int whichInstrument);

private:
    // A unique_ptr to an instrument instance, ensuring exclusive ownership and automatic resource management.
    std::unique_ptr<instrument> m_instrument;
};

#endif /* musicPlayer_h */

/*
//
//  musicPlayer.h
//  SimpleStepSequencer
//
//  Created by Anders Monrad on 09/08/2024.
//

#ifndef musicPlayer_h
#define musicPlayer_h

#include "instrument.h"
#include <memory> // For using smart pointers

class musicPlayer {
public:
    musicPlayer(std::unique_ptr<instrument> instr);
    void play(int whichInstrument);

private:
    std::unique_ptr<instrument> m_instrument; // Pointer to the instrument
};
*/
//#endif /* musicPlayer_h */
