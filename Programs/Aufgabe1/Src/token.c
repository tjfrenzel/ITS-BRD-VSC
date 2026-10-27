#include "token.h"
#include "scanner.h"
#include "stack.h"

int process_token() {
    int error_code;
    T_token token = next_token();
    
    switch (token.tok){

        case NUMBER:
            push(token.val);
            break;
        case PLUS:
            error_code = add();
            break;
        case MINUS:
            error_code = subtract();
            break;
        case MULT:
            error_code = multiply();
            break;
        case DIV:
            error_code = divide();
            break;
        case PRT:
            error_code = prt_top();
            break;
        case PRT_ALL:
            error_code = prt_three();
            break;
        case CLEAR:
            clear();
            break;
        case DOUBLE:
            error_code = double_top();
            break;
        case SWAP:
            error_code = swap();
            break;
        default:
            break;
    }
    return error_code;
}