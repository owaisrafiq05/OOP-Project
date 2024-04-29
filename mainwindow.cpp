#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mainwindow2.h"
#include "mainwindowadm.h"
#include "mainwindowseller.h"
#include "mainwindowUser.h"
#include "Login_Filing.cpp"
#include "AdminTableLogic.cpp"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_SignUp_instead_clicked()
{
    MainWindow2 *Signup= new MainWindow2();
    this->hide();
    Signup->show();
}

bool ValidUsernameAndPassword=0;
int TypeChosen=0,UniqueId=0;
QString login_password,login_email;

void MainWindow::on_Button_login_clicked()
{   login_password=ui->lineEdit_Password_login->text();
    login_email=ui->lineEdit_Email_login->text();

    Login* loginTheUser= new Login();
    UniqueId=loginTheUser->DO_login(login_email,login_password,TypeChosen);
    qDebug()<<UniqueId;
    if(UniqueId!=-1)
    {
        ValidUsernameAndPassword=1;
    }

    bool DotPresentCondition=0;
    int AtPresentCondition=0;
    QString EmailText=ui->lineEdit_Email_login->text();
    for(int i=0; i<EmailText.size(); i++)
    {
        if (EmailText.at(i)=='@')
            AtPresentCondition++;

        if (EmailText.at(i)=='.')
            DotPresentCondition=1;
    }


    if(ui->lineEdit_Password_login->text().isEmpty() ||ui->lineEdit_Email_login->text().isEmpty())
        QMessageBox::warning(this,"Inclomplete Input","Please Fill-out all fields.");
    else if (AtPresentCondition!=1 ||  !DotPresentCondition)
        QMessageBox::warning(this,"Invalid Email","Please enter a valid email.");
    else if(ui->lineEdit_Password_login->text().size()<6)
        QMessageBox::warning(this,"Password too Short","The password needs to be atleast 6 characters.");
    else if(!ValidUsernameAndPassword)
        QMessageBox::warning(this,"Invalid Credentials","The Username Or Password is wrong.");
    else if(TypeChosen==0)
        QMessageBox::warning(this,"No type Specified","Please select the mode of login.");
    else{
        this->hide();
        if(TypeChosen==2)
        {
            MainWindowSELLER* sellerPage= new MainWindowSELLER();
            sellerPage->show();
        }
        else if(TypeChosen==3)
        {
            Admin_Tables *A= new Admin_Tables();
            A->update_admin_Table();
            MainWindowadm* AdminPage= new MainWindowadm();
            AdminPage->show();
        }
        else if(TypeChosen==1)
        {
            MainWindowUSER* UserPage= new MainWindowUSER();
            UserPage->show();
        }
    }
}




void MainWindow::on_radioButton_Seller_toggled(bool checked)
{
    if(checked){
        ui->radioButton_User->setChecked(false);
        ui->radioButton_Admin->setChecked(false);
        TypeChosen=2;
    }

}


void MainWindow::on_radioButton_Admin_toggled(bool checked)
{
    if(checked){
        ui->radioButton_User->setChecked(false);
        ui->radioButton_Seller->setChecked(false);
        TypeChosen=3;
    }
}


void MainWindow::on_radioButton_User_toggled(bool checked)
{
    if(checked){
        ui->radioButton_Admin->setChecked(false);
        ui->radioButton_Seller->setChecked(false);
        TypeChosen=1;
    }
}
