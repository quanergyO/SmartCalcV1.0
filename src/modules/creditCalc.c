#include "headers/creditCalc.h"

creditCalcOutput *annuity_credit(const creditCalcInput *data) {
  creditCalcOutput *output =
      (creditCalcOutput *)malloc(sizeof(creditCalcOutput));
  // TODO check is malloc
  double total_loan_amount = atof(data->total_loan_amount);
  double term = atof(data->term) * 12;
  double interest_rate = atof(data->interest_rate) / 12 / 100;
  double monthly_payment =
      (total_loan_amount * interest_rate * pow(1 + interest_rate, term)) /
      (pow(1 + interest_rate, term) - 1);
  double total_repayment = monthly_payment * term;
  double loan_overpayment = total_repayment - total_loan_amount;
  output->monthly_payment = (char *)malloc(sizeof(char) * 128);
  output->loan_overpayment = (char *)malloc(sizeof(char) * 128);
  output->total_repayment = (char *)malloc(sizeof(char) * 128);
  sprintf(output->monthly_payment, "%.2lf", monthly_payment);
  sprintf(output->total_repayment, "%.2lf", total_repayment);
  sprintf(output->loan_overpayment, "%.2lf", loan_overpayment);

  return output;
}

creditCalcOutput *differentiated_credit(const creditCalcInput *data) {
  creditCalcOutput *output =
      (creditCalcOutput *)malloc(sizeof(creditCalcOutput));
  double interest_rate = atof(data->interest_rate) / 12 / 100;
  double total_loan_amount = atof(data->total_loan_amount);
  int term = atof(data->term) * 12;
  double monthly_payment[term];
  double total_repayment = 0;
  for (int i = 1; i <= term; ++i) {
    monthly_payment[i - 1] =
        (total_loan_amount / term) +
        (total_loan_amount - ((total_loan_amount * (i - 1)) / term)) *
            interest_rate;

    total_repayment += monthly_payment[i - 1];
  }
  double loan_overpayment = total_repayment - total_loan_amount;

  output->monthly_payment = (char *)malloc(sizeof(char) * 128);
  output->loan_overpayment = (char *)malloc(sizeof(char) * 128);
  output->total_repayment = (char *)malloc(sizeof(char) * 128);
  sprintf(output->total_repayment, "%.2lf", total_repayment);
  sprintf(output->loan_overpayment, "%.2lf", loan_overpayment);
  char tmp[128] = {'\0'};
  char first[50] = {'\0'};
  char second[50] = {'\0'};
  sprintf(first, "%.2lf", monthly_payment[0]);
  sprintf(second, "%.2lf", monthly_payment[term - 1]);
  strcat(tmp, first);
  strcat(tmp, "...");
  strcat(tmp, second);
  strcpy(output->monthly_payment, tmp);

  return output;
}

void freeCreditCalcOutput(creditCalcOutput *data) {
  free(data->monthly_payment);
  free(data->loan_overpayment);
  free(data->total_repayment);
  free(data);
}
