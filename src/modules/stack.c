#include "headers/stack.h"

lexemStack *initStack() {
  lexemStack *stack = (lexemStack *)malloc(sizeof(lexemStack));
  if (stack == NULL)
#ifdef DEBUG
  {
    fprintf(stderr, "Memory allocation error\n");
    exit(EXIT_FAILURE);
  }
#endif
  stack->next = NULL;
  stack->lexem = NULL;

  return stack;
}

bool isEmpty(lexemStack *stack) {
  bool isEmpty = false;
  if (stack->lexem == NULL) isEmpty = true;

  return isEmpty;
}

void push(lexemStack **stack, char *lexem) {
  lexemStack *tmp = (lexemStack *)malloc(sizeof(lexemStack));
#ifdef DEBUG
  if (tmp == NULL) {
    fprintf(stderr, "Memory allocation error\n");
    exit(EXIT_FAILURE);
  }
#endif
  tmp->lexem = lexem;
  tmp->next = *stack;
  *stack = tmp;
}

char *pop(lexemStack **stack) {
  lexemStack *tmp = *stack;
  *stack = (*stack)->next;
  char *value = tmp->lexem;
  free(tmp);

  return value;
}

char *peek(lexemStack *stack) {
#ifdef DEBUG
  if (isEmpty(stack)) {
    fprintf(stderr, "Stack is empty\n");
    exit(EXIT_FAILURE);
  }
#endif
  return stack->lexem;
}

void removeStack(lexemStack **stack) {
  while (!isEmpty(*stack)) {
    pop(stack);
  }
}

doubleStack *initDoubleStack() {
  doubleStack *stack = (doubleStack *)malloc(sizeof(doubleStack));
#ifdef DEBUG
  if (stack == NULL) {
    fprintf(stderr, "Memory allocation error\n");
    exit(EXIT_FAILURE);
  }
#endif
  stack->size = 0;
  stack->allocate = 10;
  stack->numbers = (long double *)calloc(stack->allocate, sizeof(long double));
#ifdef DEBUG
  if (stack->numbers == NULL) {
    fprintf(stderr, "Memory allocation error\n");
    exit(EXIT_FAILURE);
  }
#endif
  return stack;
}

void doubleStackPush(doubleStack *stack, long double number) {
  if (stack->size + 1 >= stack->allocate) {
    stack->allocate *= 2;
    stack->numbers = (long double *)realloc(
        stack->numbers, stack->allocate * sizeof(long double));
    if (stack->numbers == NULL) {
      fprintf(stderr, "Memory allocation error\n");
    }
  }
  stack->numbers[stack->size] = number;
  ++(stack->size);
}

long double doubleStackPop(doubleStack *stack) {
  --(stack->size);
  return stack->numbers[stack->size];
}

void removeDoubleStack(doubleStack *stack) { free(stack); }