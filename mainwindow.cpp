#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QLineEdit>
#include <stdlib.h>
#include <time.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(NULL));

    secret = 1+ (rand()%10);
    qDebug() <<"Random: "<<QString::number(secret);
    ui->button->setDisabled(true);
    ui->number->setDisabled(true);
    ui->number->setText("1");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    ui->button->setDisabled(false);
    ui->number->setDisabled(false);
}


void MainWindow::on_button_clicked()
{

    guess = ui->number->text().toInt();

    if(guess == secret){
        ui->result->setText("Congratulation, the secret number is: "+QString::number(secret));
        ui->button->setDisabled(true);
        ui->number->setDisabled(true);
        ui->start->setDisabled(false);
    }else{
        if( guess > secret ){
            ui->result->setText("The true number is lower");
        }
        if( guess < secret ){
            ui->result->setText("The true number is higher");
        }
    }
}

