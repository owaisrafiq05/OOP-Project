#ifndef MAINWINDOWSELLER_H
#define MAINWINDOWSELLER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindowSELLER;
}
QT_END_NAMESPACE

class MainWindowSELLER : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowSELLER(QWidget *parent = nullptr);
    ~MainWindowSELLER();

private slots:
    void on_pushButtons_clicked();

    void on_pushButtons_2_clicked();

    void on_pushButtons_3_clicked();



    void on_pushButtons_4_clicked();

private:
    Ui::MainWindowSELLER *ui;

};
#endif // MAINWINDOW_H
