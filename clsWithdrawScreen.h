#pragma once
#include <iostream>
#include "clsBankclinte.h";
#include "clsScreen.h"
#include"clsAddNewClientScreen.h"
#include "C:\Users\TOP 10\source\repos\Input & Validation Library\Input & Validation Library\clsInputValidation.h";
#include"clsMainScreen.h"
using namespace std;

class clsWithdrawScreen : public clsScreen
{
public:
    static void WithdrawClient()
    {
        string title = "\t Withdraw Client Screen\t";
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

        double withdrawAmount = 0;
        cout << "\nPlease enter the withdrawal amount: ";
        withdrawAmount = clsInputValidate::ReadIntNumber();

        char confirmWithdraw = 'n';
        cout << "Are you sure you want to perform this transaction? [y/n]: ";
        cin >> confirmWithdraw;

        if (confirmWithdraw == 'y' || confirmWithdraw == 'Y')
        {
            Client1.Withdraw(withdrawAmount);
            cout << "\nWithdrawal successful. The new balance is: " << Client1.AccountBalance << "\n";
        }
        else
        {
            cout << "\nTransaction cancelled.\n";
        }
    }
};