#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsPrepareUserClass.h"

class clsFindUserScreen:public clsScreen
{

public:

    static  void ShowFindUserScreen()
    {
        string titel = "\t Find User Screen\t";
        _DrawScreenHeader(titel);

        string AccountNumber = "";

        cout << "\nPlease Enter  User Name: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(AccountNumber))
        {
            cout << "\nUser Name is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsUser Client1 = clsUser::Find(AccountNumber);


        if (!Client1.IsEmpty())
        {

            cout << "\nFund Users :-)\n";
            PrintUsre(Client1);


        }
        else
        {
            cout << "\naClient was not fund \n";
        }

    }



};

