#include "headers/from_infix_to_polish.h"

char *fromInfixToPostfix(char *infix) {
  char *postfix = (char *)calloc(MAX_LEN * 2 + 1, sizeof(char));
#ifdef DEBUG
  if (postfix == NULL) {
    fprintf(stderr, "Memory allocation error\n");
    exit(EXIT_FAILURE);
  }
#endif
  lexemStack *stack = initStack();
  char *ptr = strtok(infix, " ");
  while (ptr != NULL) {
    dijkstraRunner(ptr, postfix, &stack);
    ptr = strtok(NULL, " ");
  }
  while (!isEmpty(stack)) {
    strcat(postfix, pop(&stack));
    strcat(postfix, " ");
  }

  return postfix;
}

void dijkstraRunner(char *lexema, char *postfix, lexemStack **stack) {
  if (strchr(NUMBERS, *lexema) != NULL || *lexema == '~' || *lexema == 'x') {
    strcat(postfix, lexema);
    strcat(postfix, " ");
  } else if (strchr(OPERATORS, *lexema) != NULL || strchr(FUNCS, *lexema)) {
    if (!isEmpty(*stack)) {
      int curPriority = getPriority(*lexema);
      char prevOper = *(peek(*stack));
      int prevPriority = getPriority(prevOper);
      while (prevPriority >= curPriority) {
        strcat(postfix, pop(stack));
        strcat(postfix, " ");
        if (isEmpty(*stack)) break;
        prevOper = *(peek(*stack));
        prevPriority = getPriority(prevOper);
      }
    }
    push(stack, lexema);
  } else if (*lexema == '(') {
    push(stack, lexema);
  } else if (*lexema == ')') {
    char prevOper = *(peek(*stack));
    while (prevOper != '(') {
      strcat(postfix, pop(stack));
      strcat(postfix, " ");
      prevOper = *(peek(*stack));
    }
    pop(stack);
  }
}

int getPriority(char oper) {
  int priority = 0;
  switch (oper) {
    case '-':
    case '+':
      priority = 1;
      break;
    case '*':
    case '/':
    case '%':
      priority = 2;
      break;
    case '^':
      priority = 3;
      break;
    case '(':
      priority = 0;
      break;
  }
  if (strchr(FUNCS, oper) != NULL) priority = 4;

  return priority;
}
