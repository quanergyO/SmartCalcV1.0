#ifndef LEXEM_DIVIDER_H
#define LEXEM_DIVIDER_H

#include "../../smart_calc_controller.h"

#include "stack.h"

/**
 * @file lexem_divider.h
 * @brief Header file containing declarations for functions related to dividing input strings into lexems.
 */

/**
 * @brief Divide an input string into lexems.
 *
 * This function takes an input string and processes it to divide it into individual lexems.
 * The resulting lexems are returned as a dynamically allocated string.
 *
 * @param str The input string to be divided into lexems.
 * @return char* Pointer to the dynamically allocated string containing the divided lexems.
 *               The caller is responsible for managing memory associated with it.
 */
char *lexemsDivider(const char *str);

/**
 * @brief Parse a double value from a string.
 *
 * This function parses a double value from the given string starting at the specified index.
 *
 * @param ptr Pointer to the input string.
 * @param index Pointer to the index indicating the starting position for parsing.
 * @return double The parsed double value.
 */
double parseDouble(char *ptr, int *index);

/**
 * @brief Calculate the length of a double value in a string.
 *
 * This function calculates the length of a double value starting from the given pointer.
 *
 * @param ptr Pointer to the input string.
 * @return int The length of the double value.
 */
int lenDouble(const char *ptr);

/**
 * @brief Handle functions in the input string.
 *
 * This function checks if a given substring in the input string matches any known function.
 *
 * @param ptr Pointer to the input string.
 * @return int The length of the matched function string, or 0 if no match is found.
 */
int handleFunctions(const char *ptr);

/**
 * @brief Check if an operator is unary in a specific context.
 *
 * This function determines if a specific operator is a unary operator based on its position
 * in the input string.
 *
 * @param ptr Pointer to the input string.
 * @param src Pointer to the original source string for reference.
 * @return bool True if the operator is unary in this context, false otherwise.
 */
bool isOperatorUnary(const char *ptr, const char *src);

#endif // LEXEM_DIVIDER_H
