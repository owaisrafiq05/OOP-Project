#ifndef MAINWINDOWADM2_H
#define MAINWINDOWADM2_H

#include <QMainWindow>

namespace Ui {
class MainWindowadm2;
}

class MainWindowadm2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowadm2(QWidget *parent = nullptr);
    ~MainWindowadm2();

private slots:
    void on_pushButton_save_adm2_clicked();
    void on_pushButton_back_adm2_clicked();

private:
    Ui::MainWindowadm2 *ui;
};

#endif // MAINWINDOWADM2_H
