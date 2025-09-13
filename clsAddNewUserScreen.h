#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsPrepareUserClass.h"

class clsAddNewUserScreen:public clsScreen
{


public:
    static  void AddUser()
    {


        string titel = "\tAdd New user Screen\n";
        clsScreen::_DrawScreenHeader(titel);


        string AccountNumber = "";

        cout << "\nPlease Enter user Name: ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(AccountNumber))
        {
            cout << "\nUser Namer Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsUser Client1 = clsUser::GetAddNewUserObject(AccountNumber);



        _ReadUsersInfo(Client1);

        clsUser::enSaveResults SaveResult;

        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            PrintUsre(Client1);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case  clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;


        }

        }
    }




};

