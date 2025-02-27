#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , counter(0)
    , timer_running(false)
    , active_player(0)
    , game(0)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTimer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTimer()
{
    counter++;
    if (active_player == 0) {
        player1_time--;
        ui->progressBar_1->setValue(player1_time);
    } else {
        player2_time--;
        ui->progressBar_2->setValue(player2_time);
    }
    if (player1_time == 0) {
        game = 0;
        timer->stop();
        ui->label->setText("Player 2 WON!!");
    } else if (player2_time == 0) {
        game = 0;
        timer->stop();
        ui->label->setText("Player 1 WON!!");
    }
}

void MainWindow::changeLabelText(QString teksti)
{
    ui->label->setText(teksti);
}

void MainWindow::on_stop_button_clicked()
{
    game = 0;
    timer->stop();
    counter = 0;
    active_player = 0;
    player1_time = 0;
    player2_time = 0;
    ui->progressBar_1->setValue(0);
    ui->progressBar_2->setValue(0);

    ui->label->setText("Game stopped. Select time and start again.");
}


void MainWindow::on_start_button_clicked()
{
    if (!game && game_time > 0) {
        timer->start(1000);
        game = 1;
        ui->label->setText("Game ongoing");
    }
}


void MainWindow::on_min5_button_clicked()
{
    if (!game) {
        player1_time = 300;
        player2_time = 300;
        ui->progressBar_1->setRange(0,300);
        ui->progressBar_2->setRange(0,300);
        ui->progressBar_1->setValue(300);
        ui->progressBar_2->setValue(300);
        ui->label->setText("Ready to play");
    }
}


void MainWindow::on_sec120_button_clicked()
{
    if (!game) {
        player1_time = 120;
        player2_time = 120;
        ui->progressBar_1->setRange(0,120);
        ui->progressBar_2->setRange(0,120);
        ui->progressBar_1->setValue(120);
        ui->progressBar_2->setValue(120);
        ui->label->setText("Ready to play");
    }
}


void MainWindow::on_switch_2_button_clicked()
{
    active_player = 0;
}


void MainWindow::on_switch_1_button_clicked()
{
    active_player = 1;
}
