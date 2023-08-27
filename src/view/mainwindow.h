#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

#ifdef __cplusplus
extern "C"
{
#endif
#include "../smart_calc_controller.h" // path - controller
#ifdef __cplusplus
}
#endif

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void buttons();

    void on_pushButton_equal_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_graph_clicked();

    void on_pushButton_credit_clicked();

    void on_pushButton_debit_clicked();

private:
    Ui::MainWindow *ui;

    void set_signals();
};
#endif // MAINWINDOW_H
