#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

static int countExistingUsers() {
    QFile checkUsers("Login_Data.txt");
    int countUsers = 0;
    QString checkingString;

    if (checkUsers.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&checkUsers);
        while (!in.atEnd()) {
            checkingString = in.readLine();
            if (checkingString == "_________________________________ USER __________________________________")
                break;
        }

        while (!in.atEnd()) {
            checkingString = in.readLine();
            if (checkingString == "############################")
                countUsers++;
        }

        checkUsers.close();
    }
    return countUsers;
}
class SignUp {
private:
    int userId;
    QString usernameComplete="Username: ", passwordComplete="Password: ", email, searchingString1, searchingString2;

public:
    SignUp() {

        userId = countExistingUsers() +1;

        qDebug() << userId;
    }

    bool signup(const QString& enteredUsername, const QString& enteredPassword, const QString& enteredEmail, int userType) {
        bool properlyWorking = true;

        usernameComplete += enteredUsername;
        passwordComplete += enteredPassword;
        email = enteredEmail;

        switch(userType) {
        case 1:
            properlyWorking = userSignUp();
            break;
        case 2:
            properlyWorking = sellerSignUp();
            break;
        default:
            return false;
        }
        return properlyWorking;
    }

    bool userSignUp() {
        temporaryFileOfUser();

        QFile dataFile("Login_Data.txt");
        QFile temp("temporary.txt");
        if (dataFile.open(QIODevice::WriteOnly | QIODevice::Text) && temp.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream out(&dataFile);
            QTextStream in(&temp);
            while (!in.atEnd()) {
                searchingString1 = in.readLine();
                out << searchingString1 << "\n";
            }
            temp.close();

            if (!temp.remove()) {
                qDebug() << "Failed to delete temporary file.";
            }
            dataFile.close();
            return true;
        }else{
            qDebug() << "Failed to open files for writing.";
            return false;
        }
    }

    void temporaryFileOfUser() {
        bool copyingFlag = false;
        QFile dataFile("Login_Data.txt");
        QFile temp("temporary.txt");

        if (dataFile.open(QIODevice::ReadOnly | QIODevice::Text) && temp.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream in(&dataFile);
            QTextStream out(&temp);

            while (!in.atEnd()) {
                searchingString2 = in.readLine();

                //going to the required section of the file

                if (searchingString2 == "_________________________________ USER __________________________________" || copyingFlag) {


                    //this is the line to skip
                    if (searchingString2 == "_________________________________________________________________________") {
                        copyingFlag = false;
                        break;
                    }
                    out << searchingString2 << "\n";
                    copyingFlag = true;
                }

                if (!copyingFlag) {
                    out << searchingString2 << "\n";
                }
            }

            //this is the data to add instead of the line
            out << "######### User " << userId << "  #########" << "\n";
            out << usernameComplete << "\n";
            out << passwordComplete << "\n";
            out << "Email: " << email << "\n";
            out << "############################" << "\n";
            out << "\n" << "\n" << "_________________________________________________________________________" << "\n";

            while (!in.atEnd()) {
                searchingString2 = in.readLine();
                out << searchingString2 << "\n";
            }

            dataFile.close();
            temp.close();
        } else {
            qDebug() << "Failed to open files for reading and writing.";
        }
    }

    bool sellerSignUp() {
        temporaryFileOfSeller();

        QFile dataFile("Login_Data.txt");
        QFile temp("temporary.txt");
        if (dataFile.open(QIODevice::WriteOnly | QIODevice::Text) && temp.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream out(&dataFile);
            QTextStream in(&temp);
            while (!in.atEnd()) {
                searchingString1 = in.readLine();
                out << searchingString1 << "\n";
            }
            temp.close();
            if (!temp.remove()) {
                qDebug() << "Failed to delete temporary file.";
            }
            dataFile.close();
            return true;
        } else {
            qDebug() << "Failed to open files for writing.";
            return false;
        }
    }

    void temporaryFileOfSeller() {
        bool copyingFlag = false;
        QFile dataFile("Login_Data.txt");
        QFile temp("temporary.txt");

        if (dataFile.open(QIODevice::ReadOnly | QIODevice::Text) && temp.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream in(&dataFile);
            QTextStream out(&temp);

            while (!in.atEnd()) {
                searchingString2 = in.readLine();

                if (searchingString2 == "_________________________________ SELLER ________________________________" || copyingFlag) {
                    if (searchingString2 == "_________________________________________________________________________") {
                        copyingFlag = false;
                        break;
                    }
                    out << searchingString2 << "\n";
                    copyingFlag = true;
                }

                if (!copyingFlag) {
                    out << searchingString2 << "\n";
                }
            }

            out <<"\n"<< "######### Seller " << userId << "  #########" << "\n";
            out << usernameComplete << "\n";
            out << passwordComplete << "\n";
            out << "Email: " << email << "\n";
            out << "############################" << "\n";
            out << "\n" << "\n" << "_________________________________________________________________________" << "\n";

            dataFile.close();
            temp.close();
        } else {
            qDebug() << "Failed to open files for reading and writing.";
        }
    }
};

class Login {
    int id;
    QString Password_complete = "Password: ", Email_complete = "Email: ", searching_string1 = "", searching_string2;
    bool email_matched = false, password_matched = false;
public:

    int DO_login(QString Entered_Email, QString Entered_Password, int type)
    {
        Password_complete += Entered_Password;
        Email_complete += Entered_Email;
        switch(type) {
        case 1:
            id = Login_User(Email_complete, Password_complete);
            break;
        case 2:
            id = Login_Seller(Email_complete, Password_complete);
            break;
        case 3:
            id = Login_Admin(Email_complete, Password_complete);
            break;
        default:
            id = -1;
        }
        return id;
    }

    int Login_User(QString Email_complete, QString Password_complete)
    {
        QFile CheckUser("Login_Data.txt");
        if (!CheckUser.open(QIODevice::ReadOnly | QIODevice::Text))
            return -1;

        QTextStream in(&CheckUser);
        while (!in.atEnd()) {
            searching_string1 = in.readLine();
            if (searching_string1 == "_________________________________ USER __________________________________")
                break;
        }

        QString stringId;
        while (searching_string1 != "_________________________________________________________________________") {
            searching_string1 = in.readLine();
            if (searching_string1.startsWith("######### User ")) {
                stringId = searching_string1.mid(15, 1);
                id = stringId.toInt();
            }

            if (searching_string1 == Password_complete)
                password_matched = true;

            if (searching_string1 == "############################") {
                email_matched = false;
                password_matched = false;
            }

            if (searching_string1 == Email_complete && password_matched) {
                email_matched = true;
                CheckUser.close();
                return id;
            }
        }
        CheckUser.close();
        if (email_matched && password_matched)
            return id;
        else
            return -1;
    }

    int Login_Seller(QString Email_complete, QString Password_complete) {
        QFile CheckSeller("Login_Data.txt");
        if (!CheckSeller.open(QIODevice::ReadOnly | QIODevice::Text))
            return -1;

        QTextStream in(&CheckSeller);
        while (!in.atEnd()) {
            searching_string1 = in.readLine();
            if (searching_string1 == "_________________________________ SELLER ________________________________")
                break;
        }

        QString stringId;
        while (searching_string1 != "_________________________________________________________________________") {
            searching_string1 = in.readLine();
            if (searching_string1.startsWith("######### Seller ")) {
                stringId = searching_string1.mid(17, 1);
                id = stringId.toInt();
            }

            if (searching_string1 == Password_complete)
                password_matched = true;

            if (searching_string1 == "############################") {
                email_matched = false;
                password_matched = false;
            }

            if (searching_string1 == Email_complete && password_matched) {
                email_matched = true;
                CheckSeller.close();
                return id;
            }
        }
        CheckSeller.close();
        if (email_matched && password_matched)
            return id;
        else
            return -1;
    }

    int Login_Admin(QString Email_complete, QString Password_complete) {
        QFile CheckAdmin("Login_Data.txt");
        if (!CheckAdmin.open(QIODevice::ReadOnly | QIODevice::Text))
            return -1;

        QTextStream in(&CheckAdmin);

        while (searching_string1 != "_________________________________________________________________________") {
            searching_string1 = in.readLine();
            if (searching_string1 == Password_complete)
                password_matched = true;

            if (searching_string1 == "############################") {
                email_matched = false;
                password_matched = false;
            }

            if (searching_string1 == Email_complete && password_matched) {
                CheckAdmin.close();
                email_matched = true;
                return 0;
            }
        }
        CheckAdmin.close();
        if (email_matched && password_matched)
            return 0;
        else
            return -1;
    }
};


