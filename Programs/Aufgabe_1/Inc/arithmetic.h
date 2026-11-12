/**
 * @file arithmetic.h
 * @author Trung Duc Nguyen, Tim-Jonas Frenzel
 * @date 29.10.26
 * @brief Header file of module containing basic arithmetic operations.
 */

#ifndef ARITHMETIC_H
#define ARITHMETIC_H

/*****************************************************************************************
 *  @brief      This function adds two Integers.
 *
 *  @param      value_1 First summand.
 *  @param      value_2 Second summand.
 *  @param      result  Integer Pointer for Result.
 *
 *  @return     POSIX API Compliant negative Error Code, else zero on success.
 ****************************************************************************************/
int add(int value_1, int value_2, int *result);

/*****************************************************************************************
 *  @brief      This function subtracts the second Integer from the first.
 *
 *  @param      value_1 Minuend.
 *  @param      value_2 Subtrahend.
 *  @param      result  Integer Pointer for Result.
 *
 *  @return     POSIX API Compliant negative Error Code, else zero on success.
 ****************************************************************************************/
int subtract(int, int, int *);

/*****************************************************************************************
 *  @brief      This function multiplies two Integers.
 *
 *  @param      value_1 First factor.
 *  @param      value_2 Second factor.
 *  @param      result  Integer Pointer for Result.
 *
 *  @return     POSIX API Compliant negative Error Code, else zero on success.
 ****************************************************************************************/
int multiply(int, int, int *);

/*****************************************************************************************
 *  @brief      This function divides the first Integer by the second.
 *
 *  @param      value_1 Dividend.
 *  @param      value_2 Divisor.
 *  @param      result  Integer Pointer for Result.
 *
 *  @return     POSIX API Compliant negative Error Code, else zero on success.
 ****************************************************************************************/
int divide(int, int, int *);

#endif