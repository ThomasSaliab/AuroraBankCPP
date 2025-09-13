#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsCreateTransferLog.h"


class clsShowTransfersLogScreen:public clsScreen
{


    static void PrintUserRecord(clsCreateTransferLog& User)
    {
        cout << "| "<< setw(18) << left << User.Date
            << "| " << setw(15) << left << User.SAcct// تم تعديل العرض إلى 20
            << "| " << setw(15) << left << User.dAcct
            << "| " << setw(15) << left << User.Amonth
            << "| " << setw(15) << left << User.sBalance
            << "| " << setw(15) << left << User.dBalance
            << "| " << setw(15) << left << User.User << '\n';
    }

public:

    static void PrintAllusersData()
    {


        if (!CheckAccessRights(clsUser::enPermissions::LoginRegister))
        {
            return;// this will exit the function and it will not continue
        }
        vector<clsCreateTransferLog> vUsers = clsCreateTransferLog::GetUsersList();

        string tital = "\t  Show Transfers Log Screen\t";
        string suptitel = "\n\t\t\t\t\t\t (" + to_string(vUsers.size()) + ") users(s)";
        clsScreen::_DrawScreenHeader(tital, suptitel);

        cout << "\n------------------------------------------------------------------------------------------------------------------------";

        cout << "| " << left << setw(18) << "Date";
        cout << "| " << left << setw(15) << " S.Acct";
        cout << "| " << left << setw(15) << "D.Acct";
        cout << "| " << left << setw(15) << "Amonth";
        cout << "| " << left << setw(15) << "S.Balance";
        cout << "| " << left << setw(15) << "D.Balance";
        cout << "| " << left << setw(15) << "User";

        cout << "\n------------------------------------------------------------------------------------------------------------------------";

        if (vUsers.empty())
            cout << "\t\t\t\tNo Users Available In the System!\n";
        else
        {
            for (clsCreateTransferLog& Users : vUsers)
            {
                PrintUserRecord(Users);
            }
        }

        cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
    }
};

