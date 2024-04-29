#include "mainwindowSELLER3.h"
#include "ui_mainwindowSELLER3.h"
#include"mainwindowSELLER.h"
#include<QFile>
#include<QTextStream>
#include<QDebug>

MainWindowSELLER3::MainWindowSELLER3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowSELLER3)
{
    ui->setupUi(this);
}

MainWindowSELLER3::~MainWindowSELLER3()
{
    delete ui;
}

void MainWindowSELLER3::on_pushButton_2_clicked()
{
    this->hide();
    MainWindowSELLER *seller_portal = new MainWindowSELLER();
    seller_portal->show();
}


bool MainWindowSELLER3::replaceTextAtLine(const QString& filePath, int lineNumber, const QString& newText) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Failed to open file for editing:" << filePath;
        return false;
    }

    QStringList lines;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        lines.append(line);
    }

    file.resize(0);
    QTextStream out(&file);
    for (int i = 1; i <= lines.size(); ++i) {
        if (i == lineNumber) {
            out << newText << "\n";
        } else {
            out << lines.at(i - 1) << "\n";
        }
    }
    file.close();
    return true;
}

int choice = 0;

void MainWindowSELLER3::on_name_radio_clicked(bool checked)
{
    if(checked == 1){
        choice = 1;
    }
}


void MainWindowSELLER3::on_description_radio_clicked(bool checked)
{
    if(checked == 1){
        choice = 2;
    }
}



void MainWindowSELLER3::on_quantity_radio_clicked(bool checked)
{
    if(checked == 1){
        choice = 3;
    }
}



void MainWindowSELLER3::on_price_radio_clicked(bool checked)
{
    if(checked == 1){
        choice = 4;
    }
}

void MainWindowSELLER3::on_pushButton_clicked()
{
    QString id = ui->id_input->text();
    QString initial = "Id: ";
    QString final = initial + id;
    QFile invent("Login_Data.txt");
    int count = 0;
    if (invent.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&invent);
        while(!in.atEnd()){
            count++;
            if(in.readLine() == final){
                break;
            }
        }
    }
    if(choice == 1){
        int line_no = count + 1;
        QString change_text1 = ui->changed_text->text();
        QString change_text2 = "Name: ";
        QString change_text3 = change_text2 + change_text1;
        QString filepath = "Login_Data.txt";
        if (replaceTextAtLine(filepath, line_no, change_text3)) {
            qDebug() << "Text replaced successfully!";
        } else {
            qDebug() << "Failed to replace text.";
        }
    }
    else if(choice == 2){
        int line_no = count + 2;
        QString change_text1 = ui->changed_text->text();
        QString change_text2 = "Description: ";
        QString change_text3 = change_text2 + change_text1;
        QString filepath = "Login_Data.txt";
        if (replaceTextAtLine(filepath, line_no, change_text3)) {
            qDebug() << "Text replaced successfully!";
        } else {
            qDebug() << "Failed to replace text.";
        }
    }
    else if(choice == 3){
        int line_no = count + 3;
        QString change_text1 = ui->changed_text->text();
        QString change_text2 = "Quantity: ";
        QString change_text3 = change_text2 + change_text1;
        QString filepath = "Login_Data.txt";
        if (replaceTextAtLine(filepath, line_no, change_text3)) {
            qDebug() << "Text replaced successfully!";
        } else {
            qDebug() << "Failed to replace text.";
        }
    }
    else if(choice == 4){
        int line_no = count + 4;
        QString change_text1 = ui->changed_text->text();
        QString change_text2 = "Price: ";
        QString change_text3 = change_text2 + change_text1;
        QString filepath = "Login_Data.txt";
        if (replaceTextAtLine(filepath, line_no, change_text3)) {
            qDebug() << "Text replaced successfully!";
        } else {
            qDebug() << "Failed to replace text.";
        }
    }
    invent.close();
    this->hide();
    MainWindowSELLER *seller_portal = new MainWindowSELLER();
    seller_portal->show();
}
