//==============================================================================
/*
    Initialization and main program logic

    Copyright 2014 by Cooper Johnson.

    This program is free software provided under the terms of the MIT License.
    It uses libgba, which is provided under the terms of the GNU LGPL v2 by the
    devkitpro project (http://sourceforge.net/projects/devkitpro).
*/
//==============================================================================

#include <gba.h>
#include <gba_types.h>
#include "demos.h"
#include "input.h"

static inline void libgba_init(void)
{
    //TODO
}

static inline void main_init(void)
{
    //TODO
}

int main(void)
{
    libgba_init();

    int selection = 0;
    bool needs_init = true;

    // this is how the demo selection will be laid out on screen
    const demo demos[NUM_DEMOS] =
    {
            demo1_main, demo2_main,
            demo3_main, demo4_main,
            demo5_main, demo6_main,
            demo7_main, demo8_main
    };

    for (;;)
    {
        if (needs_init)
        {
            main_init();
            needs_init = false;
        }

        u16 key_state = get_curr_keys();
        int tribool_horz = tribool_dpad_horz(key_state);
        int tribool_vert = tribool_dpad_vert(key_state);

        int horz = (selection + tribool_horz) & 1;
        int vert = (((selection >> 1) + tribool_vert) << 1) & (NUM_DEMOS - 1);

        selection = horz + vert;

        if (0)
        {
            demos[selection]();
            needs_init = true;
        }

        //TODO wait for vblank
    }

    // never actually get here; behavior after main returns is undefined on GBA
    return 0;
}

// safety placeholders for unimplemented demos
void demo1_main() { no_demo(); }
void demo2_main() { no_demo(); }
void demo3_main() { no_demo(); }
void demo4_main() { no_demo(); }
void demo5_main() { no_demo(); }
void demo6_main() { no_demo(); }
void demo7_main() { no_demo(); }
void demo8_main() { no_demo(); }
