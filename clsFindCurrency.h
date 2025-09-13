#pragma once
#include <iostream>
#include "clsScreen.h"
#include"C:\Users\TOP 10\source\repos\Currency Object\Currency Object\clsPrepareCurrency.h"

class clsFindCurrency:public clsScreen
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
	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}

public:
  static void printFindCurrency()
  {

	  system("cls");
	  string title = "\tFind Exchange\n";
	  _DrawScreenHeader(title);
	  short i = 0;
	 cout << "find By {code[1]or Contry [2]}\n";
	 cin >> i;


	 switch (i)
	 {
	 case 1:
	 {
		 string Code;
		 cout << "plese enter Code Contry : ";
		 cin >> Code;
		 clsCurrency Code1= clsCurrency::FindByCode(Code);

		 _ShowResults(Code1);

		 break;

	 }
	 case 2:
	 {
		 string Contry;
		 cout << "plese enter  Contry : ";
		 cin >> Contry;
		 clsCurrency Contry1= clsCurrency::FindByCountry(Contry);
		 _ShowResults(Contry1);
		 break;
	 }

	 }
  }

};

