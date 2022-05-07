#pragma once
#ifndef Phonebook_.h
//#define Phonebook_.h
//#include Phonebook_.h

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Phonebook
{
    int size;
    char* FullName = nullptr;
    char* HomePhone = nullptr;
    char* AdditionalPhone = nullptr;
    char* MobilePhone = nullptr;
    char* SomePersonalData = nullptr;

public:

    Phonebook();
    Phonebook(const Phonebook& other);
    void setFullName(char AnyChar[], int size);
    void setHomePhone(char AnyChar[], int size);
    void setAdditionalPhone(char AnyChar[], int size);
    void setMobilePhone(char AnyChar[], int size);
    void setPersonalData(char AnyChar[], int size);
    void ToFile(FILE* anyData, Phonebook anyContact);
    int Typer(char AnyData[]);
    void Display_all(FILE* any_file, char any_char[]);
    void Display_TheName(FILE* any_file, char any_char[], char anyName[]);
    ~Phonebook();
};
int HowManyStrings(FILE* any_file);
#endif Phonebook_.h
