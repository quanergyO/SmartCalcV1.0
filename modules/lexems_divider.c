#include "headers/lexems_divider.h"

char *lexemsDivider(const char *infix) {
  char *postfix = (char *)calloc(MAX_LEN * 2 + 1, sizeof(char));
  for (const char *ptr = infix; *ptr != '\0'; ++ptr) {
    char current = *ptr;
    char lexema[MAX_LEN] = "";
    int step = 0;
    if (strchr(NUMBERS, current)) {
      step = lenDouble(ptr) - 1;
      strncpy(lexema, ptr, step + 1);
    } else if (strchr(OPERATORS, current) || strchr("()", current) ||
               current == 'x') {
      if (!isOperatorUnary(ptr, infix)) {
        strncpy(lexema, ptr, 1);
      } else {
        if (*ptr == '-') {
          strcpy(lexema, "~");
        }
      }
    } else if (strchr(FUNCS, current) || *ptr == 'm') {
      step = handleFunctions(ptr) - 1;
      strncpy(lexema, ptr, step + 1);
    }
    ptr += step;
    strcat(postfix, lexema);
    strcat(postfix, " ");
  }

  return postfix;
}

int handleFunctions(const char *ptr) {
  int size = 0;
  char buffer[6] = "";
  strncat(buffer, ptr, 5);
  if (*ptr == 'a') {
    if (strstr(buffer, "asin") || strstr(buffer, "acos") ||
        strstr(buffer, "atan")) {
      size = 4;
    }
  } else if (*ptr == 'c') {
    if (strstr(buffer, "cos")) {
      size = 3;
    }
  } else if (*ptr == 'l') {
    if (strstr(buffer, "ln")) {
      size = 2;
    } else if (strstr(buffer, "log")) {
      size = 3;
    }
  } else if (*ptr == 'm') {
    if (strstr(buffer, "mod")) {
      size = 3;
    }
  } else if (*ptr == 's') {
    if (strstr(buffer, "sin")) {
      size = 3;
    } else if (strstr(buffer, "sqrt")) {
      size = 4;
    }
  } else if (*ptr == 't') {
    if (strstr(buffer, "tan")) {
      size = 3;
    }
  }

  return size;
}

int lenDouble(const char *ptr) {
  int len = 0;
  while (isdigit(*ptr)) {
    ++len;
    ++ptr;
  }
  if (*ptr == '.') {
    ++len;
    ++ptr;
    while (isdigit(*ptr)) {
      ++len;
      ++ptr;
    }
  }
  return len;
}

bool isOperatorUnary(const char *ptr, const char *src) {
  bool isUnary = false;
  if (*ptr == '-' || *ptr == '+') {
    if (ptr == src || *(ptr - 1) == '(' ||
        strchr(OPERATORS, *(ptr - 1)) != NULL) {
      isUnary = true;
    }
  }

  return isUnary;
}
