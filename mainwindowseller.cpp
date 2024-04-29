#include <vector>
#include "mainwindowseller.h"
#include "mainwindow.h"
#include "./ui_mainwindowseller.h"
#include "mainwindowseller2.h"
#include "mainwindowSELLER3.h"
#include "mainwindowSELLER4.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>



QString SearchForPlace,searchit;

struct product{
    QString id;
    QString name;
    QString description;
    QString price;
    QString quantity;
};

void add_data(Ui::MainWindowSELLER *ui){
    extern int UniqueId;
    QString myuniq = QString::number(UniqueId);

    ui->Product_Table->clear();
    ui->Product_Table->setColumnCount(5);
    ui->Product_Table->horizontalHeader()->resizeSection(0,70);
    ui->Product_Table->horizontalHeader()->resizeSection(1,120);
    ui->Product_Table->horizontalHeader()->resizeSection(2,378);
    ui->Product_Table->horizontalHeader()->resizeSection(3,70);
    ui->Product_Table->horizontalHeader()->resizeSection(4,86);
    ui->Product_Table->setHorizontalHeaderLabels(QStringList()<<"Id"<<"Name"<<"Description"<<"Qty"<<"Price");

    QFile invent("Login_Data.txt");
    if (invent.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&invent);
        int count = 0;
        while(!(SearchForPlace.contains("######### ") && SearchForPlace.contains(myuniq))  )
        {
            SearchForPlace=in.readLine();
        }
        SearchForPlace="";

        while(!searchit.contains("######### ")){
            searchit=in.readLine();
            if(in.atEnd())
                break;


            if(searchit == "######################"){
                count++;
            }
        }
        SearchForPlace="";
        searchit="";

        ui->Product_Table->setRowCount(count);

        std::vector<product> p1(count);
        invent.seek(0);

        while(!(SearchForPlace.contains("######### ") && SearchForPlace.contains(myuniq))  )
        {
            SearchForPlace=in.readLine();
        }
        SearchForPlace="";
        searchit="";

        int i = 0;
        while(!searchit.contains("######### ") && i < count){
            searchit=in.readLine();
            if(in.atEnd())
                break;


            if(searchit == "######################"){
                p1[i].id = in.readLine().mid(4);
                p1[i].name = in.readLine().mid(6);
                p1[i].description = in.readLine().mid(13);
                p1[i].quantity = in.readLine().mid(10);
                p1[i].price = in.readLine().mid(7);

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
            ui->Product_Table->setRowHeight(row, 55);
        }

    }
}

MainWindowSELLER::MainWindowSELLER(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowSELLER)
{
    ui->setupUi(this);
    add_data(ui);
}

MainWindowSELLER::~MainWindowSELLER()
{
    delete ui;
}

void MainWindowSELLER::on_pushButtons_clicked()
{
    this->hide();
    MainWindowSELLER2 *add_product = new MainWindowSELLER2();
    add_product->show();
}

void MainWindowSELLER::on_pushButtons_2_clicked()
{
    this->hide();
    MainWindowSELLER3 *edit_product = new MainWindowSELLER3();
    edit_product->show();
}

void MainWindowSELLER::on_pushButtons_3_clicked()
{
    this->hide();
    MainWindowSELLER4 *delete_product = new MainWindowSELLER4();
    delete_product->show();
}




void MainWindowSELLER::on_pushButtons_4_clicked()
{
    this->hide();
    MainWindow *login = new MainWindow();
    login->show();
}

