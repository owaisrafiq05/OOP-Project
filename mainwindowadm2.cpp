#include "MainWindowadm2.h"
#include "ui_mainwindowadm2.h"
#include"mainwindowadm.h"
#include "mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QDebug>
#include <QStringList>
#include<QString>
#include <QObject>
#include<QInputDialog>

MainWindowadm2::MainWindowadm2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowadm2)
{
    ui->setupUi(this);
}

MainWindowadm2::~MainWindowadm2()
{
    delete ui;
}

void MainWindowadm2::on_pushButton_back_adm2_clicked()
{
    this->hide();
    MainWindowadm *adminer_portal = new MainWindowadm();
    adminer_portal->show();
}

void deleteProduct2(int productId) {

    QString productIdTODELETE= QString::number(productId);
    QFile inventory("Login_Data.txt");
    if (!inventory.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file.";
        return;
    }

    QTextStream in(&inventory);

    QFile TempSELLER_Table_File("Temp_SEller_file.txt");
    TempSELLER_Table_File.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream outTemp(&TempSELLER_Table_File);

    QString myDELETINGplace,proToDelete[5];


    while(!in.atEnd()){
        myDELETINGplace=in.readLine(productId);

        if(myDELETINGplace=="######################")
        {
            proToDelete[0]=in.readLine();
            proToDelete[1]=in.readLine();
            proToDelete[2]=in.readLine();
            proToDelete[3]=in.readLine();
            proToDelete[4]=in.readLine();

            if(proToDelete[0].contains(productIdTODELETE))
            {
                outTemp<<"\n";
                continue;
            }
            else
            {
                outTemp << myDELETINGplace << "\n";
                for(int i=0;i<5;i++)
                {outTemp << proToDelete[i] << "\n";}
                outTemp << "\n\n";
            }
        }

        else{
            outTemp << myDELETINGplace << "\n";
        }
    }

    TempSELLER_Table_File.close();
    inventory.close();

    inventory.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&inventory);


    TempSELLER_Table_File.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream inTemp(&TempSELLER_Table_File);

    while(!inTemp.atEnd())
    {
        out<<inTemp.readLine()<<"\n";
    }

    inventory.close();
    TempSELLER_Table_File.close();
    TempSELLER_Table_File.remove();

    qDebug() << "Product with ID" << productId << "has been removed successfully";
}

void MainWindowadm2::on_pushButton_save_adm2_clicked()
{
    int id = ui->id_input_adm2->text().toInt();

    deleteProduct2(id);
    this->hide();
    MainWindowadm *adminer_portal = new MainWindowadm();
    adminer_portal->show();
}
