#ifndef MAINWINDOWEDITINFO_H
#define MAINWINDOWEDITINFO_H

#include <QMainWindow>

namespace Ui {
class MainWindoweditinfo;
}

class MainWindoweditinfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindoweditinfo(QWidget *parent = nullptr);
    ~MainWindoweditinfo();

private slots:
    void on_pushButton_SaveTheChange_clicked();

    void on_radio_Username_button_clicked(bool checked);

    void on_radio_Password_button_clicked(bool checked);

    void on_radio_Email_button_clicked(bool checked);

    void on_radio_Password_button_clicked();

private:
    Ui::MainWindoweditinfo *ui;
};

#endif // MAINWINDOWEDITINFO_H
