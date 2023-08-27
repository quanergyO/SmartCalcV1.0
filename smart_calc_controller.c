#include "smart_calc_controller.h"

int apiForCalculateStr(const char *str, long double *res) {
  if (!str || !res) return EXIT_FAILURE;

  *res = 0;
  char inputStr[MAX_LEN + 1] = {0};

  for (int i = 0; str[i]; i++) {
    inputStr[i] = tolower(str[i]);
  }
  bool isValid = isInputValid(inputStr);
  if (isValid) {
    char *strDivided = lexemsDivider(inputStr);
    char *postfix = fromInfixToPostfix(strDivided);
    free(strDivided);
    *res = calculate(postfix);
  }

  return isValid;
}

creditCalcOutput *apiForCreditCalc(creditCalcInput *data) {
  creditCalcOutput *output = NULL;
  if (data->type == annuity) {
    output = annuity_credit(data);
  } else if (data->type == differentiated) {
    output = differentiated_credit(data);
  }
  return output;
}
