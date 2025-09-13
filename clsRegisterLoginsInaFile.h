#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include"C:\Users\TOP 10\source\repos\My Libraries Date\My Libraries Date\clsDate.h"
#include "clsPrepareUserClass.h" // نفترض انه بيعرف CurrentUser أو تقدر تمرر user كـ parameter
#include <filesystem>

using namespace std;

const string LoginFile = "LoginFile.txt";

class clsRegisterLoginsInaFile
{
private:


    string _DateTime;
    string _name;
    string _Password;
    int _Permissions;




    static string FormatLoginEntry( clsUser user, const string& Seperator = "#//#")
    {
        clsDate Date1;
        string line = "";

        line += Date1.DateToString() + "-";
        line += clsDate::showCurrentTime() + Seperator;
        line += user.UserName + Seperator;
        line += clsUtil::EncryptText(user.Password)+ Seperator;
        line += to_string(user.Permissions);
        return line;
    }

    static void AppendLineToFile(const string& dataLine)
    {

        fstream MyFile(LoginFile, ios::out|ios::app);

        if (!MyFile.is_open())
        {
            cerr << "Error: Could not open log file!" << endl;
            return;
        }

        MyFile << dataLine << endl;

        if (!MyFile)
            cerr << "Error: Failed to write to file!" << endl;

        MyFile.close();
    }


    static clsRegisterLoginsInaFile _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsRegisterLoginsInaFile(vUserData[0], vUserData[1], vUserData[2], stoi(vUserData[3]));

    }
    static  vector <clsRegisterLoginsInaFile> _LoadUsersDataFromFile()
    {

        vector <clsRegisterLoginsInaFile> vUsers;

        fstream MyFile;
        MyFile.open(LoginFile, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsRegisterLoginsInaFile User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }
    clsRegisterLoginsInaFile(string Date, string name, string Password, int Permissions)
    {

        _DateTime = Date;
        _name = name;
        _Password = Password;
        _Permissions = Permissions;

    }
public:

   

    string GetUserName()
    {
        return _name;
    }

    void SetUserName(string UserName)
    {
        _name = UserName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string name;
    string GetDate()
    {
        return _DateTime;
       
    }

    void SetDate(string Date)
    {
        _DateTime = Date;
    }

    __declspec(property(get = GetDate, put = SetDate)) string Date;
    string GetPassword()
    {
        return _Password;

    }

    void SetPassword(string Password)
    {
        _Password = Date;
    }

    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    int GetPermissions()
    {
        return _Permissions;

    }

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;


    static void SaveLogin(const clsUser& user)
    {

        string line = FormatLoginEntry(user);
        AppendLineToFile(line);
    }

    static vector <clsRegisterLoginsInaFile> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }




};











