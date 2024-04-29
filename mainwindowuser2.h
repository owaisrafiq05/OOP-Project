#ifndef MainWindowUSER2_H
#define MainWindowUSER2_H

#include <QMainWindow>

namespace Ui {
class MainWindowuser2;
}

class MainWindowuser2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowuser2(QWidget *parent = nullptr);
    ~MainWindowuser2();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindowuser2 *ui;
    QString getTextFromLine(int lineNumber);
    bool replaceTextAtLine(const QString& filePath, int lineNumber, const QString& newText);
};

#endif // MainWindowUSER2_H
