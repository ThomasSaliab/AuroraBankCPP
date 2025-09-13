#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include"C:\Users\TOP 10\source\repos\My Libraries Date\My Libraries Date\clsDate.h"
#include "clsPrepareUserClass.h" // نفترض انه بيعرف CurrentUser أو تقدر تمرر user كـ parameter
#include <filesystem>
#include"clsBankclinte.h"

using namespace std;

const string Transfer = "TransferLog.txt";

class clsCreateTransferLog
{
private:


   



    static string FormatLoginEntry(string Accuntnum1, string Accuntnum2,double muny,double muny2, double muny3,string User, const string& Seperator = "#//#")
    {
        clsDate Date1;
        string line = "";

        line += Date1.DateToString() + "-";
        line += clsDate::showCurrentTime() + Seperator;
        
        line += Accuntnum1 + Seperator;
        line += Accuntnum2 + Seperator;
        line += to_string(muny)+Seperator;
        line += to_string(muny2)+Seperator;
        line += to_string(muny3)+Seperator;
        line += User ;



        return line;
    }

    static void AppendLineToFile(const string& dataLine)
    {

        fstream MyFile(Transfer, ios::out | ios::app);

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
    string _DateTime;
    string _SAcct;
    string _dAcct;
    double _Amonth;
    double _sBalance;
    double _dBalance;
    string _User;





    static clsCreateTransferLog _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsCreateTransferLog(vUserData[0], vUserData[1], vUserData[2], stod(vUserData[3]), stod(vUserData[4]), stod(vUserData[5]),(vUserData[6]));

    }
    static  vector <clsCreateTransferLog> _LoadUsersDataFromFile()
    {

        vector <clsCreateTransferLog> vUsers;

        fstream MyFile;
        MyFile.open(Transfer, ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsCreateTransferLog User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }
    clsCreateTransferLog(string Date, string Accuntnum1, string Accuntnum2, double muny, double muny2, double muny3, string User)
    {

        _DateTime = Date;
        _SAcct = Accuntnum1;
        _dAcct = Accuntnum2;
        _Amonth = muny;
        _sBalance = muny2;
        _dBalance = muny3;
        _User = User;

    }

    
public:



    string GetDate()
    {
        return _DateTime;

    }

    void SetDate(string Date)
    {
        _DateTime = Date;
    }

    __declspec(property(get = GetDate, put = SetDate)) string Date;

    string GetSAcct()
    {
        return  _SAcct;
    }

    void SetSAcct(string SAcct)
    {
        _SAcct = SAcct;
    }

    __declspec(property(get = GetSAcct, put = SetSAcct)) string SAcct;
  
    string GetdAcct()
    {
        return _dAcct;

    }

    void SetdAcct(string dAcct)
    {
        _dAcct = dAcct;
    }

    __declspec(property(get = GetdAcct, put = SetdAcct)) string dAcct;

    double GetAmonth()
    {
        return _Amonth;

    }

    void SetAmonth(double Amonth)
    {
        _Amonth = Amonth;
    }

    __declspec(property(get = GetAmonth, put = SetAmonth)) double Amonth;
    
    double GetsBalance()
    {
        return _sBalance;

    }

    void SetsBalance(double sBalance)
    {
        _sBalance = sBalance;
    }

    __declspec(property(get = GetsBalance, put = SetsBalance)) double sBalance;


    double GetdBalance()
    {
        return _dBalance;

    }

    void SetdBalance(double dBalance)
    {
        _dBalance = dBalance;
    }

    __declspec(property(get = GetdBalance, put = SetdBalance)) double dBalance;

    string GetUser()
    {
        return _User;

    }

    void SetUser(string User)
    {
        _User = User;
    }

    __declspec(property(get = GetUser, put = SetUser)) string User;


    static vector <clsCreateTransferLog> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }




    static void SaveLogin(string Accuntnum1, string Accuntnum2,
        double muny, double muny2, double muny3, string User)
    {

        string line = FormatLoginEntry(Accuntnum1, Accuntnum2, muny, muny2, muny3,User);
        AppendLineToFile(line);
    }

 



};




