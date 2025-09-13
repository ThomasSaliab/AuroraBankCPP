#pragma once
#include <iostream>
#include "clsBankclinte.h";
#include "clsScreen.h"
#include"clsAddNewClientScreen.h"
using namespace std;

class clsFindClientScreen :public clsScreen
{

   
    public:

        static  void ShowFindClientScreen()
        {
            if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
            {
                return;// this will exit the function and it will not continue
            }
            string titel = "\t Find Client Screen\t";
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
          

            if (!Client1.IsEmpty())
            {

                cout << "\nFund Client :-)\n";


            }
            else
            {
                cout << "\naClient was not fund \n";
            }

            PrintClient(Client1);
        }




    


};

