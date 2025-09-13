#pragma once
#include <iostream>
#include "clsBankclinte.h";
#include "clsScreen.h"
#include"clsAddNewClientScreen.h"
#include "C:\Users\TOP 10\source\repos\Input & Validation Library\Input & Validation Library\clsInputValidation.h";
#include"clsMainScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTransferScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsShowTransfersLogScreen.h"
using namespace std;




class clsTransactionsScreen :public clsScreen
{

    static enum _myTransactions
    {
        Deposit = 1, Withdraw = 2, TotalBalances = 3, TransferScreen=4, TransferLog=5,BacktoMainMenu = 6
    };


    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }


    static  void _GoBackToMainMenueTransactions()
    {

        system("pause>0");
        printTransactionsScreen();
    }
    static void _ShowDeposit()
    {
        clsDepositScreen::DepositClient();

    }
    static void _ShowWithdraw()
    {
        clsWithdrawScreen::WithdrawClient();


    }
    static void _ShowTransferClient()
    {

        clsTransferScreen::TransferClient();
    }

    static void _ShowTransfersLogScreen()
    {

        clsShowTransfersLogScreen::PrintAllusersData();
    }
    static void _ShowTotalBalances()
    {

        clsTotalBalancesScreen::ShowTotalBalances();
    }
    
   

    static void  MainMenuTransactions(_myTransactions bn)
    {
        switch (bn)
        {

        case _myTransactions::Deposit:
        {
            system("cls"); 
            _ShowDeposit();
            _GoBackToMainMenueTransactions();
            break;
        }
        case _myTransactions::Withdraw:
            system("cls");
            _ShowWithdraw();
            _GoBackToMainMenueTransactions();
            break;

        case _myTransactions::TotalBalances:

            system("cls");
            _ShowTotalBalances();
            _GoBackToMainMenueTransactions();
            break;
        case _myTransactions::TransferScreen:

            system("cls");
            _ShowTransferClient();       
            _GoBackToMainMenueTransactions();
            break;

        case _myTransactions::TransferLog:

            system("cls");
            _ShowTransfersLogScreen();
            _GoBackToMainMenueTransactions();
            break;

        case _myTransactions::BacktoMainMenu:
            system("cls");
            
            break;

        }
    }



public:
	static void printTransactionsScreen()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }
        system("cls");
        string titel = "\tTransactions Screen\n";
        _DrawScreenHeader(titel);

        cout << setw(40) << left << ""<< "=====================================\n";
        cout << setw(40) << left << ""<< "\t[1] Deposit\n";
        cout << setw(40) << left << ""<< "\t[2] Withdraw\n";
        cout << setw(40) << left << ""<< "\t[3] Total Balances\n";
        cout << setw(40) << left << "" << "\t[4] Trans fer Client\n";
        cout << setw(40) << left << "" << "\t[5] Transfer Log\n";

        cout << setw(40) << left << ""<< "\t[6] Back to Main Menu\n";
        cout << setw(40) << left << ""<< "=====================================\n";


        MainMenuTransactions(_myTransactions(_ReadMainMenueOption()));
	}



};

