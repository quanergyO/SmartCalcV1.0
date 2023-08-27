#include "headers/calculate.h"

long double calculate(char *str) {
  long double result = 0;
  bool isUnary = false;
  doubleStack *stack = initDoubleStack();
  char *token = strtok(str, " ");
  while (token != NULL) {
    tokenHandler(token, &stack, &isUnary);
    token = strtok(NULL, " ");
  }
  result = doubleStackPop(stack);
  removeDoubleStack(stack);

  return result;
}

void tokenHandler(char *token, doubleStack **stack, bool *isUnary) {
  if (strchr(NUMBERS, *token) != NULL) {
    long double num = atof(token);
    if (*isUnary == true) {
      num *= -1;
      *isUnary = false;
    }
    doubleStackPush(*stack, num);
  } else if (*token == '~') {
    *isUnary = *isUnary ? false : true;
  } else if (strchr(OPERATORS, *token) != NULL || *token == 'm') {
    long double num1 = doubleStackPop(*stack);
    long double num2 = doubleStackPop(*stack);
    long double res = operatorsHandler(*token, num2, num1);
    doubleStackPush(*stack, res);
  } else if (strchr(FUNCS, *token) != NULL) {
    long double num = doubleStackPop(*stack);
    long double res = functionsHandler(token, num);
    doubleStackPush(*stack, res);
  }
}

long double operatorsHandler(char oper, long double num1, long double num2) {
  long double res = 0;
  switch (oper) {
    case '+':
      res = num1 + num2;
      break;
    case '-':
      res = num1 - num2;
      break;
    case '*':
      res = num1 * num2;
      break;
    case '/':
      res = num1 / num2;
      // TODO check zero
      break;
    case 'm':
      res = (int)num1 % (int)num2;
      break;
    case '^':
      res = pow(num1, num2);
      break;
  }

  return res;
}

long double functionsHandler(char *oper, long double num) {
  long double res = 0;
  if (!strcmp(oper, "sin")) {
    num = num * M_PI / 180;
    res = sinl(num);
  } else if (!strcmp(oper, "cos")) {
    num = num * M_PI / 180;
    res = cosl(num);
  } else if (!strcmp(oper, "sqrt")) {
    res = sqrtl(num);
  } else if (!strcmp(oper, "asin")) {
    res = asinl(num) * 180.0 / M_PI;
  } else if (!strcmp(oper, "acos")) {
    res = acosl(num) * 180.0 / M_PI;
  } else if (!strcmp(oper, "atan")) {
    res = atanl(num) * 180.0 / M_PI;
  } else if (!strcmp(oper, "ln")) {
    res = logl(num);
  } else if (!strcmp(oper, "log")) {
    res = log10l(num);
  } else if (!strcmp(oper, "tan")) {
    num = num * M_PI / 180;
    res = tanl(num);
  }

  return res;
}

long double calculateWithX(char *str, double x) {
  char cpy_str[255];
  strcpy(cpy_str, str);
  long double result = 0;
  bool isUnary = false;
  doubleStack *stack = initDoubleStack();
  char *token = strtok(cpy_str, " ");
  while (token != NULL) {
    tokenHandlerWithX(token, &stack, &isUnary, x);
    token = strtok(NULL, " ");
  }
  result = doubleStackPop(stack);

  return result;
}

void tokenHandlerWithX(char *token, doubleStack **stack, bool *isUnary,
                       double x) {
  if (token[0] == 'x') {
    doubleStackPush(*stack, x);
  } else if (strchr(NUMBERS, *token) != NULL) {
    long double num = atof(token);
    if (*isUnary == true) {
      num *= -1;
      *isUnary = false;
    }
    doubleStackPush(*stack, num);
  } else if (*token == '~') {
    *isUnary = true;
  } else if (strchr(OPERATORS, *token) != NULL || *token == 'm') {
    long double num1 = doubleStackPop(*stack);
    long double num2 = doubleStackPop(*stack);
    long double res = operatorsHandler(*token, num2, num1);
    doubleStackPush(*stack, res);
  } else if (strchr(FUNCS, *token) != NULL) {
    long double num = doubleStackPop(*stack);
    long double res = functionsHandlerWithX(token, num);
    doubleStackPush(*stack, res);
  }
}

long double functionsHandlerWithX(char *oper, long double num) {
  long double res = 0;
  if (!strcmp(oper, "sin")) {
    res = sinl(num);
  } else if (!strcmp(oper, "cos")) {
    res = cosl(num);
  } else if (!strcmp(oper, "sqrt")) {
    res = sqrtl(num);
  } else if (!strcmp(oper, "asin")) {
    res = asinl(num);
  } else if (!strcmp(oper, "acos")) {
    res = acosl(num);
  } else if (!strcmp(oper, "atan")) {
    res = atanl(num);
  } else if (!strcmp(oper, "ln")) {
    res = logl(num);
  } else if (!strcmp(oper, "log")) {
    res = log10l(num);
  } else if (!strcmp(oper, "tan")) {
    res = tanl(num);
  }

  return res;
}
