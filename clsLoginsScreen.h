#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPrepareUserClass.h"
#include "clsMainScreen.h"
#include"clsRegisterLoginsInaFile.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{

private:

    static bool _Login()
    {
        bool LoginFailed = false;
        short attempt = 0;
        string Username, Password;

        do
        {
            if (LoginFailed)
            {
                attempt++;

                cout << "\n[Error] Invalid username or password.\n";
                cout << "Attempt " << attempt << " of 3.\n";

                if (attempt == 3)
                {
                    cout << "\nAccess denied. Too many failed attempts.\n";
                    return false;
                }
            }

          
            cout << "Enter username: ";
            cin >> Username;

            cout << "Enter password: ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFailed = CurrentUser.IsEmpty();

        } while (LoginFailed);

        cout << "\nLogin successful. Welcome, " << Username << "!\n";

        clsRegisterLoginsInaFile::SaveLogin(CurrentUser);


        clsMainScreen::ShowMainMenue();
        return true;
    }

public:

    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }
};
