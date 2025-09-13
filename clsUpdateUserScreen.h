#pragma once
#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsPrepareUserClass.h"

class clsUpdateUserScreen:public clsScreen
{




public:

    static  void UpdateUser()
    {
        string titel = "\t Update User Screen\t";
        _DrawScreenHeader(titel);

        string AccountNumber = "";

        cout << "\nPlease Enter User Name: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(AccountNumber))
        {
            cout << "\nUser Name is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsUser Client1 = clsUser::Find(AccountNumber);
        PrintUsre(Client1);
        char y = 'n';
        cout << "you are Update User y/n: ";
        cin >> y;
        if (y == 'y' || y == 'Y')
        {
            cout << "\n\nUpdate User  Info:";
            cout << "\n____________________\n";


            _ReadUsersInfo(Client1);

            clsUser::enSaveResults SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";
                PrintUsre(Client1);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }



        }
       
    }











};

