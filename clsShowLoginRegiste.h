#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsRegisterLoginsInaFile.h"
class clsShowLoginRegiste:public clsScreen
{

    static void PrintUserRecord(clsRegisterLoginsInaFile& User)
    {
        cout<< "| " <<setw (25)<< left << User.Date
            << "| " << setw(25) << left << User.name// تم تعديل العرض إلى 20
         
            << "| " << setw(25) << left << clsUtil:: DecryptText(User.Password)
            << "| " << setw(25) << left << (User.Permissions) << '\n';
    }

public:

    static void PrintAllusersData()
    {


        if (!CheckAccessRights(clsUser::enPermissions::LoginRegister))
        {
            return;// this will exit the function and it will not continue
        }
        vector<clsRegisterLoginsInaFile> vUsers = clsRegisterLoginsInaFile::GetUsersList();

        string tital = "\tRegister Logins Ina File List\t";
        string suptitel = "\n\t\t\t\t\t\t (" + to_string(vUsers.size()) + ") users(s)";
        clsScreen::_DrawScreenHeader(tital, suptitel);

        cout << "\n---------------------------------------------------------------------------------------------------------\n";

        cout << "| " << left << setw(25) << "Date";
        cout << "| " << left << setw(25) << " Name";
        cout << "| " << left << setw(25) << "Password";
        cout << "| " << left << setw(25) << "Permissions";
    
        cout << "\n---------------------------------------------------------------------------------------------------------\n";

        if (vUsers.empty())
            cout << "\t\t\t\tNo Users Available In the System!\n";
        else
        {
            for (clsRegisterLoginsInaFile& Users : vUsers)
            {
                PrintUserRecord(Users);
            }
        }

        cout << "\n---------------------------------------------------------------------------------------------------------\n";
    }




};

