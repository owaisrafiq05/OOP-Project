// #ifndef MAINWINDOWSELLER2_H
// #define MAINWINDOWSELLER2_H

// #include <QMainWindow>

// namespace Ui {
// class MainWindowSELLER2;
// }

// class MainWindowSELLER2 : public QMainWindow
// {
//     Q_OBJECT

// public:
//     explicit MainWindowSELLER2(QWidget *parent = nullptr);
//     ~MainWindowSELLER2();

// private:
//     Ui::MainWindowSELLER2 *ui;
// };

// #endif // MAINWINDOWSELLER2_H

#ifndef MAINWINDOWSELLER2_H
#define MAINWINDOWSELLER2_H

#include <QMainWindow>

namespace Ui {
class MainWindowSELLER2;
}

class MainWindowSELLER2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowSELLER2(QWidget *parent = nullptr);
    ~MainWindowSELLER2();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindowSELLER2 *ui;
};

#endif // MAINWINDOWSELLER2_H
