#pragma once
#include <iostream>
#include "clsScreen.h"
#include"C:\Users\TOP 10\source\repos\Currency Object\Currency Object\clsPrepareCurrency.h"
#include "C:\Users\TOP 10\source\repos\Input & Validation Library\Input & Validation Library\clsInputValidation.h";

class clsCurrencyCalculatorScreen:public clsScreen
{
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }
    static void _PrintCurren()
    {
        system("cls");
        CalculatorCurrency();
    }


public:
    static void CalculatorCurrency()
    {
        string sourceCurrencyCode = "";
        string destinationCurrencyCode = "";

        cout << "\nPlease Enter The Source Currency Code: \n";
        sourceCurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(sourceCurrencyCode))
        {
            cout << "\nCurrency is not found, please choose another one: ";
            sourceCurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency sourceCurrency = clsCurrency::FindByCode(sourceCurrencyCode);

        cout << "\nPlease Enter The Destination Currency Code: \n";
        destinationCurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(destinationCurrencyCode))
        {
            cout << "\nCurrency is not found, please choose another one: ";
            destinationCurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency destinationCurrency = clsCurrency::FindByCode(destinationCurrencyCode);

        double amountToConvert = 0;
        cout << "Please Enter The Amount To Convert:\n";
        cin >> amountToConvert;

        float sourceRate = sourceCurrency.Rate();
        float destinationRate = destinationCurrency.Rate();

        _PrintCurrency(sourceCurrency);

        cout << amountToConvert << " " << sourceCurrencyCode << " = " << clsCurrency::ConvertToUSD(amountToConvert, sourceRate) << " $" << "\n";
        _PrintCurrency(destinationCurrency);

        cout << amountToConvert << " " << sourceCurrencyCode << " = " << clsCurrency::ConvertFrom(amountToConvert, destinationRate, sourceRate) << " " << destinationCurrencyCode << "\n";

        char userChoice;
        cout << "Do you want to perform another conversion? (y/n): ";
        cin >> userChoice;

        if (userChoice == 'y' || userChoice == 'Y')
        {
            _PrintCurren();
        }


    }

        
	








};

