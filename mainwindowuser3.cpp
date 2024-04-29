#include "mainwindowuser3.h"
#include "ui_mainwindowuser3.h"
#include"mainwindowuser.h"
#include <QMessageBox>
#include <QStandardPaths>
#include <QIODevice>
#include<QTextStream>
#include<QFile>

MainWindowUSER3::MainWindowUSER3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowUSER3)
{
    ui->setupUi(this);
    QFile file("Receipt.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this, "Error", file.errorString());
    }
    QTextStream in(&file);
    while(!in.atEnd()){
        QListWidgetItem *item = new QListWidgetItem(in.readLine(), ui->listWidget);
        ui->listWidget->addItem(item);
    }

    file.close();
}

MainWindowUSER3::~MainWindowUSER3()
{
    delete ui;
}

void MainWindowUSER3::on_pushButton_clicked()
{
    QFile file("Receipt.txt");
    if(file.open(QIODevice::WriteOnly)){
        QTextStream out(&file);
        out << "" ;
    }
    file.close();
    QFile cart("Cart.txt");
    if(cart.open(QIODevice::WriteOnly)){
        QTextStream out(&cart);
        out << "" ;
    }
    cart.close();
    this->hide();
    MainWindowUSER *seller_portal = new MainWindowUSER();
    seller_portal->show();
    QMessageBox::information(nullptr, "Success", "Successfully Checked out. Cart is now Empty");
}
