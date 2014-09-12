
// http://en.wikipedia.org/wiki/Morse_code#mediaviewer/File:International_Morse_Code.svg
#DEFINE MORSE_UNIT         75           // in milliseconds
#DEFINE MORSE_DOT          MORSE_UNIT   // Morse Code Dot
#DEFINE MORSE_DASH         3*MORSE_UNIT // Morse Code Dash
#DEFINE MORSE_PAUSE        MORSE_UNIT   // Space between parts of same letter
#DEFINE MORSE_LETTER_SPACE 3*MORSE_UNIT // Space between letters
#DEFINE MORSE_WORD_SPACE   7*MORSE_UNIT // Space between words

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

int morseSOS[] = {
    MORSE_DOT, MORSE_PAUSE, MORSE_DOT, MORSE_PAUSE, MORSE_DOT,
    MORSE_LETTER_SPACE,
    MORSE_DASH, MORSE_PAUSE, MORSE_DASH, MORSE_PAUSE, MORSE_DASH,
    MORSE_LETTER_SPACE,
    MORSE_DOT, MORSE_PAUSE, MORSE_DOT, MORSE_PAUSE, MORSE_DOT,
};

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