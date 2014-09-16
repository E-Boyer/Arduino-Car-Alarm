#IFNDEF ALARM_FTNS_H
#DEFINE ALARM_FTNS_H

void alarmRunner(void);
void resetAlarm(void);

// These are the enumerated states that the car can be in.
enum carState {
    UNLOCKED, // 0
    LOCKED,
    ARMED,
    ALARMING
};

#ENDIF