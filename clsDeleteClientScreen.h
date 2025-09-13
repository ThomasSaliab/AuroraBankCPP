#pragma once
#include <iostream>
#include "clsBankclinte.h";
#include "clsScreen.h"
#include"clsAddNewClientScreen.h"

using namespace std;

class clsDeleteClientScreen:public clsScreen
{


public:


    static void DeleteClient()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;// this will exit the function and it will not continue
        }
        string titel = "\tDelete Client Screen\t";
        _DrawScreenHeader(titel);
        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        PrintClient(Client1);


        char Ansuar = 'n';
        cout << "Are you Delete Client [y,n]\n";
        cin >> Ansuar;
        if (Ansuar == 'y' || Ansuar == 'Y')
        {
            if (Client1.DeletClient())
            {

                cout << "\nDelete Client Successfully :-)\n";
                PrintClient(Client1);

            }
            else
            {
                cout << "\nError account was not Delete Client it's Empty";
            }



        }



    }
};

