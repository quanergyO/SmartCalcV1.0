#ifndef CALCULATE_H
#define CALCULATE_H

#include "../../smart_calc_controller.h"

/**
 * @file calculate.h
 * @brief Header file containing declarations for functions related to mathematical calculations.
 */

/**
 * @brief Perform a calculation on the provided input string.
 *
 * This function evaluates a mathematical expression represented by the input string.
 *
 * @param str The input string containing the mathematical expression.
 * @return long double The result of the mathematical calculation.
 */
long double calculate(char *str);

/**
 * @brief Process a token in the calculation.
 *
 * This function handles a token during the calculation process, updating the stack and unary state.
 *
 * @param token The current token being processed.
 * @param stack Pointer to the stack of double values.
 * @param isUnary Pointer indicating whether the token represents a unary operator.
 */
void tokenHandler(char* token, doubleStack** stack, bool* isUnary);

/**
 * @brief Handle binary operators during calculation.
 *
 * This function performs calculations using binary operators and operands.
 *
 * @param oper The binary operator.
 * @param num1 The first operand.
 * @param num2 The second operand.
 * @return long double The result of the operation.
 */
long double operatorsHandler(char oper, long double num1, long double num2);

/**
 * @brief Handle functions during calculation.
 *
 * This function performs calculations using mathematical functions and an operand.
 *
 * @param oper The function/operator.
 * @param num The operand.
 * @return long double The result of the operation.
 */
long double functionsHandler(char* oper, long double num);

/**
 * @brief Perform a calculation on the provided input string with a given value for x.
 *
 * This function evaluates a mathematical expression represented by the input string, using the provided x value.
 *
 * @param str The input string containing the mathematical expression.
 * @param x The value for the variable x.
 * @return long double The result of the mathematical calculation with the given x value.
 */
long double calculateWithX(char *str, double x);

/**
 * @brief Process a token in the calculation with a given value for x.
 *
 * This function handles a token during the calculation process, updating the stack, unary state, and using the provided x value.
 *
 * @param token The current token being processed.
 * @param stack Pointer to the stack of double values.
 * @param isUnary Pointer indicating whether the token represents a unary operator.
 * @param x The value for the variable x.
 */
void tokenHandlerWithX(char *token, doubleStack **stack, bool *isUnary, double x);

/**
 * @brief Handle functions during calculation with a given value for x.
 *
 * This function performs calculations using mathematical functions and an operand, considering the provided x value.
 *
 * @param oper The function/operator.
 * @param num The operand.
 * @return long double The result of the operation.
 */
long double functionsHandlerWithX(char *oper, long double num);

#endif // CALCULATE_H
