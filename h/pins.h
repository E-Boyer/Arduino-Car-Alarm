/*****************************************************************************
 * Car-Alarm Pin Definitions File
 * Author: Eric Boyer
******************************************************************************/
#ifndef PINS_H
#define PINS_H

#define HORN_PIN ONBOARD_LED // Pin that will supply power to horn relay.

#define FL_DOOR ## // Driver Side Front Door
#define FR_DOOR ## // Passenger Side Front Door
#define RL_DOOR ## // Driver Side Rear Door
#define RR_DOOR ## // Passenger Side Rear Door

#ifdef ELECTRONIC_LOCKS
#define UNLOCK_PIN ## // Pin number that will unlock the car
#define LOCK_PIN   ## // Pin number to lock the car
#endif

#endif
