#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QLabel"
#include <QMainWindow>
#include <QTimer>
#include <QApplication>


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
    void changeLabelText(QString teksti);
    bool game = 0;

private slots:
    void on_stop_button_clicked();

    void on_start_button_clicked();

    void on_min5_button_clicked();

    void on_sec120_button_clicked();

    void on_switch_2_button_clicked();

    void on_switch_1_button_clicked();

    void updateTimer();
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    unsigned int counter;
    unsigned int player1_time;
    unsigned int player2_time;
    unsigned int game_time;
    bool timer_running;
    bool active_player;
};
#endif // MAINWINDOW_H
