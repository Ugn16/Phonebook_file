#include "Phonebook_.h"

Phonebook::Phonebook()
{
    cout << " Phonebook Constructor " << this << endl;
}

Phonebook::Phonebook(const Phonebook& other)
{
    cout << " Phonebook copy Constructor " << this << endl;
    this->size = size;
    this->FullName = new char[other.size];
    for (int i = 0; i < other.size; i++)
    {
        this->FullName[i] = other.FullName[i];
    }

    this->HomePhone = new char[other.size];
    for (int i = 0; i < other.size; i++)
    {
        this->HomePhone[i] = other.HomePhone[i];
    }

    this->AdditionalPhone = new char[other.size];
    for (int i = 0; i < other.size; i++)
    {
        this->AdditionalPhone[i] = other.AdditionalPhone[i];
    }

    this->MobilePhone = new char[other.size];
    for (int i = 0; i < other.size; i++)
    {
        this->MobilePhone[i] = other.MobilePhone[i];
    }

    this->SomePersonalData = new char[other.size];
    for (int i = 0; i < other.size; i++)
    {
        this->SomePersonalData[i] = other.SomePersonalData[i];
    }
}

void Phonebook::setFullName(char AnyChar[], int size)
{
    this->size = size + 1;

    FullName = new char[this->size];
    for (int i = 0; i < this->size; i++)
    {
        FullName[i] = AnyChar[i];
    }
    FullName[this->size - 1] = '\0';
}

void Phonebook::setHomePhone(char AnyChar[], int size)
{
    this->size = size + 1;
    HomePhone = new char[this->size];
    for (int i = 0; i < this->size; i++)
    {
        HomePhone[i] = AnyChar[i];
    }
    HomePhone[this->size - 1] = '\0';
}

void Phonebook::setAdditionalPhone(char AnyChar[], int size)
{
    this->size = size + 1;
    AdditionalPhone = new char[this->size];

    for (int i = 0; i < this->size; i++)
    {
        AdditionalPhone[i] = AnyChar[i];
    }
    AdditionalPhone[this->size - 1] = '\0';
}

void Phonebook::setMobilePhone(char AnyChar[], int size)
{
    this->size = size + 1;
    MobilePhone = new char[this->size];
    for (int i = 0; i < this->size; i++)
    {
        MobilePhone[i] = AnyChar[i];
    }
    MobilePhone[this->size - 1] = '\0';
}


void Phonebook::setPersonalData(char AnyChar[], int size)
{
    this->size = size + 1;
    SomePersonalData = new char[this->size];
    for (int i = 0; i < this->size; i++)
    {
        SomePersonalData[i] = AnyChar[i];
    }
    SomePersonalData[this->size - 1] = '\0';
}

void Phonebook::ToFile(FILE* anyData, Phonebook anyContact)
{
    fputs(anyContact.FullName, anyData);
    fputs("\n", anyData);

    fputs(anyContact.HomePhone, anyData);
    fputs("\n", anyData);

    fputs(anyContact.AdditionalPhone, anyData);
    fputs("\n", anyData);

    fputs(anyContact.MobilePhone, anyData);
    fputs("\n", anyData);

    fputs(anyContact.SomePersonalData, anyData);
    fputs("\n\n", anyData);
}



int Phonebook::Typer(char AnyData[])
{
    int size(-1);
    do
    {
        size += 1;
        AnyData[size] = getchar();
    } while (AnyData[size] != '\n');

    AnyData[size] = '\0';
    return size;
}

void Phonebook::Display_all(FILE* any_file, char any_char[])
{
    while (!feof(any_file))
    {
        fgets(any_char, 40, any_file);
        cout << " " << any_char << endl;
    }
}

 void Phonebook::Display_TheName(FILE* any_file, char any_char[], char anyName[])
{
    int count(0);
    while (!feof(any_file))
    {
        fgets(any_char, 20, any_file);
        if (count == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                if (anyName[i] == any_char[i])
                {
                    count++;
                    if (count == 3) count = 5;
                }

                else
                {
                    count = 0;
                    break;
                }
            }
        }

        if (count <= 5 && count > 0)
        {
            cout << " " << string(any_char) << endl;
            count--;
        }
    }
}

Phonebook:: ~Phonebook()
{
    cout << " Phonebook Destructor " << this << endl;
    delete[] FullName;
    delete[] HomePhone;
    delete[] AdditionalPhone;
    delete[] MobilePhone;
    delete[] SomePersonalData;
}

int HowManyStrings(FILE* any_file)
{
    int string_counter(0);
    char any_char[40];
    while (!feof(any_file))
    {
        fgets(any_char, 40, any_file);
        string_counter++;
    }
    return string_counter;
}
