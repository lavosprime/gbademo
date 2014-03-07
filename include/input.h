//==============================================================================
/*
    Header file for various button input functions

    Copyright 2014 by Cooper Johnson.

    This program is free software provided under the terms of the MIT License.
    It uses libgba, which is provided under the terms of the GNU LGPL v2 by the
    devkitpro project (http://sourceforge.net/projects/devkitpro).
*/
//==============================================================================

#ifndef _input_h
#define _input_h

#include <gba_types.h>

/*------------------------------------------------------------------------------
 * Functions for frame-locking of input logic and acquiring input state
 *----------------------------------------------------------------------------*/

/*
 * Updates internal tracking of current and previous key states.
 */
inline void refresh_keys();

/*
 * Returns the key state as of the most recent call to refresh_keys().
 */
inline u16 get_curr_keys();

/*
 * Returns the key state from before the most recent call to refresh_keys().
 */
inline u16 get_prev_keys();

/*------------------------------------------------------------------------------
 * "Tribool" values of -1 for left/up, 1 for right/down, or 0 for none/both.
 * Tribools enable simple addition instead of if/else blocks for handling
 * directional controls.
 *----------------------------------------------------------------------------*/

/*
 * Converts the given boolean values representing a "positive" value and a
 * "negative" value to a corresponding tribool.
 */
#define TRIBOOL(POS, NEG) ((!(POS))^1 - (!(NEG))^1)

/*
 * Returns 1 if the given key state includes down on the d-pad but not up,
 * returns -1 if the given key state includes up on the d-pad but not down,
 * or returns 0 if the given key state includes both or neither.
 */
inline int tribool_dpad_vert(u16 key_state);

/*
 * Returns 1 if the given key state includes down on the d-pad but not up,
 * returns -1 if the given key state includes up on the d-pad but not down,
 * or returns 0 if the given key state includes both or neither.
 */
inline int tribool_dpad_horz(u16 key_state);

/*
 * Returns 1 if the given key state includes the R shoulder button but not L,
 * returns -1 if the given key state includes the L shoulder button but not R,
 * or returns 0 if the given key state includes both or neither.
 */
inline int tribool_shoulder(u16 key_state);

#endif // _input_h
