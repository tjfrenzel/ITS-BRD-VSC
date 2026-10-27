/**
 * @file errorhandling.h
 * @brief Header file for error handling.
 */

#ifndef ERRORHANDLING_H
#define ERRORHANDLING_H

/*
 ****************************************************************************************
 * @brief : 
 * @return 
 ****************************************************************************************/
#define STACKOVERFLOW -2
#define STACKUNDERFLOW -3
#define EMPTYSTACK -4
#define NOTENOUGHTELEMENTS -5
#define INTEGEROVERFLOW -6
#define DIVISIONBYZERO -7

void process_error_code(int error_code);

#endif /* ERRORHANDLING_H */
// EOF