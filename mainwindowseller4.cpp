#include "mainwindowSELLER4.h"
#include "ui_mainwindowSELLER4.h"
#include"mainwindowSELLER.h"
#include "mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QDebug>
#include <QStringList>
#include<QString>
#include <QObject>
#include<QInputDialog>

MainWindowSELLER4::MainWindowSELLER4(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowSELLER4)
{
    ui->setupUi(this);
}

MainWindowSELLER4::~MainWindowSELLER4()
{
    delete ui;
}

void MainWindowSELLER4::on_pushButton_2_clicked()
{
    this->hide();
    MainWindowSELLER *seller_portal = new MainWindowSELLER();
    seller_portal->show();
}

void deleteProduct(int productId) {

    QString productIdTODELETE= QString::number(productId);
    QFile inventory("Login_Data.txt");
    if (!inventory.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file.";
        return;
    }

    extern int UniqueId;
    QString myuniq4 = QString::number(UniqueId);
    QString SearchForPlace3;
    QTextStream in(&inventory);

    QFile TempSELLER_Table_File("Temp_SEller_file.txt");
    TempSELLER_Table_File.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream outTemp(&TempSELLER_Table_File);

    while(!(SearchForPlace3.contains("######### ") && SearchForPlace3.contains(myuniq4))  )
    {
        SearchForPlace3=in.readLine();
        outTemp<<SearchForPlace3<<"\n";
    }
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




void MainWindowSELLER4::on_pushButton_clicked()
{
    int id = ui->id_input->text().toInt();

    deleteProduct(id);
    this->hide();
    MainWindowSELLER *seller_portal = new MainWindowSELLER();
    seller_portal->show();
}
