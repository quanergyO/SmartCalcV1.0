#include "creditwindow.h"

#include <iostream>

#include "../modules/headers/creditCalc.h"
#include "ui_creditwindow.h"

CreditWindow::CreditWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::CreditWindow) {
  ui->setupUi(this);
  connect(ui->pushButton_calc_credit, SIGNAL(clicked()), this,
          SLOT(on_pushButton_calc_credit_clicked()));
  setAttribute(Qt::WA_DeleteOnClose);
}

CreditWindow::~CreditWindow() { delete ui; }

void CreditWindow::on_pushButton_calc_credit_clicked() {
  creditCalcInput inputData;

  std::string total_loan_amount =
      ui->doubleSpinBox_deposit_amount->text().toStdString();
  std::string term = ui->spinBox_term->text().toStdString();
  std::string interest_rate = ui->spinBox_insert_rate->text().toStdString();

  inputData.total_loan_amount = total_loan_amount.c_str();
  inputData.term = term.c_str();
  inputData.interest_rate = interest_rate.c_str();
  inputData.type =
      ui->comboBox_credit_type->currentIndex() ? differentiated : annuity;

  creditCalcOutput *outputData = apiForCreditCalc(&inputData);

  ui->label_loan_overpayment->setText(QString(outputData->loan_overpayment));
  ui->label_monthly_payment->setText(QString(outputData->monthly_payment));
  ui->label_total_repayment->setText(QString(outputData->total_repayment));

  freeCreditCalcOutput(outputData);
}
