#pragma once
#include <iostream>
#include "clsBankclinte.h";
#include "clsScreen.h"

using namespace std;


class clsListClientsScreen:public clsScreen
{

   static void PrintClientRecord(clsBankClient& Client)
    {
        cout << "| " << setw(15) << left << Client.AccountNumber()
            << "| " << setw(20) << left << Client.fullName() // تم تعديل العرض إلى 20
            << "| " << setw(15) << left << Client.phone
            << "| " << setw(19) << left << Client.email
            << "| " << setw(12) << left << Client.PinCode
            << "| " << setw(21) << left << fixed << setprecision(2) << Client.AccountBalance << '\n';
    }

public:

    static void PrintAllClientsData()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;// this will exit the function and it will not continue
        }

       
        vector<clsBankClient> vClients = clsBankClient::Getclint();
         
        string tital = "\tClient List\t";
        string suptitel="\n\t\t\t\t\t\t (" + to_string (vClients.size()) + ") Client(s)";
        clsScreen::_DrawScreenHeader(tital, suptitel);

        cout << "\n---------------------------------------------------------------------------------------------------------------------\n";

        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(15) << "Phone";
        cout << "| " << left << setw(19) << "Email";
        cout << "| " << left << setw(12) << "Pin Code";
        cout << "| " << left << setw(21) << "Balance";
        cout << "\n---------------------------------------------------------------------------------------------------------------------\n";

        if (vClients.empty())
            cout << "\t\t\t\tNo Clients Available In the System!\n";
        else
        {
            for (clsBankClient& Client : vClients)
            {
                PrintClientRecord(Client);
            }
        }

        cout << "\n---------------------------------------------------------------------------------------------------------------------\n";
    }



};

