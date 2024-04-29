// #ifndef MAINWINDOWSELLER4_H
// #define MAINWINDOWSELLER4_H

// #include <QMainWindow>

// namespace Ui {
// class MainWindowSELLER4;
// }

// class MainWindowSELLER4 : public QMainWindow
// {
//     Q_OBJECT

// public:
//     explicit MainWindowSELLER4(QWidget *parent = nullptr);
//     ~MainWindowSELLER4();

// private:
//     Ui::MainWindowSELLER4 *ui;
// };

// #endif // MAINWINDOWSELLER4_H

#ifndef MAINWINDOWSELLER4_H
#define MAINWINDOWSELLER4_H
#include"mainwindowSELLER.h"

#include <QMainWindow>

namespace Ui {
class MainWindowSELLER4;
}

class MainWindowSELLER4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowSELLER4(QWidget *parent = nullptr);
    ~MainWindowSELLER4();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindowSELLER4 *ui;
    void removeLines(int lineNumber, int iterations);
};

#endif // MAINWINDOWSELLER4_H
