/**
 * @file
 * @copyright
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * @author Thomas Vogt, thomas@thomas-vogt.de
 *
 * @brief C Main.
 **/

#ifndef MAIN_H
#define MAIN_H

#include"io_adapter.h"
#include"hangman.h"
#include"game_state.h"

/**
 * @brief starts the hangman game
 * 
 * @return 0 if finished, else replay wanted
 */
int myMain( void );

#endif
