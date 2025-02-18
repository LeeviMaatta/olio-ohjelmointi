#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_clear_button_clicked();

    void on_enter_button_clicked();

    void on_add_button_clicked();

    void on_mul_button_clicked();

    void on_div_button_clicked();

    void on_lineEdit_num1_selectionChanged();

    void on_lineEdit_num2_selectionChanged();

    void on_sub_button_clicked();

private:
    Ui::MainWindow *ui;
    QString number1;
    QString number2;
    QString result;
    int active_number;
    QString action;
    void numberClickedHandler();
};
#endif // MAINWINDOW_H
