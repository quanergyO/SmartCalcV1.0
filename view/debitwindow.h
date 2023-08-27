#ifndef DEBITWINDOW_H
#define DEBITWINDOW_H

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
class debitWindow;
}

class debitWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit debitWindow(QWidget *parent = nullptr);
    ~debitWindow();

private slots:
    void on_pushButton_calculate_clicked();

    void on_pushButton_replenishment_clicked();

    void on_pushButton_withdrawal_clicked();

private:
    Ui::debitWindow *ui;

    int calculate_replenishment_cycle();
};

#endif // DEBITWINDOW_H
