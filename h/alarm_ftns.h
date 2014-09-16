#ifndef ALARM_FTNS_H
#define ALARM_FTNS_H

// Definition to be used if the Arduino board is integrated into the car's electronic locks
#define ELECTRONIC_LOCKS


void alarmRunner(void);
void resetAlarm(void);

// These are the enumerated states that the car can be in.
enum carState {
    UNLOCKED, // 0
    LOCKED,
    ARMED,
    ALARMING
};

void loopRunner(void);
void resetAlarm(void);

enum returnCode changeCarState(enum carState newState);
void initialize(void);
void unlock(void);
void lock(void);
void arm(void);

#endif