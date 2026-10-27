#include <stdint.h>
#include "stack.h"
#include "errorhandling.h"

int add(){
    int a;
    int b;

    error_code = pop(&a);
    if (error_code != 0) {
        return error_code;
    }

    error_code = pop(&b);
    if (error_code != 0) {
        push(a);
        return error_code;
    }

    if ((b > 0 && a > INTMAX_MAX - b) || (b < 0 && a < INTMAX_MIN - b)) {
        push(b);
        push(a);
        return INTEGEROVERFLOW;
    }

    push(b + a);
    return 0;
}

int subtract(){
    int a;
    int b;

    error_code = pop(&a);
    if (error_code != 0) {
        return error_code;
    }

    error_code = pop(&b);
    if (error_code != 0) {
        push(a);
        return error_code;
    }

    if ((b > 0 && -a < INTMAX_MIN + b) || (b < 0 && -a > INTMAX_MAX + b)) {
        push(b);
        push(a);
        return INTEGEROVERFLOW;
    }
    
    push(b - a);
    return 0;
}

int multiply(){
    int a;
    int b;

    error_code = pop(&a);
    if (error_code != 0) {
        return error_code;
    }

    error_code = pop(&b);
    if (error_code != 0) {
        push(a);
        return error_code;
    }

    // positives Ergebnis
    if ((a > 0 && b > 0)) {
        if (a > INTMAX_MAX / b) goto overflow;
    }

    // negatives Ergebnis (beide negativ → positiv)
    if ((a < 0 && b < 0)) {
        if (a < INTMAX_MAX / b) goto overflow;
    }

    // gemischte Vorzeichen → negativ
    if ((a > 0 && b < 0)) {
        if (b < INTMAX_MIN / a) goto overflow;
    }

    if ((a < 0 && b > 0)) {
        if (a < INTMAX_MIN / b) goto overflow;
    }

    push(a * b);
    return 0;

    overflow:
    push(b);
    push(a);
    return INTEGEROVERFLOW;
}

int divide(){
    int a;
    int b;

    error_code = pop(&a);
    if (error_code != 0) {
        return error_code;
    }

    error_code = pop(&b);
    if (error_code != 0) {
        push(a);
        return error_code;
    }

    if (a == 0) {
        push(b);
        push(a);
        return DIVISIONBYZERO;
    }
        
    push(b / a);
    return 0;
}