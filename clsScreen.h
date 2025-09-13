#pragma once
#include <iostream>
#include"clsBankclinte.h"
#include"clsPrepareUserClass.h"
#include"CurrentUser.h"
#include"C:\Users\TOP 10\source\repos\My Libraries Date\My Libraries Date\clsDate.h"
using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t=====================================";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t=====================================\n\n";
        cout << "\t\t\t\t\t User Name : " << CurrentUser.UserName << endl;
        clsDate Date1;
        cout << "\t\t\t\t\t Date: " << Date1.DateToString() << "\t\tTime: " << clsDate::showCurrentTime() << "\n";
       
     

        
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }





    static void PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " <<Client. firstName;
        cout << "\nLastName    : " <<Client. lastName;
        cout << "\nFull Name   : " <<Client. fullName();
        cout << "\nEmail       : " <<Client. email;
        cout << "\nPhone       : " <<Client. phone;
        cout << "\nAcc. Number : " <<Client.AccountNumber();
        cout << "\nPassword    : " <<Client.PinCode;
        cout << "\nBalance     : " <<Client.AccountBalance;
        cout << "\n___________________\n";

    }


    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.firstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.lastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadIntNumber();
    }


   

    static void _ReadUsersInfo(clsUser& Users)
    {
        cout << "\nEnter FirstName: ";
        Users.firstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Users.lastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Users.email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Users.phone = clsInputValidate::ReadString();

        cout << "\nEnter password: ";
        Users.Password = clsInputValidate::ReadString();

        cout << "\nEnter permissions: ";
        Users.Permissions = inputpermsis();
    }
   


    static void PrintUsre(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n_________________________";
        cout << "\nFirstName      : " << User.firstName;
        cout << "\nLastName       : " << User.lastName;
        cout << "\nFull Name      : " << User.fullName();
        cout << "\nEmail          : " << User.email;
        cout << "\nPhone          : " << User.phone;
        cout << "\nUser Namer     : " << User.UserName;
        cout << "\nPassword       : " << (User.Password);
        cout << "\nPermissions    : " << User.Permissions;
        cout << "\n_________________________\n";

    }

    static short inputpermsis()
    {
        short sh = 0;
        char y;
        cout << "Show All ? y/n: ";
        cin >> y;
        if (y == 'y' || y == 'Y')
        {
            sh += clsUser::enPermissions::eAll;
            return sh;

        }

        cout << "Show client list? y/n: ";
        cin >> y;
        if (y == 'y' || y == 'Y')
        {
            sh += clsUser::enPermissions::pListClients;

        }

        cout << "Add New Client? y/n: ";
        cin >> y;
        if (y == 'y' || y == 'Y')
        {
            sh += clsUser::enPermissions::pAddNewClient;
        }
        cout << "Delete Client? y/n: ";
        cin >> y;
        if (y == 'y' || y == 'Y')
        {
            sh += clsUser::enPermissions::pDeleteClient;
        }
        cout << "Update Client? y/n: ";
        cin >> y;
        if (y == 'y' || y == 'Y')
        {
            sh += clsUser::enPermissions::pUpdateClients;
        }
        cout << "Search Client? y/n: ";
        cin >> y;
        if (y == 'y' || y == 'Y')
        {
            sh += clsUser::enPermissions::pFindClient;
        }
        cout << "Transactions? y/n: ";
        cin >> y;
        if (y == 'y' || y == 'Y')
        {
            sh += clsUser::enPermissions::pTranactions;
        }

        // Add new permission
        cout << "Manage Users? y/n: ";
        cin >> y;
        if (y == 'y' || y == 'Y')
        {
            sh += clsUser::enPermissions::pManageUsers;
        }
        cout << "Login Register? y/n: ";
        cin >> y;
        if (y == 'y' || y == 'Y')
        {
            sh += clsUser::enPermissions::LoginRegister;
        }
        cout << "Currency? y/n: ";
        cin >> y;
        if (y == 'y' || y == 'Y')
        {
            sh += clsUser::enPermissions::Currency;
        }

        return sh;
    }







};


