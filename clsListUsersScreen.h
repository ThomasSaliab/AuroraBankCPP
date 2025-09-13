
#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsPrepareUserClass.h"

class clsListUsersScreen :public clsScreen
{
   
   
    

        static void PrintUserRecord(clsUser& User)
        {
            cout<< "| " << setw(15) << left << User.UserName
                << "| " << setw(20) << left << User.fullName() // تم تعديل العرض إلى 20
                << "| " << setw(15) << left << User.phone
                << "| " << setw(19) << left << User.email
                << "| " << setw(12) << left << User.Password
                << "| " << setw(21) << left << fixed << setprecision(2) << User.Permissions << '\n';
        }

    public:

        static void PrintAllusersData()
        {
            vector<clsUser> vUsers = clsUser::GetUsersList();

            string tital = "\tUsers List\t";
            string suptitel = "\n\t\t\t\t\t\t (" + to_string(vUsers.size()) + ") users(s)";
            clsScreen::_DrawScreenHeader(tital, suptitel);

            cout << "\n---------------------------------------------------------------------------------------------------------------------\n";

            cout << "| " << left << setw(15) << "User Name";
            cout << "| " << left << setw(20) << "full Name";
            cout << "| " << left << setw(15) << "Phone";
            cout << "| " << left << setw(19) << "Email";
            cout << "| " << left << setw(12) << "password";
            cout << "| " << left << setw(21) << "permissions";
            cout << "\n---------------------------------------------------------------------------------------------------------------------\n";

            if (vUsers.empty())
                cout << "\t\t\t\tNo Users Available In the System!\n";
            else
            {
                for (clsUser& Users : vUsers)
                {
                    PrintUserRecord(Users);
                }
            }

            cout << "\n---------------------------------------------------------------------------------------------------------------------\n";
        }



    


};

