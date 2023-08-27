#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/**
 * @file credit_calculator.h
 * @brief Header file containing structures and function declarations for credit calculations.
 */

/**
 * @enum creditType
 * @brief Enumeration defining the types of credit calculation methods.
 */
typedef enum creditType
{
    annuity,         /**< Annuity credit calculation type. */
    differentiated   /**< Differentiated credit calculation type. */
} creditType;

/**
 * @struct creditCalcInput
 * @brief Structure holding input data for credit calculations.
 */
typedef struct creditCalcInput
{
    const char *total_loan_amount; /**< String representing the total loan amount. */
    const char *term;              /**< String representing the loan term. */
    const char *interest_rate;     /**< String representing the interest rate. */
    creditType type;               /**< Type of credit calculation to be performed. */
} creditCalcInput;

/**
 * @struct creditCalcOutput
 * @brief Structure holding output data from credit calculations.
 */
typedef struct creditCalcOutput
{
    char *monthly_payment;   /**< String representing the calculated monthly payment. */
    char *loan_overpayment;  /**< String representing the total overpayment on the loan. */
    char *total_repayment;    /**< String representing the total repayment amount. */
} creditCalcOutput;

/**
 * @brief Perform annuity credit calculation based on input data.
 *
 * This function calculates annuity credit using the provided input data.
 *
 * @param data Pointer to the input data structure for credit calculation.
 * @return creditCalcOutput* Pointer to the calculated output structure.
 *                          The caller is responsible for managing memory associated with it.
 */
creditCalcOutput* annuity_credit(const creditCalcInput *data);

/**
 * @brief Perform differentiated credit calculation based on input data.
 *
 * This function calculates differentiated credit using the provided input data.
 *
 * @param data Pointer to the input data structure for credit calculation.
 * @return creditCalcOutput* Pointer to the calculated output structure.
 *                          The caller is responsible for managing memory associated with it.
 */
creditCalcOutput* differentiated_credit(const creditCalcInput *data);

/**
 * @brief Free memory associated with a creditCalcOutput structure.
 *
 * This function deallocates memory associated with a creditCalcOutput structure.
 *
 * @param data Pointer to the creditCalcOutput structure to be freed.
 */
void freeCreditCalcOutput(creditCalcOutput *data);

#endif // CREDIT_CALCULATOR_H
