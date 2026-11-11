/**
 * @file finalstatemachine.h
 * @brief Header file for the final state machine.
 */

#ifndef FINALSTATEMACHINE_H
#define FINALSTATEMACHINE_H

#include <stdint.h>
#include <stdbool.h>

#define PHASE_A 1
#define PHASE_B 2
#define PHASE_C 3
#define PHASE_D 4

#define ERROR -1
#define NO_CHANGE 5
#define FORWARD 6
#define BACKWARD 7

/*
 ****************************************************************************************
 * @brief :
 * @return
 ****************************************************************************************/
typedef struct {
    int new_phase;
    int old_phase;
    int phase_counter;
    uint32_t timestamp;
} Phase;
extern Phase phase;

 typedef struct {
    int current_state;
    int error;
    uint32_t timestamp;
} State;
extern State state;

void get_phase(void);
int get_state(void);

#endif /* FINALSTATEMACHINE_H */
       // EOF   