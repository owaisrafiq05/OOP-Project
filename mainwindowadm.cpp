#include "mainwindowadm.h"
#include "ui_mainwindowadm.h"
#include "mainwindowadm2.h"
#include"mainwindow.h"
#include "AdminTableLogic.cpp"
#include "mainwindoweditinfo.h"
#include<QMessageBox>
#include<QDebug>
#include <vector>

struct product{
    QString id;
    QString name;
    QString description;
    QString price;
    QString quantity;
};

void UpdateANDShow_Admin_Tables(Ui::MainWindowadm *ui){
    ui->tableWidget_UserSellerInfo->clear();
    ui->tableWidget_UserSellerInfo->setColumnCount(4);
    ui->tableWidget_UserSellerInfo->horizontalHeader()->resizeSection(0, 70);
    ui->tableWidget_UserSellerInfo->horizontalHeader()->resizeSection(1, 150);
    ui->tableWidget_UserSellerInfo->horizontalHeader()->resizeSection(2, 150);
    ui->tableWidget_UserSellerInfo->horizontalHeader()->resizeSection(3, 213);

    ui->tableWidget_UserSellerInfo->setHorizontalHeaderLabels(QStringList() << "Id" << "Username" << "Password" << "Email");

    Admin_Tables* A= new Admin_Tables();
    A->update_admin_Table();
    Add_Data_to_Admin_Table * UserSellerData= new Add_Data_to_Admin_Table();
    Tableinfo *tab1 =UserSellerData->User_Data_to_Table();
    Tableinfo *tab2 =UserSellerData->Seller_Data_to_Table();

    ui->tableWidget_UserSellerInfo->setRowCount(UserSellerData->countUsers+UserSellerData->countSellers);

    for (int row = 0; row < UserSellerData->countUsers; ++row) {
        for (int col = 0; col < 4; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem();
            switch (col) {
            case 0: item->setText(tab1[row].theId); break;
            case 1: item->setText(tab1[row].theUsername); break;
            case 2: item->setText(tab1[row].thePassword); break;
            case 3: item->setText(tab1[row].theEmail); break;
            }
            ui->tableWidget_UserSellerInfo->setItem(row, col, item);
        }
        ui->tableWidget_UserSellerInfo->setRowHeight(row, 50);
    }

    for (int row=0; row < UserSellerData->countSellers; ++row) {
        for (int col = 0; col < 4; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem();
            switch (col) {
            case 0: item->setText(tab2[row].theId); break;
            case 1: item->setText(tab2[row].theUsername); break;
            case 2: item->setText(tab2[row].thePassword); break;
            case 3: item->setText(tab2[row].theEmail); break;
            }
            ui->tableWidget_UserSellerInfo->setItem(row + UserSellerData->countUsers, col, item);
        }
        ui->tableWidget_UserSellerInfo->setRowHeight(row+ UserSellerData->countUsers, 50);
    }
    delete[] tab1;
    delete[] tab2;
}


void add_data_to_Product_Table(Ui::MainWindowadm *ui){

    ui->tableWidget_Products_admin->clear();
    ui->tableWidget_Products_admin->setColumnCount(5);
    ui->tableWidget_Products_admin->horizontalHeader()->resizeSection(0,70);
    ui->tableWidget_Products_admin->horizontalHeader()->resizeSection(1,120);
    ui->tableWidget_Products_admin->horizontalHeader()->resizeSection(2,378);
    ui->tableWidget_Products_admin->horizontalHeader()->resizeSection(3,70);
    ui->tableWidget_Products_admin->horizontalHeader()->resizeSection(4,86);
    ui->tableWidget_Products_admin->setHorizontalHeaderLabels(QStringList()<<"Id"<<"Name"<<"Description"<<"Qty"<<"Price");

    QFile invent("Login_Data.txt");
    if (invent.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&invent);
        int count = 0;
        while(!in.atEnd()){
            if(in.readLine() == "######################"){
                count++;
            }
        }

        ui->tableWidget_Products_admin->setRowCount(count);

        qDebug()<<count;
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

                i++;
            }
        }
        invent.close();
        for (int row=0;row<count;++row) {
            for (int col = 0; col < 5; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem();
                switch (col) {
                case 0: item->setText(p1[row].id); break;
                case 1: item->setText(p1[row].name); break;
                case 2: item->setText(p1[row].description); break;
                case 3: item->setText(p1[row].quantity); break;
                case 4: item->setText(p1[row].price); break;
                }
                ui->tableWidget_Products_admin->setItem(row, col, item);
            }
            ui->tableWidget_Products_admin->setRowHeight(row, 80);
        }

    }
}

MainWindowadm::MainWindowadm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowadm)
{  ui->setupUi(this);


    UpdateANDShow_Admin_Tables(ui);
    add_data_to_Product_Table(ui);

}

MainWindowadm::~MainWindowadm()
{
    delete ui;
}



void MainWindowadm::on_Button_Edit_Data_clicked()
{
    this->hide();
    MainWindoweditinfo* EditTheInfo= new MainWindoweditinfo();
    EditTheInfo->show();

}


void MainWindowadm::on_Button_Remove_Product_clicked()
{
    this->hide();
    MainWindowadm2 *delete_product2 = new MainWindowadm2();
    delete_product2->show();
}

void MainWindowadm::on_btn_log_out_clicked()
{
    this->hide();
    MainWindow *login = new MainWindow();
    login->show();
}

