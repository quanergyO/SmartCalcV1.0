#ifndef FROM_INFIX_TO_POSTFIX_H
#define FROM_INFIX_TO_POSTFIX_H

#include "../../smart_calc_controller.h"

/**
 * @file from_infix_to_postfix.h
 * @brief Header file containing declarations for functions related to converting infix expressions to postfix.
 */

/**
 * @brief Convert an infix expression to a postfix expression.
 *
 * This function takes an infix expression in the form of a string and converts it to a postfix expression.
 * The resulting postfix expression is returned as a dynamically allocated string.
 *
 * @param infix The input infix expression string.
 * @return char* Pointer to the dynamically allocated string containing the postfix expression.
 *               The caller is responsible for managing memory associated with it.
 */
char *fromInfixToPostfix(char *infix);

/**
 * @brief Run Dijkstra's shunting-yard algorithm for converting infix to postfix.
 *
 * This function processes a lexem during the infix to postfix conversion using Dijkstra's algorithm.
 *
 * @param lexema The lexem being processed.
 * @param postfix The current postfix expression being built.
 * @param stack Pointer to the lexem stack used in the algorithm.
 */
void dijkstraRunner(char *lexema, char *postfix, lexemStack **stack);

/**
 * @brief Get the priority of an operator.
 *
 * This function determines the priority of an operator for the purpose of infix to postfix conversion.
 *
 * @param oper The operator whose priority is to be determined.
 * @return int The priority value of the operator.
 */
int getPriority(char oper);

#endif // FROM_INFIX_TO_POSTFIX_H
