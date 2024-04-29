#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "mainwindowSELLER.h"
#include "mainwindowUSER.h"
#include "Login_Filing.cpp"
#include "mainwindow.h"


/*#include "loginInterfaceLogic.cpp"*/

MainWindow2::MainWindow2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

int UserType=1, terms_and_Conditions;

void MainWindow2::on_CheckBox_Terms_and_conditions_2_stateChanged(int state)
{
    if (state == Qt::Checked) {
        UserType = 2;
    }
    else {
        UserType = 1;
    }
}

void MainWindow2::on_CheckBox_Terms_and_conditions_stateChanged(int state)
{
    if (state == Qt::Checked) {
        terms_and_Conditions = 1;
    }
    else {
        terms_and_Conditions = 0;
    }
}



void MainWindow2::on_Button_Sign_up_clicked()
{
    bool DotPresent=0;
    int AtPresent=0;
    QString EmailText=ui->lineEdit_Email->text();
    for(int i=0; i<EmailText.size(); i++)
    {
        if (EmailText.at(i)=='@')
            AtPresent++;

        if (EmailText.at(i)=='.')
            DotPresent=1;

    }
    QString given_username, given_password,given_email;

    if(ui->lineEdit_Username->text().isEmpty() ||ui->lineEdit_Password->text().isEmpty() ||
        ui->lineEdit_Confirm_Password->text().isEmpty() || ui->lineEdit_Email->text().isEmpty())
        QMessageBox::warning(this,"Inclomplete Input","Please Fill-out all fields.");
    else if(ui->lineEdit_Password->text().size()<6)
        QMessageBox::warning(this,"Password too Short","The password needs to be atleast 6 characters.");
    else if (ui->lineEdit_Password->text() !=ui->lineEdit_Confirm_Password->text())
        QMessageBox::warning(this,"Missmatch found","The passwords do not match.");
    else if (AtPresent!=1 ||  !DotPresent)
        QMessageBox::warning(this,"Invalid Email","Please enter a valid email.");
    else if (terms_and_Conditions!=1)
        QMessageBox::warning(this,"Terms and Conditions Unchecked","Please agree to the terms and conditions of the app.");
    else {
        given_username=ui->lineEdit_Username->text();
        given_password=ui->lineEdit_Password->text();
        given_email=ui->lineEdit_Email->text();
        SignUp* check= new SignUp();
        int result=check->signup(given_username,given_password,given_email,UserType);
        this->hide();
        if(UserType==2 || UserType==1)
        {
            MainWindow *SignupAgain= new MainWindow();
            this->hide();
            SignupAgain->show();
        }

    }


}



