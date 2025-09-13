#pragma once
#include <iostream>
#include "clsScreen.h"
#include"C:\Users\TOP 10\source\repos\Currency Object\Currency Object\clsPrepareCurrency.h"

class clsCurrenciesListScreen :public clsScreen
{


        static void PrintCountryRecord(clsCurrency& User)
        {
            cout <<"| "<< setw(35) << left << User.Country()
                << "| " << setw(15) << left << User.CurrencyCode() // تم تعديل العرض إلى 20
                << "| " << setw(40) << left << User.CurrencyName()
                << "| " << setw(20) << left << User.Rate() << '\n';
        }

    public:

        static void PrintAllCountry()
        {
            vector<clsCurrency> vUsers = clsCurrency::GetCurrenciesList();

            string tital = "\t Currencies List Screen\t";
            string suptitel = "\n\t\t\t\t\t\t (" + to_string(vUsers.size()) + ") users(s)";
            clsScreen::_DrawScreenHeader(tital, suptitel);

            cout << "\n---------------------------------------------------------------------------------------------------------------------\n";

            cout << "| " << left << setw(35) << "Country";
            cout << "| " << left << setw(15) << "Code";
            cout << "| " << left << setw(40) << "Name";
            cout << "| " << left << setw(20) << "Rate";
            cout << "\n---------------------------------------------------------------------------------------------------------------------\n";

            if (vUsers.empty())
                cout << "\t\t\t\tNo Users Available In the System!\n";
            else
            {
                for (clsCurrency& Users : vUsers)
                {
                    PrintCountryRecord(Users);
                }
            }

            cout << "\n---------------------------------------------------------------------------------------------------------------------\n";
        }


};

