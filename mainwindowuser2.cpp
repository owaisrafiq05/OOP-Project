#include "MainWindowuser2.h"
#include"mainwindowuser.h"
#include "ui_MainWindowuser2.h"
#include<QFile>
#include<QTextStream>
#include<QString>
#include<QDebug>
#include<QChar>
#include<QMessageBox>

MainWindowuser2::MainWindowuser2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowuser2)
{
    ui->setupUi(this);
}

MainWindowuser2::~MainWindowuser2()
{
    delete ui;
}

void MainWindowuser2::on_pushButton_2_clicked()
{
    this->hide();
    MainWindowUSER *add_to_cart = new MainWindowUSER();
    add_to_cart->show();
}

QString MainWindowuser2::getTextFromLine(int lineNumber) {
    QFile file("Login_Data.txt");
    int i = 0;
    QString lineText;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while(!in.atEnd()){
            lineText = in.readLine();
            i++;
            if(i == lineNumber){
                break;
            }
            else{}
        }
    }
    else{
        qDebug() << "Failed to open file for reading:" << "Login_Data.txt";
        return QString();
    }
    file.close();
    return lineText;
}

bool MainWindowuser2::replaceTextAtLine(const QString& filePath, int lineNumber, const QString& newText) {
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


void MainWindowuser2::on_pushButton_clicked()
{
    QString id = ui->id_input->text();
    QString user_quantity = ui->quantity_input->text();
    int u_quantity = user_quantity.toInt();
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
    invent.close();
    int qLineNo = count+3;
    QString quantity_line = getTextFromLine(qLineNo);
    QString actual_quantity = quantity_line.mid(10);
    int a_quantity = actual_quantity.toInt();
    // qDebug() << a_quantity;
    if(a_quantity < u_quantity){
        QMessageBox::critical(nullptr, "Error", "Given Quantity is greater than Available Quantity!");
    }
    else{
        QString id_line = getTextFromLine(count);
        QString name_line = getTextFromLine(count + 1);
        QString desc_line = getTextFromLine(count + 2);
        QString price_line = getTextFromLine(count + 4);
        QString qTemp = "Quantity: "; // 4 => Quantity: 4
        QString qTemp2 = QString::number(u_quantity);
        QString quantity_line_fin = qTemp + qTemp2;
        float price = price_line.mid(7).toFloat();
        price = price * u_quantity;
        QString pTemp = "Price: ";
        QString pTemp2 = QString::number(price);
        QString price_line_fin = pTemp + pTemp2;
        // qDebug() << id_line;
        // qDebug() << name_line;
        // qDebug() << desc_line;
        // qDebug() << quantity_line_fin;
        // qDebug() << price_line_fin;
        QFile cart("Cart.txt");
        if (cart.open(QIODevice::Append | QIODevice::Text)){
            QTextStream out(&cart);
            out << "######################" << "\n";
            out << id_line << "\n";
            out << name_line << "\n";
            out << desc_line << "\n";
            out << quantity_line_fin << "\n";
            out << price_line_fin << "\n\n";
            qDebug() << "Products added to cart successfully";
        }
        cart.close();
        int line_no = count + 3;
        a_quantity = a_quantity - u_quantity;
        QString qTemp3 = QString::number(a_quantity);
        QString quantity_line_fin_2 = qTemp + qTemp3;
        QString filepath = "Login_Data.txt";
        if (replaceTextAtLine(filepath, line_no, quantity_line_fin_2)) {
            qDebug() << "Text replaced successfully!";
        } else {
            qDebug() << "Failed to replace text.";
        }
        this->hide();
        MainWindowUSER *add_to_cart = new MainWindowUSER();
        add_to_cart->show();
        QMessageBox::information(nullptr, "Success", "Product Added to Cart Successfully");
    }
}
