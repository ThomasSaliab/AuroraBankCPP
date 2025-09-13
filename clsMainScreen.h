#pragma once


#include <iostream>
#include<string>
#include "clsScreen.h"
#include "C:\Users\TOP 10\source\repos\Input & Validation Library\Input & Validation Library\clsInputValidation.h";
#include <iomanip>
#include"clsListClientsScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersScreen.h"
#include"CurrentUser.h"
#include"clsShowLoginRegiste.h"
#include"clsCurrency.h"
using namespace std;

class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueUser {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, LoginRegister =8, PrepareCurrency=9,
        eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
     

        clsListClientsScreen::PrintAllClientsData();


    }

    static void _ShowAddNewClientsScreen()
    {
        
        clsAddNewClientScreen::AddClient();

    }

    static void _ShowDeleteClientScreen()
    {
        
        clsDeleteClientScreen::DeleteClient();

    }

    static void _ShowUpdateClientScreen()
    {
      
       // cout << "\nUpdate Client Screen Will be here...\n";

        clsUpdateClientScreen::UpdateClient();

    }

    static void _ShowFindClientScreen()
    {
       
      //  cout << "\nFind Client Screen Will be here...\n";
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
       
      //  cout << "\nTransactions Menue Will be here...\n";

        clsTransactionsScreen::printTransactionsScreen();

    }
   
    static void _ShowManageUsersMenue() {
       
        clsManageUsersScreen::ShowManageUsersScreen();
    }
    static void _ShowLoginRegiste()
    {

        clsShowLoginRegiste::PrintAllusersData();
       
    }
    static void _ShowPrepareCurrency()
    {

       
        clsCurrencyScr::CurrencyExchange();
    }

    static void _logout()
    {
       // cout << "\nEnd Screen Will be here...\n";

        CurrentUser.Find("", "");


    }

    static void _PerfromMainMenueOption(enMainMenueUser MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueUser::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueUser::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueUser::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueUser::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueUser::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueUser::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueUser::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueUser::LoginRegister:
            system("cls");
            _ShowLoginRegiste();
            _GoBackToMainMenue();
            break;
        case enMainMenueUser::PrepareCurrency:
            system("cls");
            _ShowPrepareCurrency();
            _GoBackToMainMenue();
            break;

        case enMainMenueUser::eExit:
            system("cls");
            _logout();
           
            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(40) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(40) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(40) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(40) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(40) << left << "" << "\t[5] Find Client.\n";
        cout << setw(40) << left << "" << "\t[6] Transactions.\n";
        cout << setw(40) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(40) << left << "" << "\t[8] Login Registe.\n";
        cout << setw(40) << left << "" << "\t[9] Prepare Currency.\n";
        cout << setw(40) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueUser)_ReadMainMenueOption());
    }

};
