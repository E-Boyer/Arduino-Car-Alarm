
#include morse.h
//#include pins.h

#DEFINE HORN_PIN           ## // Pin that will supply power to horn relay.

// These are the enumerated states that the car can be in.
enum carState = {
    UNLOCKED,
    LOCKED,
    ARMED,
    ALARMING
};

// This will hold the current state of the car
#DEFINE CAR_STATE UNLOCKED

void soundAlarm(int * code){
    for(int i = 0; i < code.length(); i++){
        switch(code[i]){
            case MORSE_DOT:
            case MORSE_DASH:
                setPinHigh(HORN_PIN);
                break;
            
            case MORSE_PAUSE:
            case MORSE_LETTER_SPACE:
            case MORSE_WORD_SPACE:
            default:
                setPinLow(HORN_PIN);
                break;
        };
    }
    setPinLow(HORN_PIN);
}

while(running){
    if((getCarState() == ARMED) && (!DOOR_BUTTON)){
        // Do alarm stuff
        initAlarm()
    }
    else if(getCarState() == ALARMING){
        // Already alarming, what else do you want from me?
    }
}

void initAlarm(){
    if(getCarState() != ALARMING){
        setCarState(ALARMING);
        
        // start a timer so that it will only sound the alarm for XX seconds
        while(timer){
            soundAlarm(morseSOS);
        }
    }
    
    return;
}

void setCarState(carState newState){
    CAR_STATE = newState;
}

carState getCarState(){
    return CAR_STATE;
}