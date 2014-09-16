/*****************************************************************************
 *  Author: Eric Boyer
 *  Description: 
*****************************************************************************/

#ifndef MORSE_H
#define MORSE_H

// http://en.wikipedia.org/wiki/Morse_code#mediaviewer/File:International_Morse_Code.svg
#define MORSE_UNIT         75           // in milliseconds
#define MORSE_DOT          MORSE_UNIT   // Morse Code Dot
#define MORSE_DASH         3*MORSE_UNIT // Morse Code Dash
#define MORSE_PAUSE        MORSE_UNIT   // Space between parts of same letter
#define MORSE_LETTER_SPACE 3*MORSE_UNIT // Space between letters
#define MORSE_WORD_SPACE   7*MORSE_UNIT // Space between words

int morseSOS[] = {
    MORSE_DOT, MORSE_PAUSE, MORSE_DOT, MORSE_PAUSE, MORSE_DOT,
    MORSE_LETTER_SPACE,
    MORSE_DASH, MORSE_PAUSE, MORSE_DASH, MORSE_PAUSE, MORSE_DASH,
    MORSE_LETTER_SPACE,
    MORSE_DOT, MORSE_PAUSE, MORSE_DOT, MORSE_PAUSE, MORSE_DOT,
};

// Morse Code Letters - Do I need to actually include the letters?

#endif
