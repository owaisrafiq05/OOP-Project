#ifndef MAINWINDOWADM_H
#define MAINWINDOWADM_H

#include <QMainWindow>

namespace Ui {
class MainWindowadm;
}

class MainWindowadm : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowadm(QWidget *parent = nullptr);
    ~MainWindowadm();

private slots:
    void on_Button_Edit_Data_clicked();

    void on_Button_Remove_Product_clicked();

    void on_btn_log_out_clicked();

private:
    Ui::MainWindowadm *ui;

};

#endif // MAINWINDOWADM_H
