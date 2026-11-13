/**
 * @file my_error.h
 * @author Trung Duc Nguyen, Tim-Jonas Frenzel
 * @date 29.10.26
 * @brief Header file of module containing error definitions and error
 * conversion.
 */

#ifndef MY_ERROR_H
#define MY_ERROR_H

/*****************************************************************************************
 *  @brief      This define represents [Error Description].
 *
 *  @details    [Optional additional information about the error].
 *****************************************************************************************/
#define E_STACKOVERFLOW 1001

/*****************************************************************************************
 *  @brief      This define represents [Error Description].
 *
 *  @details    [Optional additional information about the error].
 *****************************************************************************************/
#define E_STACKUNDERFLOW 1002

/*****************************************************************************************
 *  @brief      This define represents [Error Description].
 *
 *  @details    [Optional additional information about the error].
 *****************************************************************************************/
#define E_DIVBYZERO 1003

/*****************************************************************************************
 *  @brief      This define represents [Error Description].
 *
 *  @details    [Optional additional information about the error].
 *****************************************************************************************/
#define E_INTOVERFLOW 1004

/*****************************************************************************************
 *  @brief      This function adds two Integers.
 *
 *  @param      value_1 First summand.
 *
 *  @return     POSIX API Compliant negative Error Code, else zero on success.
 ****************************************************************************************/
char *my_strerror(int);

#endif