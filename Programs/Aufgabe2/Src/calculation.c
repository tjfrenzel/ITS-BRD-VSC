#include "calculation.h"
#include "finalstatemachine.h"

double get_angle(){
        return phase.phase_counter * DEGREES_PER_COUNT;
}