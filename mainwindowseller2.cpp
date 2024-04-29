#include "mainwindowseller2.h"
#include"mainwindowseller.h"
#include "mainwindow.h"
#include "ui_mainwindowseller2.h"
#include<QFile>
#include<QTextStream>
#include<QString>
#include<QMessageBox>
#include<QRandomGenerator>


MainWindowSELLER2::MainWindowSELLER2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowSELLER2)
{
    MainWindowSELLER *seller_portal = new MainWindowSELLER();
    seller_portal->close();
    ui->setupUi(this);
}

MainWindowSELLER2::~MainWindowSELLER2()
{
    delete ui;
}


QString  SearchForPlace2,searchit2;

void MainWindowSELLER2::on_pushButton_2_clicked()
{
    this->hide();
    MainWindowSELLER *seller_portal = new MainWindowSELLER();
    seller_portal->show();
}

int generateRandomNumber() {
    // Generate a random number between 100 and 999
    int randomNumber = QRandomGenerator::global()->bounded(100, 1000);
    return randomNumber;
}


void MainWindowSELLER2::on_pushButton_clicked()
{
    extern int UniqueId;
    QString myuniq2 = QString::number(UniqueId);


    QFile invent("Login_Data.txt");
    invent.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&invent);
    int count = 0;

    while(!(SearchForPlace2.contains("######### ") && SearchForPlace2.contains(myuniq2))  )
    {
        SearchForPlace2=in.readLine();
    }
    SearchForPlace2="";

    while(!searchit2.contains("######### ")){
        searchit2=in.readLine();
        if(in.atEnd())
            break;


        if(searchit2 == "######################"){
            count++;
        }
    }
    SearchForPlace2="";
    searchit2="";

    invent.close();
    int id = generateRandomNumber();
    QString name = ui->name_input->text();
    QString price = ui->price_input->text();
    QString description = ui->description_input->text();
    QString quantity = ui->quantity_input->text();
    if(name.isEmpty() || price.isEmpty() || description.isEmpty() || quantity.isEmpty()){
        QMessageBox::warning(this,"ERROR","Please fill out all the inputs");
    }
    else{
        QFile TempSELLER_Table_File("Temp_SEller_file.txt");
        invent.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream in2(&invent);

        TempSELLER_Table_File.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream outTemp(&TempSELLER_Table_File);

        while(!(SearchForPlace2.contains("######### ") && SearchForPlace2.contains(myuniq2))  )
        {
            SearchForPlace2=in2.readLine();
            outTemp<<SearchForPlace2<<"\n";
        }
        SearchForPlace2="";

        while(!searchit2.contains("######### ")){
            searchit2=in2.readLine();

            if(!searchit2.contains("######### "))
                outTemp<<searchit2<<"\n";
            if(in2.atEnd())
                break;
        }

        outTemp << "######################" << "\n";
        outTemp << "Id: " << id << "\n";
        outTemp << "Name: " << name << "\n";
        outTemp << "Description: " << description << "\n";
        outTemp << "Quantity: " << quantity << "\n";
        outTemp << "Price: " << price << "\n\n";
        outTemp <<searchit2<< "\n";

        while(!in2.atEnd())
        {
            outTemp <<in2.readLine()<<"\n";
        }
        invent.close();
        TempSELLER_Table_File.close();


        invent.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&invent);


        TempSELLER_Table_File.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream inTemp(&TempSELLER_Table_File);

        while(!inTemp.atEnd())
        {
            out<<inTemp.readLine()<<"\n";
        }
        invent.close();
        TempSELLER_Table_File.close();
        TempSELLER_Table_File.remove();


        this->hide();
        MainWindowSELLER *seller_portal = new MainWindowSELLER();
        seller_portal->show();
    }
}


