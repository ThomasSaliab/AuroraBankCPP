#pragma once
#include <iostream>
#include<string>
#include "clsScreen.h"
#include "C:\Users\TOP 10\source\repos\Input & Validation Library\Input & Validation Library\clsInputValidation.h";
#include <iomanip>
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeletUser.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
using namespace std;
class clsManageUsersScreen:public clsScreen
{

private:
    enum enMainMenueUser
    {
        eListUser = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, MainMenue =6
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowManageUsersScreen();
    }

    static void _ShowAllUserScreen()
    {
       
        clsListUsersScreen::PrintAllusersData();

    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::AddUser();
    }

    static void _ShowDeleteUserScreen()
    {
        //  cout << "\nDelete Client Screen Will be here...\n"; clsDeleteClientScreen::DeleteClient();
        clsDeletUser::DeleteUser();
    }

    static void _ShowUpdateUserScreen()
    {
        // cout << "\nUpdate Client Screen Will be here...\n";

        clsUpdateUserScreen::UpdateUser();

    }

    static void _ShowFindUserScreen()
    {
        //  cout << "\nFind Client Screen Will be here...\n";
        clsFindUserScreen::ShowFindUserScreen();
    }

    

   

    static void _PerfromMainMenueOption(enMainMenueUser MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueUser::eListUser:
        {
            system("cls");
            _ShowAllUserScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueUser::eAddNewUser:
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueUser::eDeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueUser::eUpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueUser::eFindUser:
            system("cls");
            _ShowFindUserScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueUser::MainMenue:
            system("cls");
            break;

        }

    }



public:


    static void ShowManageUsersScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;// this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("\t\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tManage Users Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(40) << left << "" << "\t[1] Show Users List.\n";
        cout << setw(40) << left << "" << "\t[2] Add New Users.\n";
        cout << setw(40) << left << "" << "\t[3] Delete Users.\n";
        cout << setw(40) << left << "" << "\t[4] Update Users Info.\n";
        cout << setw(40) << left << "" << "\t[5] Find Users.\n";
        cout << setw(40) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueUser)_ReadMainMenueOption());
    }

};

