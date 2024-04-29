#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

class Admin_Tables {
    QString UniquestringId, searching_string1, Table_Username, Table_Password, Table_Email;
public:
    void update_admin_Table() {
        QFile ForAdminTable("Login_Data.txt");
        QFile Admin_Table_File("Admin_Table.txt");

        if (!ForAdminTable.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Failed to open Login_Data.txt";
            return;
        }

        if (!Admin_Table_File.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        }

        QTextStream in(&ForAdminTable);
        QTextStream out(&Admin_Table_File);

        bool usersSection = false;
        bool sellersSection = false;

        while (!in.atEnd()) {
            searching_string1 = in.readLine();
            if (searching_string1 == "_________________________________ USER __________________________________") {
                usersSection = true;
                sellersSection = false;
                out << "----- USERS -----\n\n";
            }
            else if (searching_string1 == "_________________________________ SELLER ________________________________") {
                usersSection = false;
                sellersSection = true;
                out << "----- SELLERS -----\n\n";
            }
            else if (searching_string1 == "_________________________________________________________________________") {
                usersSection = false;
                sellersSection = false;
            }
            else if (usersSection && searching_string1.contains("######### User ")) {
                UniquestringId = searching_string1.mid(15, 1);
                searching_string1 = in.readLine();
                Table_Username = searching_string1.mid(10);
                searching_string1 = in.readLine();
                Table_Password = searching_string1.mid(10);
                searching_string1 = in.readLine();
                Table_Email = searching_string1.mid(7);
                out << "\n*****\n";
                out << UniquestringId << "\n";
                out << Table_Username << "\n";
                out << Table_Password << "\n";
                out << Table_Email << "\n\n";
            }
            else if (sellersSection && searching_string1.contains("######### Seller ")) {
                UniquestringId = searching_string1.mid(17, 1);
                searching_string1 = in.readLine();
                Table_Username = searching_string1.mid(10);
                searching_string1 = in.readLine();
                Table_Password = searching_string1.mid(10);
                searching_string1 = in.readLine();
                Table_Email = searching_string1.mid(7);
                out << "\n*****\n";
                out << UniquestringId << "\n";
                out << Table_Username << "\n";
                out << Table_Password << "\n";
                out << Table_Email << "\n\n";
            }
        }

        ForAdminTable.close();
        Admin_Table_File.close();
    }
};

struct Tableinfo {
    QString theEmail, theId, thePassword, theUsername;
};

class Add_Data_to_Admin_Table {
public:
    int countUsers = 0, countSellers = 0;

    Add_Data_to_Admin_Table() {
        QFile Admin_Table_File("Admin_Table.txt");

        if (!Admin_Table_File.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return;
        }

        QTextStream in(&Admin_Table_File);
        QString searching_string1;

        while (!in.atEnd()) {
            searching_string1 = in.readLine();
            if (searching_string1 == "----- SELLERS -----") {
                break;
            }
            if (searching_string1 == "*****") {
                countUsers++;
            }
        }

        while (!in.atEnd()) {
            searching_string1 = in.readLine();
            if (searching_string1 == "*****") {
                countSellers++;
            }
        }

        Admin_Table_File.close();
    }
    int Countingi=-1;
    QString searching_string1;

    Tableinfo* User_Data_to_Table()
    {
        Tableinfo *table1 = new Tableinfo[countUsers];
        QFile Admin_Table_File("Admin_Table.txt");
        if (!Admin_Table_File.open(QIODevice::ReadOnly | QIODevice::Text))
            return nullptr;

        int Countingi=-1;
        QTextStream in(&Admin_Table_File);

        while(searching_string1!="----- SELLERS -----")
        {
            searching_string1 = in.readLine();
            if (searching_string1=="*****")
            {Countingi++;
                searching_string1 = in.readLine();
                table1[Countingi].theId= searching_string1;
                searching_string1 = in.readLine();
                table1[Countingi].theUsername=searching_string1;
                searching_string1 = in.readLine();
                table1[Countingi].thePassword=searching_string1;
                searching_string1 = in.readLine();
                table1[Countingi].theEmail=searching_string1;
            }
        }
        return table1;
    }


    Tableinfo* Seller_Data_to_Table()
    {
        Tableinfo *table2 = new Tableinfo[countSellers];
        QFile Admin_Table_File("Admin_Table.txt");
        if (!Admin_Table_File.open(QIODevice::ReadOnly | QIODevice::Text))
            return nullptr;

        int Countingi = -1;
        QTextStream in(&Admin_Table_File);

        // Skip the users' data
        while (!in.atEnd())
        {
            searching_string1 = in.readLine();
            if(searching_string1=="----- SELLERS -----")
                break;
        }


        // Read the sellers' data
        while (!in.atEnd())
        {

            searching_string1 = in.readLine();
            if(searching_string1=="*****")
            {Countingi++;
                searching_string1 = in.readLine();
                table2[Countingi].theId= searching_string1;
                searching_string1 = in.readLine();
                table2[Countingi].theUsername=searching_string1;
                searching_string1 = in.readLine();
                table2[Countingi].thePassword=searching_string1;
                searching_string1 = in.readLine();
                table2[Countingi].theEmail=searching_string1;
            }
        }
        Admin_Table_File.close();
        Admin_Table_File.remove();
        return table2;
    }

    void changeData(int dataToChange, QString idToChangeDataIn, QString GivenData) {
        QFile ForLoginFile("Login_Data.txt");
        QFile Admin_Table_File("Temp_Table_file.txt");

        if (!ForLoginFile.open(QIODevice::ReadOnly | QIODevice::Text) ||
            !Admin_Table_File.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream in(&ForLoginFile);
        QTextStream out(&Admin_Table_File);

        QString place[3], searching_string1;
        while (!in.atEnd()) {
            searching_string1 = in.readLine();
            if (searching_string1.contains("######### ") && searching_string1.contains(idToChangeDataIn)) {
                out << searching_string1 << "\n";
                for (int i = 0; i < 3; ++i)
                    place[i] = in.readLine();

                if (dataToChange == 1) {
                    out << "Username: " << GivenData << "\n";
                    out << place[1] << "\n";
                    out << place[2] << "\n";
                } else if (dataToChange == 2) {
                    out << place[0] << "\n";
                    out << "Password: " << GivenData << "\n";
                    out << place[2] << "\n";
                } else if (dataToChange == 3) {
                    out << place[0] << "\n";
                    out << place[1] << "\n";
                    out << "Email: " << GivenData << "\n";
                }
            } else {
                out << searching_string1 << "\n";
            }
        }

        ForLoginFile.close();
        Admin_Table_File.close();

        QFile LoginFile("Login_Data.txt");
        QFile Admin_Temp_File("Temp_Table_file.txt");

        if (!LoginFile.open(QIODevice::WriteOnly | QIODevice::Text) ||
            !Admin_Temp_File.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream inTemp(&Admin_Temp_File);
        QTextStream outLogin(&LoginFile);

        while (!inTemp.atEnd()) {
            outLogin << inTemp.readLine() << "\n";
        }

        LoginFile.close();
        Admin_Temp_File.close();
        Admin_Table_File.remove();
    }
};
