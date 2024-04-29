// #ifndef MAINWINDOWSELLER3_H
// #define MAINWINDOWSELLER3_H

// #include <QMainWindow>

// namespace Ui {
// class MainWindowSELLER3;
// }

// class MainWindowSELLER3 : public QMainWindow
// {
//     Q_OBJECT

// public:
//     explicit MainWindowSELLER3(QWidget *parent = nullptr);
//     ~MainWindowSELLER3();

// private:
//     Ui::MainWindowSELLER3 *ui;
// };

// #endif // MAINWINDOWSELLER3_H

#ifndef MAINWINDOWSELLER3_H
#define MAINWINDOWSELLER3_H

#include <QMainWindow>

namespace Ui {
class MainWindowSELLER3;
}

class MainWindowSELLER3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowSELLER3(QWidget *parent = nullptr);
    ~MainWindowSELLER3();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_name_radio_clicked(bool checked);

    void on_description_radio_clicked(bool checked);

    void on_quantity_radio_clicked(bool checked);

    void on_price_radio_clicked(bool checked);

private:
    Ui::MainWindowSELLER3 *ui;
    bool replaceTextAtLine(const QString& filePath, int lineNumber, const QString& newText);
};

#endif // MAINWINDOWSELLER3_H
