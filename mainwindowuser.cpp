#include "mainwindowuser.h"
#include "ui_mainwindowuser.h"
#include"mainwindowuser2.h"
#include"mainwindowuser3.h"
#include"mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include<vector>
#include<QMessageBox>
#include <QFile>
#include <QTextStream>
#include <iomanip>
#include <QString>
#include <QDateTime>
#include <QDebug>

struct product{
    QString id;
    QString name;
    QString description;
    QString price;
    QString quantity;
};


void add_data(Ui::MainWindowUSER *ui){
    ui->Product_Table->clear();
    ui->Product_Table->setColumnCount(5);
    ui->Product_Table->horizontalHeader()->resizeSection(0,40);
    ui->Product_Table->horizontalHeader()->resizeSection(1,110);
    ui->Product_Table->horizontalHeader()->resizeSection(2,184);
    ui->Product_Table->horizontalHeader()->resizeSection(3,70);
    ui->Product_Table->horizontalHeader()->resizeSection(4,86);
    ui->Product_Table->setHorizontalHeaderLabels(QStringList()<<"Id"<<"Name"<<"Description"<<"Qty"<<"Price");

    QFile invent("Login_Data.txt");
    if (invent.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&invent);
        int count = 0;
        qDebug() << count << "\n";
        while(!in.atEnd()){
            if(in.readLine() == "######################"){
                count++;
            }
        }
        ui->Product_Table->setRowCount(count);

        std::vector<product> p1(count);
        invent.seek(0);
        int i = 0;
        while(!in.atEnd() && i < count){
            if(in.readLine() == "######################"){
                p1[i].id = in.readLine().mid(4);
                p1[i].name = in.readLine().mid(6);
                p1[i].description = in.readLine().mid(13);
                p1[i].quantity = in.readLine().mid(10);
                p1[i].price = in.readLine().mid(7);
                qDebug() << "Product Found Successfully\n";
                i++;
            }
        }
        invent.close();
        for (int row = 0; row < count; ++row) {
            for (int col = 0; col < 5; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem();
                switch (col) {
                case 0: item->setText(p1[row].id); break;
                case 1: item->setText(p1[row].name); break;
                case 2: item->setText(p1[row].description); break;
                case 3: item->setText(p1[row].quantity); break;
                case 4: item->setText(p1[row].price); break;
                }
                ui->Product_Table->setItem(row, col, item);
            }
            ui->Product_Table->setRowHeight(row, 80);
        }

    }
    else{
        qDebug() << "Unable to open file";
    }
}

void add_data2(Ui::MainWindowUSER *ui){
    ui->Cart_Table->clear();
    ui->Cart_Table->setColumnCount(5);
    ui->Cart_Table->horizontalHeader()->resizeSection(0,40);
    ui->Cart_Table->horizontalHeader()->resizeSection(1,110);
    ui->Cart_Table->horizontalHeader()->resizeSection(2,184);
    ui->Cart_Table->horizontalHeader()->resizeSection(3,70);
    ui->Cart_Table->horizontalHeader()->resizeSection(4,86);
    ui->Cart_Table->setHorizontalHeaderLabels(QStringList()<<"Id"<<"Name"<<"Description"<<"Qty"<<"Price");

    QFile invent("Cart.txt");
    if (invent.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&invent);
        int count = 0;
        qDebug() << count << "\n";
        while(!in.atEnd()){
            if(in.readLine() == "######################"){
                count++;
            }
        }
        ui->Cart_Table->setRowCount(count); // Set the row count before adding items

        // Use std::vector for dynamic allocation
        std::vector<product> p1(count);
        invent.seek(0); // Reset file pointer to the beginning
        int i = 0;
        while(!in.atEnd() && i < count){
            if(in.readLine() == "######################"){
                p1[i].id = in.readLine().mid(4);
                p1[i].name = in.readLine().mid(6);
                p1[i].description = in.readLine().mid(13);
                p1[i].quantity = in.readLine().mid(10);
                p1[i].price = in.readLine().mid(7);
                qDebug() << "Product Found Successfully\n";
                i++;
            }
        }
        invent.close();
        for (int row = 0; row < count; ++row) {
            for (int col = 0; col < 5; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem();
                switch (col) {
                case 0: item->setText(p1[row].id); break;
                case 1: item->setText(p1[row].name); break;
                case 2: item->setText(p1[row].description); break;
                case 3: item->setText(p1[row].quantity); break;
                case 4: item->setText(p1[row].price); break;
                }
                ui->Cart_Table->setItem(row, col, item);
            }
            ui->Cart_Table->setRowHeight(row, 80);
        }

    }
    else{
        qDebug() << "Unable to open file";
    }
}

MainWindowUSER::MainWindowUSER(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowUSER)
{
    ui->setupUi(this);
    add_data(ui);
    add_data2(ui);
}

MainWindowUSER::~MainWindowUSER()
{
    delete ui;
}

void MainWindowUSER::on_pushButton_clicked()
{
    this->hide();
    MainWindowuser2 *add_to_cart = new MainWindowuser2();
    add_to_cart->show();
}


void MainWindowUSER::on_pushButton_2_clicked()
{
    QFile invent("Cart.txt");

    if (invent.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&invent);
        int count = 0;
        while (!in.atEnd()) {
            if (in.readLine() == "######################") {
                count++;
            }
        }
        invent.seek(0);
        std::vector <product> p1(count);
        int i = 0;
        while (!in.atEnd() && i < count) {
            QString line = in.readLine();
            if (line == "######################") {
                p1[i].id = in.readLine().mid(4);
                p1[i].name = in.readLine().mid(6);
                p1[i].description = in.readLine().mid(13);
                p1[i].quantity = in.readLine().mid(10);
                p1[i].price = in.readLine().mid(7);
                qDebug() << "Product Found Successfully\n";
                i++;
            }
        }
        if(i == 0){
            QMessageBox::critical(nullptr, "Error", "Your Cart is Empty");
        }
        invent.close();

        // Writing to Receipt file
        if(i != 0){
            double Cost = 0;
            QDateTime currentDateTime = QDateTime::currentDateTime();
            QString billingTime = currentDateTime.toString(Qt::ISODate);
            QFile receipt("Receipt.txt");
            if (receipt.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&receipt);
                out << "-------------------------------------------------------------" << "\n";
                out << "                             " << "Ecommerce Store" << "             " << "\n";
                out << "-------------------------------------------------------------" << "\n";
                out << "Billing Time: " << billingTime << "\n";
                out << "-------------------------------------------------------------" << "\n";

                out << QString("%1 %2 %3\n")
                           .arg("Product Name\t", -20)
                           .arg("Quantity\t", -15)
                           .arg("Price\t", -15);
                out << "-------------------------------------------------------------" << "\n";

                for (int i = 0; i < count; ++i) {
                    Cost += p1[i].price.toDouble();
                    QString productName = p1[i].name;
                    if (productName.length() > 20) {
                        productName = productName.left(20) + "...\t";
                    }
                    out << QString("%1 %2 %3\n")
                               .arg(productName, -20)
                               .arg(p1[i].quantity, -15)
                               .arg(p1[i].price, -15);
                }

                out << "-------------------------------------------------------------" << "\n";
                out << "Total Amount: " << Cost << "\n";
                double TaxCost = (Cost * 13) / 100;
                out << "GST (13%): " << TaxCost << "\n";
                double finalAmount = Cost + TaxCost;
                out << "Final Amount: " << finalAmount << "\n";
                out << "-------------------------------------------------------------" << "\n";
                out << "                        "<< "Thank you for shopping!" << "\n";
                receipt.close();
            }
            this->hide();
            MainWindowUSER3 *receipt_window = new MainWindowUSER3();
            receipt_window->show();
        }
    }

}


void MainWindowUSER::on_pushButton_3_clicked()
{
    this->hide();
    MainWindow *login_window = new MainWindow();
    login_window->show();
}

