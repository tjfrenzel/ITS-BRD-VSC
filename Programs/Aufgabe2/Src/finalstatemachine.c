#include "timer.h"
#include "finalstatemachine.h"

typedef struct {
    int new_phase;
    int old_phase;
    int phase_counter;

    uint32_t timestamp;
} Phase;

typedef struct {
    int current_state;
    uint32_t timestamp;
} State;

static Phase phase;
static State state;
#include "stdbool.h"
bool channel_a;
bool channel_b;

void get_phase(){
    phase.timestamp = getTimeStamp();
    phase.old_phase = phase.new_phase; // Speichern der alten Phase

    if (!channel_a && !channel_b) {
        phase.new_phase = PHASE_A; // Phase a
    } else if (channel_a && !channel_b) {
        phase.new_phase = PHASE_B; // Phase b
    } else if (channel_a && channel_b) {
        phase.new_phase = PHASE_C; // Phase c
    } else if (!channel_a && channel_b) {
        phase.new_phase = PHASE_D; // Phase d
    }
}

int get_state() {
    int phase_diff = phase.new_phase - phase.old_phase;

    if (phase_diff == 1 || phase_diff == -3) {
        state.current_state = FORWARD; // Vorwärts
        phase.phase_counter++; // Erhöhe den Phasenzähler
    } else if (phase_diff == -1 || phase_diff == 3) {
        state.current_state = BACKWARD; // Rückwärts
        phase.phase_counter--; // Verringere den Phasenzähler
    } else if (phase_diff == 0) {
        state.current_state = NO_CHANGE; // Kein Richtungswechsel
    } else {
        state.current_state = ERROR; // Fehler
    }
    state.timestamp = phase.timestamp;
    return state.current_state;
}