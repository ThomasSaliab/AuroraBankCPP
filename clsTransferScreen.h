#pragma once
#include <iostream>
#include "clsBankclinte.h";
#include "clsScreen.h"
#include"clsAddNewClientScreen.h"
#include "C:\Users\TOP 10\source\repos\Input & Validation Library\Input & Validation Library\clsInputValidation.h";
#include"clsMainScreen.h"
#include"clsCreateTransferLog.h"
#include"CurrentUser.h"
using namespace std;
class clsTransferScreen : public clsScreen
{

    static void PrintClien(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        
        cout << "\nFull Name   : " << Client.fullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
public:
    static void TransferClient()
    {
        string title = "\t Transfer Client Screen\t";
        _DrawScreenHeader(title);

        string SourceAccountNumber = "";
        string DestinationAccountNumber = "";


        cout << "\nPlease enter client's account number (Source): ";
        SourceAccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(SourceAccountNumber))
        {
            cout << "\nAccount number [" << SourceAccountNumber << "] is not found. Please choose another one: ";
            SourceAccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(SourceAccountNumber);
        PrintClien(Client1);

        cout << "\nPlease enter client's account number (Destination): ";
        DestinationAccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(DestinationAccountNumber) || DestinationAccountNumber == SourceAccountNumber)
        {
            cout << "\nAccount number [" << DestinationAccountNumber << "] is not found or is the same as the source account. Please choose another one: ";
            DestinationAccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client2 = clsBankClient::Find(DestinationAccountNumber);
        PrintClien(Client2);

        double transferAmount = 0;
        cout << "\nPlease enter the transfer amount: ";
        transferAmount = clsInputValidate::ReadIntNumber();
        
        // Check for sufficient balance
        if (transferAmount > Client1.AccountBalance)
        {
            cout << "\nTransfer cancelled. The source account balance is not sufficient.\n";
            return; 
        }

        char confirmTransfer = 'n';
        cout << "Are you sure you want to perform this transaction? [y/n]: ";
        cin >> confirmTransfer;

        if (confirmTransfer == 'y' || confirmTransfer == 'Y')
        {
            Client1.Withdraw(transferAmount);
            Client2.Deposit(transferAmount);
            
            clsCreateTransferLog::SaveLogin(Client1.AccountNumber(), Client2.AccountNumber(), 
                transferAmount, Client1.AccountBalance, Client2.AccountBalance, CurrentUser.UserName);
            cout << "\nTransfer successful.\n";
            PrintClien(Client1);
            PrintClien(Client2);
        }
        else
        {
            cout << "\nTransaction cancelled.\n";
        }
    }
};