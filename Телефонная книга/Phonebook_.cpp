
#include "Phonebook_.h"

int main()
{
    int size{ -1 },
        choice,
        counter(0);
      
    char AnyData[40] = "\0";
    char TheName[40];
    Phonebook AnyPerson;
    
    FILE* ContactsBook;
    
    do {
        cout << " 1 - Add new Contact person " << endl;
        cout << " 2 - Display all Contact persons " << endl;
        cout << " 3 - Find the Contact " << endl;
        cout << " 4 - Delete the Contact person " << endl;
        cout << " 0 - Finish " << endl;
        cout << " ";
        cin >> choice;
        cin.ignore();

        
        switch (choice)
        {
        case 1:
            if (fopen_s(&ContactsBook, "Contacts.txt", "a") != NULL)
            {
                cout << "File could not be created!";
            }
            else
            {
                AnyPerson.setFullName(AnyData, AnyPerson.Typer(AnyData));
                AnyPerson.setHomePhone(AnyData, AnyPerson.Typer(AnyData));
                AnyPerson.setAdditionalPhone(AnyData, AnyPerson.Typer(AnyData));
                AnyPerson.setMobilePhone(AnyData, AnyPerson.Typer(AnyData));
                AnyPerson.setPersonalData(AnyData, AnyPerson.Typer(AnyData));
                AnyPerson.ToFile(ContactsBook, AnyPerson); 

                fclose(ContactsBook);
            }
            break;

        case 2:
            if (fopen_s(&ContactsBook, "Contacts.txt", "r") != NULL)
            {
                cout << "File could not be created!";
            }
            else
            {
                AnyPerson.Display_all(ContactsBook, AnyData);
                fclose(ContactsBook);
            }
            break;

        case 3:
            if (fopen_s(&ContactsBook, "Contacts.txt", "r") != NULL)
            {
                cout << "File could not be created!";
            }
            else
            {
                cout << " What name? ";
                size = AnyPerson.Typer(TheName);
                AnyPerson.Display_TheName(ContactsBook, AnyData, TheName);
                fclose(ContactsBook);
            }

            break;

        case 4:
                

            break;
        case 0:

        default:
            break;
        }
    } while (choice !=0 );
    
}

