//==============================================================================
/*
    Implementation of functions defined in input.h

    Copyright 2014 by Cooper Johnson.

    This program is free software provided under the terms of the MIT License.
    It uses libgba, which is provided under the terms of the GNU LGPL v2 by the
    devkitpro project (http://sourceforge.net/projects/devkitpro).
*/
//==============================================================================

#include <gba_input.h>
#include "input.h"

static u16 curr_keys;
static u16 prev_keys;

inline void refresh_keys()
{
    prev_keys = curr_keys;
    curr_keys = ~REG_KEYINPUT;
}

inline u16 get_curr_keys()
{
    return curr_keys;
}

inline u16 get_prev_keys()
{
    return prev_keys;
}

inline int tribool_dpad_vert(u16 key_state)
{
    return TRIBOOL((key_state & KEY_DOWN), (key_state & KEY_UP));
}

inline int tribool_dpad_horz(u16 key_state)
{
    return TRIBOOL((key_state & KEY_RIGHT), (key_state & KEY_LEFT));
}

inline int tribool_shoulder(u16 key_state)
{
    return TRIBOOL((key_state & KEY_R), (key_state & KEY_L));
}
