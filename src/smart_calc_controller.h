#ifndef SMART_CALC_CONTROLLER_H
#define SMART_CALC_CONTROLLER_H

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#include "modules/headers/stack.h"
#include "modules/headers/calculate.h"
#include "modules/headers/creditCalc.h"
#include "modules/headers/from_infix_to_polish.h"
#include "modules/headers/input_validation.h"
#include "modules/headers/lexems_divider.h"

#define MAX_LEN 255
#define NUMBERS "12324567890"
#define ALLOWED_CHARRACTERS "1234567890()+-*/^qatlmgosrdcin.ex "
#define FUNCS "toaqslnrcgim"
#define OPERATORS "+-*/^"
#define BRACKETS "()"


/**
 * @file smart_calc_controller.h
 * @brief Header file containing API declarations for a smart calculator controller.
 */

/**
 * @brief Calculate the result of an expression provided as a string.
 *
 * This function takes an input string containing a mathematical expression
 * and calculates its result.
 *
 * @param str The input string containing the mathematical expression to be evaluated.
 * @param res Pointer to a variable where the calculated result will be stored.
 * @return int Return status. Zero indicates success, while a non-zero value
 * indicates an error.
 */
int apiForCalculateStr(const char *str, long double *res);

/**
 * @brief Perform a credit calculation using input data.
 *
 * This function takes input data for credit calculation and returns the
 * calculated output.
 *
 * @param data Pointer to the input data structure for credit calculation.
 * @return creditCalcOutput* Pointer to the calculated output structure.
 *                          The caller is responsible for managing memory associated with it.
 */
creditCalcOutput *apiForCreditCalc(creditCalcInput *data);

#endif // SMART_CALC_CONTROLLER_H
