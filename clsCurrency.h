#pragma once
#include <iostream>
#include "clsBankclinte.h";
#include "clsScreen.h"
#include"clsAddNewClientScreen.h"
#include "C:\Users\TOP 10\source\repos\Input & Validation Library\Input & Validation Library\clsInputValidation.h";
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrency.h"
#include"clsUpdateCurrencyRate.h"
#include"clsCurrencyCalculatorScreen.h"
using namespace std;


class clsCurrencyScr:public clsScreen
{

    static enum _MyTransactions
    {
        ListCurrencies = 1,
        FindCurrency = 2,
        UpdateRate = 3,
        CurrencyCalculator = 4,
        BackToMainMenu = 5
    };


    static short _ReadMainMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }


    static void _GoBackToMainMenuTransactions()
    {
        system("pause>0");
        CurrencyExchange();
    }

    static void _ShowListCurrencies()
    {
        clsCurrenciesListScreen::PrintAllCountry();
    }

    static void _ShowFindCurrency()
    {
        clsFindCurrency::printFindCurrency();
    }

    static void _ShowUpdateRate()
    {
        clsUpdateCurrencyRate::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculator()
    {
        clsCurrencyCalculatorScreen::CalculatorCurrency();
    }

    


    static void MainMenuTransactions(_MyTransactions option)
    {
        switch (option)
        {

        case _MyTransactions::ListCurrencies:
        {
            system("cls");
            _ShowListCurrencies();
            _GoBackToMainMenuTransactions();
            break;
        }
        case _MyTransactions::FindCurrency:
            system("cls");
            _ShowFindCurrency();
            _GoBackToMainMenuTransactions();
            break;

        case _MyTransactions::UpdateRate:
            system("cls");
            _ShowUpdateRate();
            _GoBackToMainMenuTransactions();
            break;

        case _MyTransactions::CurrencyCalculator:
            system("cls");
            _ShowCurrencyCalculator();
            _GoBackToMainMenuTransactions();
            break;

        case _MyTransactions::BackToMainMenu:
            system("cls");
            break;
        }
    }



public:
    static void CurrencyExchange()
    {

        if (!CheckAccessRights(clsUser::enPermissions::Currency))
        {
            return; // this will exit the function and it will not continue
        }
        system("cls");
        string title = "\tCurrency Exchange\n";
        _DrawScreenHeader(title);

        cout << setw(40) << left << "" << "=====================================\n";
        cout << setw(40) << left << "" << "\t[1] List Currencies\n";
        cout << setw(40) << left << "" << "\t[2] Find Currency\n";
        cout << setw(40) << left << "" << "\t[3] Update Rate\n";
        cout << setw(40) << left << "" << "\t[4] Currency Calculator\n";
        cout << setw(40) << left << "" << "\t[5] Back to Main Menu\n";
        cout << setw(40) << left << "" << "=====================================\n";

        MainMenuTransactions(_MyTransactions(_ReadMainMenuOption()));
    }

};
