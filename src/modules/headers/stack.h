#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * @file stack.h
 * @brief Header file containing declarations for two types of stacks: lexemStack and doubleStack.
 */

/**
 * @struct lexemStack
 * @brief A stack structure to hold lexems (strings).
 */
typedef struct lexemStack
{
    char *lexem;               /**< The lexem stored in the stack node. */
    struct lexemStack *next;   /**< Pointer to the next node in the stack. */
} lexemStack;

/**
 * @struct doubleStack
 * @brief A stack structure to hold long double values.
 */
typedef struct doubleStack
{
    long double* numbers;      /**< Array to store long double values. */
    int size;                  /**< Current number of elements in the stack. */
    int allocate;              /**< Total allocated size of the stack array. */
} doubleStack;

/**
 * @brief Initialize a lexem stack.
 * @return lexemStack* Pointer to the initialized lexem stack.
 */
lexemStack *initStack();

/**
 * @brief Check if a lexem stack is empty.
 * @param stack The lexem stack to check.
 * @return bool True if the stack is empty, false otherwise.
 */
bool isEmpty(lexemStack *stack);

/**
 * @brief Push a lexem onto the lexem stack.
 * @param stack Pointer to the lexem stack.
 * @param lexem The lexem to push onto the stack.
 */
void push(lexemStack **stack, char *lexem);

/**
 * @brief Peek at the top lexem in the stack without removing it.
 * @param stack The lexem stack to peek into.
 * @return char* Pointer to the top lexem in the stack.
 */
char *peek(lexemStack *stack);

/**
 * @brief Pop and remove the top lexem from the lexem stack.
 * @param stack Pointer to the lexem stack.
 * @return char* Pointer to the popped lexem.
 */
char *pop(lexemStack **stack);

/**
 * @brief Deallocate memory and remove a lexem stack.
 * @param stack Pointer to the lexem stack to be removed.
 */
void removeStack(lexemStack **stack);

/**
 * @brief Initialize a double stack.
 * @return doubleStack* Pointer to the initialized double stack.
 */
doubleStack* initDoubleStack();

/**
 * @brief Check if a double stack is empty.
 * @param stack The double stack to check.
 * @return bool True if the stack is empty, false otherwise.
 */
bool isDoubleStackEmpty(doubleStack* stack);

/**
 * @brief Push a long double value onto the double stack.
 * @param stack Pointer to the double stack.
 * @param number The value to push onto the stack.
 */
void doubleStackPush(doubleStack* stack, long double number);

/**
 * @brief Peek at the top value in the double stack without removing it.
 * @param stack The double stack to peek into.
 * @return long double The top value in the stack.
 */
long double doubleStackPeek(doubleStack* stack);

/**
 * @brief Pop and remove the top value from the double stack.
 * @param stack Pointer to the double stack.
 * @return long double The popped value.
 */
long double doubleStackPop(doubleStack* stack);

/**
 * @brief Deallocate memory and remove a double stack.
 * @param stack Pointer to the double stack to be removed.
 */
void removeDoubleStack(doubleStack* stack);

#endif // STACK_H
