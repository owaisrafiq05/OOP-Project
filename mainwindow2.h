#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();
private slots:
    void on_CheckBox_Terms_and_conditions_2_stateChanged(int arg1);

    void on_Button_Sign_up_clicked();

    void on_CheckBox_Terms_and_conditions_stateChanged(int arg1);

private:
    Ui::MainWindow2 *ui;
};

#endif // MAINWINDOW2_H
