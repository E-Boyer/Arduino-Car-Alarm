/*****************************************************************************
 * Author: Eric Boyer
 * Arduino_IO - This is a configuration file for the inputs and outputs of the
                Arduino Board.
******************************************************************************/

#IFNDEF ARDUINO_IO_H
#DEFINE ARDUINO_IO_H

#DEFINE ONBOARD_LED 13

typedef struct {
    bool enabled;  // Whether or not the pin is enabled
    int number;    // The number of the pin, This might now work for analog pins...
    string level;  // Pin level (HIGH and LOW)
    string ioType; // Input/Output Type (INPUT, INPUT_PULLUP-Reverses high & Low, and OUTPUT)
} Pin

// This table will hold all of the pin information 
Pin arduinoPins = [
    {false, 0, "LOW", "OUTPUT"},
    {false, 1, "LOW", "OUTPUT"}
    {false, 2, "LOW", "OUTPUT"}
    {false, 3, "LOW", "OUTPUT"}
    {false, 4, "LOW", "OUTPUT"}
    {false, 5, "LOW", "OUTPUT"}
    {false, 6, "LOW", "OUTPUT"}
    {false, 7, "LOW", "OUTPUT"}
    {false, 8, "LOW", "OUTPUT"}
    {false, 9, "LOW", "OUTPUT"}
    {false, 10, "LOW", "OUTPUT"}
    {false, 11, "LOW", "OUTPUT"}
    {false, 12, "LOW", "OUTPUT"}
];

#ENDIF
