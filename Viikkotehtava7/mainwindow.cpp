#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QPushButton*> numberButtons = {
        ui->num0, ui->num1, ui->num2, ui->num3, ui->num4,
        ui->num5, ui->num6, ui->num7, ui->num8, ui->num9
    };

    for (QPushButton* button : numberButtons) {
        connect(button, &QPushButton::clicked, this, &MainWindow::numberClickedHandler);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QString name = button->objectName();
    qDebug() << "Button name: " << name;
    if (active_number == 1) {
        number1 += button->text();
        ui->lineEdit_num1->setText(number1);
        qDebug() << "Number1: " << number1;
    } else if (active_number == 2) {
        number2 += button->text();
        ui->lineEdit_num2->setText(number2);
        qDebug() << "Number2: " << number2;
    } else {
        qDebug() << "No slot active";
    }
}



void MainWindow::on_clear_button_clicked()
{
    number1.clear();
    number2.clear();
    result.clear();
    action.clear();

    ui->lineEdit_num1->setText(number1);
    ui->lineEdit_num2->setText(number2);
    ui->lineEdit_result->setText(result);
}


void MainWindow::on_enter_button_clicked()
{
    float number1_ = number1.toFloat();
    float number2_ = number2.toFloat();
    float result_;
    if (number1.isEmpty() || number2.isEmpty()) {
        result_ = 0.0;
    }
    if (action == "+") {
        result_ = number1_ + number2_;
    } else if (action == "-") {
        result_ = number1_ - number2_;
    } else if (action == "*") {
        result_ = number1_ * number2_;
    } else if (action == "/") {
        result_ = number1_ / number2_;
    } else {
        qDebug() << "No action selected";
        result_ = 0.0;
    }
    qDebug() << "Result: " << result;
    result = QString::number(result_);
    ui->lineEdit_result->setText(result);
}


void MainWindow::on_add_button_clicked()
{
    action = "+";
    qDebug() << "Add selected";
}

void MainWindow::on_sub_button_clicked()
{
    action = "-";
    qDebug() << "Sub selected";
}

void MainWindow::on_mul_button_clicked()
{
    action = "*";
    qDebug() << "Mul selected";
}


void MainWindow::on_div_button_clicked()
{
    action = "/";
    qDebug() << "Div selected";
}


void MainWindow::on_lineEdit_num1_selectionChanged()
{
    active_number = 1;
    qDebug() << "Active number slot 1";
}


void MainWindow::on_lineEdit_num2_selectionChanged()
{
    active_number = 2;
    qDebug() << "Active number slot 2";
}
