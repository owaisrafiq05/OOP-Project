#ifndef MAINWINDOWUSER_H
#define MAINWINDOWUSER_H

#include <QMainWindow>

namespace Ui {
class MainWindowUSER;
}

class MainWindowUSER : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowUSER(QWidget *parent = nullptr);
    ~MainWindowUSER();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindowUSER *ui;
};

#endif // MAINWINDOWUSER_H
