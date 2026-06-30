#include "PhoneDirectory.h"
#include <fstream>
#include <vector>
using namespace std;

void PhoneDirectory::loadData(string fileName)
{
    ifstream file(fileName);

    if(!file)
    {
        cout << "Sample data file not found!\n";
        return;
    }

    string name, phone;

    while(getline(file, name))
    {
        getline(file, phone);
        directory.insert(name, phone);
    }

    file.close();
}
void PhoneDirectory::searchByPhone()
{
    string phone;
    cout << "Enter Phone Number: ";
    cin >> phone;

    ifstream file("sample_data.txt");

    string name, number;
    bool found = false;

    while (getline(file, name))
    {
        getline(file, number);

        if (number == phone)
        {
            cout << "\nContact Found\n";
            cout << "Name : " << name << endl;
            cout << "Phone: " << number << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Contact Not Found!\n";
}
void PhoneDirectory::menu()
{
    int choice;

    while(true)
    {
        cout << "\n=====================================\n";
cout << "      PHONE DIRECTORY USING TRIE\n";
cout << "=====================================\n";
     cout << "\n1. Add Contact";
cout << "\n2. Search by Name";
cout << "\n3. Search by Phone";
cout << "\n4. Display All Contacts";
cout << "\n5. Delete Contact";
cout << "\n6. Exit";
cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                string name, phone;

                cin.ignore();

                cout << "Enter Name : ";
                getline(cin, name);

                cout << "Enter Phone Number : ";
                cin >> phone;
                if(directory.searchExact(name))
{
    cout << "Contact already exists!\n";
    break;
}

                directory.insert(name, phone);
                cout << "Contact Added Successfully!\n";

// Save contact permanently
ofstream outFile("sample_data.txt", ios::app);

outFile << name << endl;
outFile << phone << endl;

outFile.close();


                break;
            }

            case 2:
            {
                string prefix;

                cin.ignore();

                cout << "Enter Name : ";
                getline(cin, prefix);

                directory.search(prefix);
                break;
            }

           case 3:
{
    searchByPhone();
    break;
}
case 4:
{
    directory.displayAll();
    break;
}

          case 5:
{
    string name;

    cin.ignore();

    cout << "Enter Contact Name : ";
    getline(cin, name);

    if(directory.remove(name))
    {
        cout << "Contact Deleted Successfully!\n";

        ifstream in("sample_data.txt");
        vector<pair<string,string>> contacts;

        string n, p;

        while(getline(in, n))
        {
            getline(in, p);

            if(n != name)
                contacts.push_back({n,p});
        }

        in.close();

        ofstream out("sample_data.txt");

        for(auto contact : contacts)
        {
            out << contact.first << endl;
            out << contact.second << endl;
        }

        out.close();
    }
    else
    {
        cout << "Contact Not Found!\n";
    }

    break;
}

case 6:
{
    cout << "\nThank You!\n";
    return;
}

            default:
            {
                cout << "Invalid Choice!\n";
            }
        }
    }
}