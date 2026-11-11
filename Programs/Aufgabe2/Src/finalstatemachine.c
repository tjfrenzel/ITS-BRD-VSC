#include "timer.h"
#include "finalstatemachine.h"
#include "gpio.h"




void get_phase(){
    phase.timestamp = getTimeStamp();
    phase.old_phase = phase.new_phase; // Speichern der alten Phase

    if (!gpio_t.channel_a && !gpio_t.channel_b) {
        phase.new_phase = PHASE_A; // Phase a
    } else if (gpio_t.channel_a && !gpio_t.channel_b) {
        phase.new_phase = PHASE_B; // Phase b
    } else if (gpio_t.channel_a && gpio_t.channel_b) {
        phase.new_phase = PHASE_C; // Phase c
    } else if (!gpio_t.channel_a && gpio_t.channel_b) {
        phase.new_phase = PHASE_D; // Phase d
    }
}

int get_state() {
    int phase_diff = phase.new_phase - phase.old_phase;

    if (phase_diff == 1 || phase_diff == -3) {
        state.current_state = FORWARD; // Vorwärts
        phase.phase_counter++; // Erhöhe den Phasenzähler
        state.timestamp = phase.timestamp;

    } else if (phase_diff == -1 || phase_diff == 3) {
        state.current_state = BACKWARD; // Rückwärts
        phase.phase_counter--; // Verringere den Phasenzähler
        state.timestamp = phase.timestamp;

    } else if (phase_diff == 0) {
        state.current_state = NO_CHANGE; // Kein Richtungswechsel

    } else {
        state.error = ERROR; // Fehler
        return state.error;
    }
    return state.current_state;
}