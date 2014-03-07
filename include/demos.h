//==============================================================================
/*
    Header file for linking the various demos into main

    Copyright 2014 by Cooper Johnson.

    This program is free software provided under the terms of the MIT License.
    It uses libgba, which is provided under the terms of the GNU LGPL v2 by the
    devkitpro project (http://sourceforge.net/projects/devkitpro).
*/
//==============================================================================

#ifndef _demos_h
#define _demos_h

// 8 different demos are available
#define NUM_DEMOS (8)

// type "demo" is a pointer to a function that takes no args and returns void
typedef void (*demo)();

// each demo is activated by calling its "main" method
void demo1_main();
void demo2_main();
void demo3_main();
void demo4_main();
void demo5_main();
void demo6_main();
void demo7_main();
void demo8_main();

// a placeholder for unimplemented demos
static inline void no_demo() {}

#endif // _demos_h
