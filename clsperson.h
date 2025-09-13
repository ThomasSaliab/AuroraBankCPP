#pragma once


#include <iostream>
#include <string>

class clsPerson
{
private:
    string _lastName;
    string _firstName;
    string _email;
    string _phone;

public:
    clsPerson(string firstName, string lastName, string phone, string email)
    {
        _firstName = firstName;
        _lastName = lastName;
        _email = email;
        _phone = phone;
    }

    void setFirstName(string firstName)
    {
        _firstName = firstName;
    }
    string getFirstName()
    {
        return (_firstName);
    }

    __declspec(property(get = getFirstName, put = setFirstName))string firstName;

    void setLastName(string lastName)
    {
        _lastName = lastName;
    }
    string getLastName()
    {
        return (_lastName);
    }

    __declspec(property(get = getLastName, put = setLastName))string lastName;

    void setEmail(string email)
    {
        _email = email;
    }
    string getEmail()
    {
        return (_email);
    }

    __declspec(property(get = getEmail, put = setEmail))string email;

    string fullName()
    {
        return _firstName + " " + _lastName;
    }

    void setPhone(string phone)
    {
        _phone = phone;
    }
    string getPhone()
    {
        return (_phone);
    }

    __declspec(property(get = getPhone, put = setPhone))string phone;
};