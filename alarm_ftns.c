#include "alarm_ftns.h"
#include "error.h"

// This will hold the current state of the car
enum carState CAR_STATE = UNLOCKED;

// Set a new state of the car
static void setCarState(enum carState newState){
    CAR_STATE = newState;
}

// Get the current state of the car
static enum carState getCarState(void){
    return CAR_STATE;
}

// This function actually sends power to the specified pin in morse code form
static void soundAlarm(int * code, int pin){
    for(int i = 0; i < code.length(); i++){
        if(getCarState() == ALARMING){
            switch(code[i]){
                case MORSE_DOT:
                case MORSE_DASH:
                    setPinHigh(pin, "HIGH");
                    break;
                
                case MORSE_PAUSE:
                case MORSE_LETTER_SPACE:
                case MORSE_WORD_SPACE:
                default:
                    setPin(pin, "LOW");
                    break;
            }
        }
    }
    setPinLow(pin, "LOW"); // return to natural state (TODO: What if natural state is high)
}

static void playAlarm(void){
    if(getCarState() != ALARMING){
        changeCarState(ALARMING);
        
        // start a timer so that it will only sound the alarm for XX seconds
        while(timer){
            soundAlarm(morseSOS, HORN_PIN);
            // sleep for 2 seconds?
        }
    }
    
    return;
}

// This loop runs forever (or until the arduino catches fire).
void loopRunner(void){
    // if (reset_btn || reset_cmd) // reset the alarm
    switch(getCarState()){
        case UNLOCKED:
        case default:
            // Do nothing
            break;
        case LOCKED:
            break;
        case ARMED:
            if(!DOOR_BUTTON){
                playAlarm(); // Do Alarm Stuff
            }
            break;
        case ALARMING:
            // Already alarming, what else do you want from me?
            break;
    }
    return;
}

/* resetAlarm
 * Desc: Reset (turn off) the alarm and set any pins back to their default state
 */
void resetAlarm(void){
    changeCarState(UNLOCKED);
    
    // Set any other default states
    
    return;
}

enum returnCode changeCarState(enum carState newState){
    setCarState(newState);
    if(getCarState() == newState){
        return SUCCESS;
    }
    return FAILURE;
}

/* initialize
 * Initialize the car alarm features/functions 
 */
void initialize(void){
    pinMode(ONBOARD_LED, OUTPUT);
}

/* unlock
 * Function called whenever the car is unlocked 
 */
void unlock(void){
    changeCarState(UNLOCKED);
}

/* lock
 * Function called whenever the car is locked (not armed) 
 */
void lock(void){
    changeCarState(LOCKED);
#ifdef ELECTRONIC_LOCKS
    // Send signal to car's electronic lock.
#endif
}

/* Arm
 * Function called whenever the car alarm is armed. 
 */
void arm(void){
    lock(); // Lock the car
    changeCarState(ARMED);
}
