#pragma once

#include <iostream>
#include "clsBankclinte.h";
#include "clsScreen.h"
#include"clsAddNewClientScreen.h"
#include "C:\Users\TOP 10\source\repos\Input & Validation Library\Input & Validation Library\clsInputValidation.h";
#include"clsMainScreen.h"
using namespace std;



class clsDepositScreen:public clsScreen
{

public:
    static void DepositClient()
    {
        string title = "\t Deposit Client Screen\t";
        _DrawScreenHeader(title);

        string AccountNumber = "";

        cout << "\nPlease enter client's account number: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number [" << AccountNumber << "] is not found. Please choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        PrintClient(Client1);

        double depositAmount = 0;
        cout << "\nPlease enter the deposit amount: ";
        depositAmount = clsInputValidate::ReadIntNumber();

        char confirmDeposit = 'n';
        cout << "Are you sure you want to perform this transaction? [y/n]: ";
        cin >> confirmDeposit;

        if (confirmDeposit == 'y' || confirmDeposit == 'Y')
        {
            Client1.Deposit(depositAmount);
            cout << "\nDeposit successful. The new balance is: " << Client1.AccountBalance << "\n";
        }
        else
        {
            cout << "\nTransaction cancelled.\n";
        }
    }

};

