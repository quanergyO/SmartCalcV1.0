#ifndef CREDITWINDOW_H
#define CREDITWINDOW_H

#include <QMainWindow>

#ifdef __cplusplus
extern "C"
{
#endif
#include "../smart_calc_controller.h" // path - controller
#ifdef __cplusplus
}
#endif

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreditWindow(QWidget *parent = nullptr);
    ~CreditWindow();

private slots:
    void on_pushButton_calc_credit_clicked();

private:
    Ui::CreditWindow *ui;
};

#endif // CREDITWINDOW_H
