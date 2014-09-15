/*****************************************************************************
 * Author: Eric Boyer
 *****************************************************************************/
#include morse.h
#include pins.h

// These are the enumerated states that the car can be in.
enum carState = {
    UNLOCKED, // 0
    LOCKED,
    ARMED,
    ALARMING
};

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
        };
    }
    setPinLow(pin); // return to natural state (TODO: What if natural state is high)
}

void alarmRunner(void){
    while(1){
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
        };
    }
}

void playAlarm(void){
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
