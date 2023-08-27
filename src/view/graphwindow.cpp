#include "graphwindow.h"

#include <iostream>

#include "ui_graphwindow.h"

GraphWindow::GraphWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::GraphWindow) {
  ui->setupUi(this);
  connect(ui->lineEdit_f_x, SIGNAL(returnPressed()), this,
          SLOT(on_pushButton_draw_clicked()));
  setAttribute(Qt::WA_DeleteOnClose);
}

GraphWindow::~GraphWindow() { delete ui; }

void GraphWindow::on_pushButton_draw_clicked() {
  double x_min = QString(ui->doubleSpinBox_start_x->text()).toDouble();
  double x_max = QString(ui->doubleSpinBox_end_x->text()).toDouble();
  double y_min = QString(ui->doubleSpinBox_min_y->text()).toDouble();
  double y_max = QString(ui->doubleSpinBox_max_y->text()).toDouble();
  double step = QString(ui->doubleSpinBox_step->text()).toDouble();

  long double res = 0;
  std::string str = ui->lineEdit_f_x->text().toLower().toStdString();
  const char* infix = str.c_str();
  char inputStr[MAX_LEN + 1] = {0};
  for (int i = 0; str[i]; i++) {
    inputStr[i] = tolower(infix[i]);
  }
  bool isValid = isInputValid(inputStr);
  if (isValid) {
    char* strDivided = lexemsDivider(inputStr);
    char* postfix = fromInfixToPostfix(strDivided);
    free(strDivided);
    QVector<double> x, y;
    for (double current_x = x_min; current_x < x_max; current_x += step) {
      double tmp = calculateWithX(postfix, current_x);
      x.push_back(current_x);
      y.push_back(tmp);
    }

    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y, true);
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->xAxis->setRange(x_min, x_max);
    ui->widget->yAxis->setRange(y_min, y_max);
    //        ui->widget->setInteraction(QCP::iRangeZoom, true);
    //        ui->widget->setInteraction(QCP::iRangeZoom, true);

    ui->widget->replot();
    x.clear();
    y.clear();
    free(postfix);
  } else {
    ui->lineEdit_f_x->setText("Error!");
  }
}
