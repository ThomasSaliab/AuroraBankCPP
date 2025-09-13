#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsPrepareUserClass.h"


class clsDeletUser:public clsScreen
{


    
public:
    static void DeleteUser()
    {
        string titel = "\tDelete User Screen\t";
        _DrawScreenHeader(titel);
        string AccountNumber = "";

        cout << "\nPlease Enter User Name : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(AccountNumber))
        {
            cout << "\n User Name is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsUser Client1 = clsUser::Find(AccountNumber);
        PrintUsre(Client1);


        char Ansuar = 'n';
        cout << "Are you Delete User [y,n]\n";
        cin >> Ansuar;
        if (Ansuar == 'y' || Ansuar == 'Y')
        {
            if (Client1.Delete())
            {

                cout << "\nDelete User Successfully :-)\n";
                PrintUsre(Client1);

            }
            else
            {
                cout << "\nError account was not Delete User it's Empty";
            }



        }



    }

};

