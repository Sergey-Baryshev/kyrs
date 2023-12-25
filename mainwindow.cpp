#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QLineEdit>
#include <QComboBox>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bmr_clicked()
{
        if (ui->weightLineEdit->text().isEmpty() ||
            ui->heightLineEdit->text().isEmpty() ||
            ui->ageLineEdit->text().isEmpty()) {
            QMessageBox::critical(this, "Ошибка", "Введите данные");
            return;
        }
    double weight = ui->weightLineEdit-> text().toDouble();
    double height = ui->heightLineEdit-> text().toDouble();
    int age = ui->ageLineEdit->text().toInt();
    double bmr;

    if (ui->formulaComboBox->currentText()=="Формула Миффлина-Сан Жеора"){
        bmr = (10 * weight) + (6.25 * height) - (4.92 * age) + 5;
    }
    else if  ( ui->formulaComboBox->currentText()=="Формула Харриса-Бенедикта") {
        bmr =  (13.75 * weight) + (5.0 * height) - (6.74 * age) + 66.47 ;
    }
    QMessageBox::information(this, "Результат", "Ваш базовый метаболизм: " + QString::number (bmr));
}

void MainWindow::on_exit_clicked()
{
    QMessageBox::StandardButton reply= QMessageBox::question(this, "Закрыть приложение", "Вы действительной желаете выйти?", QMessageBox::Yes | QMessageBox:: No);
    if (reply == QMessageBox::Yes){
        QApplication::quit();
    }
}

