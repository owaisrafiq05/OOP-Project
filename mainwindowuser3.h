#ifndef MAINWINDOWUSER3_H
#define MAINWINDOWUSER3_H

#include <QMainWindow>

namespace Ui {
class MainWindowUSER3;
}

class MainWindowUSER3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowUSER3(QWidget *parent = nullptr);
    ~MainWindowUSER3();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindowUSER3 *ui;
};

#endif // MainWindowUSER3_H
