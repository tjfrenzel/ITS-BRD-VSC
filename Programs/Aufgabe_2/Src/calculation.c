#include "calculation.h"
#include "timer.h"
#include <math.h>

void calculation_init(Calculation_t *calc, Decoder_t *decoder)
{
    calc->counter = decoder->counter;
    calc->timestamp = decoder->timestamp;
}

int calculate_angle(double * result, Decoder_t *decoder){
    
    double angle;

    angle = decoder->counter * DEGREE_PHASE_CHANGE;

    /* Winkel auf den Bereich 0 bis 360 begrenzen */
    angle = fmod(angle, DEGREE_MAX);

    if (angle < 0) {
        angle += DEGREE_MAX;
    }

    *result = angle;

    return 0;
}

int calculate_speed(double *result, Decoder_t *decoder, Calculation_t *calc){

    int32_t delta_counter;
    uint32_t delta_timestamp;
    double delta_angle;
    double delta_time;

    /* Erster Messpunkt: Noch keine Geschwindigkeit berechenbar */
    if (!decoder->initialized) {
        return -1;
    }

    //omega = delta phi/delta t
    delta_counter = (decoder->counter - calc->counter);

    delta_timestamp = decoder->timestamp - calc->timestamp;

    //kein gültiger Phasenwechsel erkannt
    if (delta_timestamp == 0) {
        return -1;
    }

    delta_angle = delta_counter * DEGREE_PHASE_CHANGE;

    /* Timer zählt mit 90 Ticks pro Mikrosekunde */
    delta_time = (double)delta_timestamp / TICKS_PER_US / US_TO_S;

    *result = delta_angle / delta_time;

    /* Aktuellen Messpunkt für die nächste Berechnung speichern */
    calc->counter = decoder->counter;
    calc->timestamp = decoder->timestamp;

    return 0;
}