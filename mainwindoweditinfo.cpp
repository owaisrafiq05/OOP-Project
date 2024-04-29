#include "mainwindoweditinfo.h"
#include "ui_mainwindoweditinfo.h"
#include "AdminTableLogic.cpp"
#include "mainwindowadm.h"

MainWindoweditinfo::MainWindoweditinfo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindoweditinfo)
{
    ui->setupUi(this);
}

MainWindoweditinfo::~MainWindoweditinfo()
{
    delete ui;
}

int ChangeChosen=0;
void MainWindoweditinfo::on_pushButton_SaveTheChange_clicked()
{
    QString theIdtoChangeInput= ui->Unique_id_input->text();
    QString TheNewDataToReplace=ui->changed_text_for_UniqueId->text();
    if((ChangeChosen==1 || ChangeChosen==2 || ChangeChosen==3 )
        && !ui->Unique_id_input->text().isEmpty() && !ui->changed_text_for_UniqueId->text().isEmpty())
    {
        this->hide();
        Add_Data_to_Admin_Table * DataChanger= new Add_Data_to_Admin_Table();
        DataChanger->changeData(ChangeChosen, theIdtoChangeInput,TheNewDataToReplace);
        MainWindowadm* ANEWAdminPage= new MainWindowadm();
        ANEWAdminPage->show();


    }

}


void MainWindoweditinfo::on_radio_Username_button_clicked(bool checked)
{
    if(checked){
        ui->radio_Password_button->setChecked(false);
        ui->radio_Email_button->setChecked(false);
        ChangeChosen=1;
    }
}


void MainWindoweditinfo::on_radio_Password_button_clicked(bool checked)
{
    if(checked){
        ui->radio_Username_button->setChecked(false);
        ui->radio_Email_button->setChecked(false);
        ChangeChosen=2;
    }
}


void MainWindoweditinfo::on_radio_Email_button_clicked(bool checked)
{
    if(checked){
        ui->radio_Username_button->setChecked(false);
        ui->radio_Password_button->setChecked(false);
        ChangeChosen=3;
    }
}


void MainWindoweditinfo::on_radio_Password_button_clicked()
{

}
