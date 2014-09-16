#include "alarm_ftns.h"

// This will hold the current state of the car
#DEFINE CAR_STATE UNLOCKED

static void setCarState(carState newState){
    CAR_STATE = newState;
}

static carState getCarState(void){
    return CAR_STATE;
}

static void soundAlarm(int * code, int pin){
    for(int i = 0; i < code.length(); i++){
        switch(code[i]){
            case MORSE_DOT:
            case MORSE_DASH:
                setPinHigh(pin);
                break;
            
            case MORSE_PAUSE:
            case MORSE_LETTER_SPACE:
            case MORSE_WORD_SPACE:
            default:
                setPinLow(pin);
                break;
        }
    }
    setPinLow(pin); // return to natural state (TODO: What if natural state is high)
}

static void playAlarm(void){
    if(getCarState() != ALARMING){
        setCarState(ALARMING);
        
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
   Desc: Reset (turn off) the alarm and set any pins back to their default state
*/
void resetAlarm(void){
    setCarState(UNLOCKED);
    
    // Set any other default states
    
    return;
}

int changeCarState(carState newState){
    setCarState(newState);
    if(getCarState() == newState){
        return SUCCESS;
    }
    return FAILURE;
}

void initialize(void){
    pinMode(ONBOARD_LED, OUTPUT);
}
