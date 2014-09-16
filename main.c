/*****************************************************************************
 * Author: Eric Boyer
 * Arduino Car Alarm
 *****************************************************************************/

#include "error.h"
#include "arduino_io.h"

#include "morse.h"
#include "pins.h"
#include "alarm_ftns.h"

/* Ftn: Setup
 * Desc: put your setup code here, to run once */
void setup(void)
{
    initialize();
    resetAlarm();
}

/* Ftn: loop
 * Desc: put your main code here, to run repeatedly  */
void loop(void)
{
    loopRunner();
    delay(100);
}

