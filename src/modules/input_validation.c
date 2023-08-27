#include "./headers/input_validation.h"

bool isInputValid(const char *str) {
  if (str == NULL) return false;
  if (*str == 'e' || *str == ')' || *str == '.' || *str == '*' || *str == '/' ||
      *str == '^')
    return false;

  bool isValid = true;
  isValid = checkBrackets(str);
  for (const char *ptr = str; *ptr != '\0' && isValid; ++ptr) {
    if (!checkNeighbourOperators(ptr)) {
      isValid = false;
      break;
    }
    char currentSymbol = *ptr;
    if (strchr(ALLOWED_CHARRACTERS, currentSymbol) != NULL) {
      int qtySymbolsForSkip = handleSymbols(ptr);
      if (qtySymbolsForSkip)
        ptr += qtySymbolsForSkip - 1;
      else
        isValid = false;
    } else {
      isValid = false;
    }
  }

  return isValid;
}

int handleSymbols(const char *ptr) {
  int qtySymbolsForSkip = 0;
  char sliceForCkeck[7] = {0};
  strncat(sliceForCkeck, ptr, 6);
  switch (*ptr) {
    case ' ':
    case '(':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '0':
    case 'x':
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
      qtySymbolsForSkip = 1;
      break;
    case ')':
      if (*(ptr - 1) != '(') qtySymbolsForSkip = 1;
      break;
    case 's':
      if (strstr(sliceForCkeck, "sin(") && sliceForCkeck[4] != ')') {
        qtySymbolsForSkip = 4;
      } else if (strstr(sliceForCkeck, "sqrt(") && sliceForCkeck[5] != ')')
        qtySymbolsForSkip = 5;
      break;
    case 'c':
      if (strstr(sliceForCkeck, "cos(") && sliceForCkeck[4] != ')')
        qtySymbolsForSkip = 4;
      break;
    case 'a':
      if ((strstr(sliceForCkeck, "asin(") || strstr(sliceForCkeck, "acos(") ||
           strstr(sliceForCkeck, "atan(")) &&
          sliceForCkeck[5] != ')')
        qtySymbolsForSkip = 5;
      break;
    case 'l':
      if (strstr(sliceForCkeck, "ln(") && sliceForCkeck[3] != ')')
        qtySymbolsForSkip = 3;
      else if (strstr(sliceForCkeck, "log(") && sliceForCkeck[4] != ')')
        qtySymbolsForSkip = 4;
      break;
    case 'm':
      if (strstr(sliceForCkeck, "mod") && sliceForCkeck[3] != ')')
        qtySymbolsForSkip = 3;
      break;
    case 't':
      if (strstr(sliceForCkeck, "tan(") && sliceForCkeck[4] != ')')
        qtySymbolsForSkip = 4;
      break;
    case '.':
      qtySymbolsForSkip = checkValidDoubleAndReturnSize(ptr);
      break;
    case 'e':
      // TODO add check exponent
      qtySymbolsForSkip = 1;  // mock
      break;
    default:
      qtySymbolsForSkip = 0;
  }

  return qtySymbolsForSkip;
}

bool checkBrackets(const char *ptr) {
  lexemStack *bracketsStack = initStack();
  bool isValid = true;
  for (const char *current = ptr; *current != '\0'; ++current) {
    if (*current == ')') {
      if (isEmpty(bracketsStack)) {
        isValid = false;
        break;
      }
      pop(&bracketsStack);
    }
    if (*current == '(') push(&bracketsStack, "(");
  }
  if (!isEmpty(bracketsStack)) {
    isValid = false;
    removeStack(&bracketsStack);
  }
  free(bracketsStack);
  return isValid;
}

int checkValidDoubleAndReturnSize(const char *ptr) {
  int size = 1;
  ++ptr;
  while (isdigit(*ptr)) {
    ++ptr;
    ++size;
  }

  if ((*ptr == '.' || strchr(FUNCS, *ptr) != NULL || *ptr == '(' ||
       *ptr == 'e') &&
      *ptr != '\0') {
    size = 0;
  }

  return size;
}

int checkNeighbourOperators(const char *ptr) {
  return !(*(ptr + 1) != '\0' && strchr(OPERATORS, *ptr) != NULL &&
           strchr(OPERATORS, *(ptr + 1)) != NULL);
}