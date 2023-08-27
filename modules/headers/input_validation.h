#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include "../../smart_calc_controller.h"

/**
 * @file input_validation.h
 * @brief Header file containing declarations for functions related to input validation.
 */

/**
 * @brief Check if an input string is valid.
 *
 * This function checks if the given input string is valid according to specified criteria.
 *
 * @param str The input string to be validated.
 * @return bool True if the input is valid, false otherwise.
 */
bool isInputValid(const char *str);

/**
 * @brief Handle special symbols in the input string.
 *
 * This function processes a substring of the input string and identifies any special symbols.
 *
 * @param ptr Pointer to the input string.
 * @return int The length of the identified special symbol, or 0 if none is found.
 */
int handleSymbols(const char *ptr);

/**
 * @brief Check if brackets in the input string are balanced.
 *
 * This function checks if the brackets in the input string are properly balanced.
 *
 * @param ptr Pointer to the input string.
 * @return bool True if brackets are balanced, false otherwise.
 */
bool checkBrackets(const char *ptr);

/**
 * @brief Check for a valid double value in the input string and return its length.
 *
 * This function attempts to find a valid double value in the input string starting from the given pointer.
 * It returns the length of the valid double value if found, or 0 if not.
 *
 * @param ptr Pointer to the input string.
 * @return int Length of the valid double value, or 0 if not found.
 */
int checkValidDoubleAndReturnSize(const char *ptr);

/**
 * @brief Check the neighboring operators around a given character pointer.
 *
 * This function analyzes the operators surrounding a character pointer to determine
 * the context in which it appears.
 *
 * @param ptr A pointer to the character to be analyzed.
 * @return An integer representing the context of the character:
 *         -1 if the character is surrounded by incompatible operators.
 *          0 if the character is not surrounded by operators.
 *          1 if the character is surrounded by compatible operators.
 *
 * @note This function assumes that the input character pointer is pointing to a valid location
 *       within a null-terminated string.
 *
 * @warning The behavior is undefined if the input pointer does not point to a valid character
 *          within the string.
 *
 * @see isValidOperator
 */
int checkNeighbourOperators(const char *ptr);

#endif // INPUT_VALIDATION_H
