#include <bits/stdc++.h>
using namespace std;
#include "Menu.h"

void Menu::welcomeScreen()
{

    int selection; // user's menu choice
    string temp;   // temp to store user's input
    bool firstRun = true;

    do
    {
        if (firstRun)
        {

            clearScreen();

            // Customize the UI by changing text and border characters
            cout << "\n\n\n\n";
            cout << "\033[32m";
            printStyledText("WELCOME TO", '*');
            printStyledText("AIRLINE RESERVATION SYSTEM MANAGEMENT", '#');
            printStyledText("PROJECT", '+');

            cout << "\t\t\t\t\t--------------------------------------------------------------------------------\n";
            cout << "\t\t\t\t\t\t\t\t\t  Developed By:-                             \t\n";
            cout << "\t\t\t\t\t\t\t\t\t                                            \t\n";
            cout << "\t\t\t\t\t\t\t\t\t  Jagadeesh B                            \t\n";
            cout << "\t\t\t\t\t--------------------------------------------------------------------------------\n\n";
            firstRun = false;
            system("pause");
        }

        std::cout << "+===========================================+" << std::endl;
        std::cout << "| Please pick an option from the menu below |. \n";
        std::cout << "+===========================================+" << std::endl;
        std::cout << "+----+---------------------------+" << std::endl;
        std::cout << "| ID | Option                    |" << std::endl;
        std::cout << "+----+---------------------------+" << std::endl;
        std::cout << "| 1  | Add new flights           |" << std::endl;
        std::cout << "| 2  | Delete flights            |" << std::endl;
        std::cout << "| 3  | Display flight schedule   |" << std::endl;
        std::cout << "| 4  | Display flight details    |" << std::endl;
        std::cout << "| 5  | Display passenger info    |" << std::endl;
        std::cout << "| 6  | Book reservation          |" << std::endl;
        std::cout << "| 7  | Cancel reservation        |" << std::endl;
        std::cout << "| 8  | Exit                      |" << std::endl;
        std::cout << "+----+---------------------------+" << std::endl;

        cout << "Enter the number of a menu option: ";
        cin >> temp;

        // check validity of input
        while (!checkNumber(temp))
        {
            cout << "Please enter a number!" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> temp;
        }
        cout << endl;

        selection = atoi(temp.c_str());
        select(selection);

    } while (true);
}

void Menu::select(int selection)
{

    Flight f;    // FLight's object
    Person p;    // class Person's object
    string temp; // temp to store input

    switch (selection)
    {
    case 1:
        f.addFlight();
        break;
    case 2:
        if (!flist.empty())
        {
            cout << "Enter the Flight Number you want to delete: ";
            cin >> temp;
            cout << endl;
            while (!checkNumber(temp))
            {
                cout << "Flight Number must be a number!" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> temp;
                cout << endl;
            }

            Flight::deleteFlight(atoi(temp.c_str()));
        }
        else
        {
            cout << "There are no flights to delete" << endl;
        }

        break;
    case 3:
        if (!flist.empty())
        {
            Flight::displaySchedule();
        }
        else
        {
            cout << "There are no scheduled flights!" << endl;
        }
        break;
    case 4:
        if (!flist.empty())
        {
            cout << "Please insert flight's number: ";
            cin >> temp;
            cout << endl;
            while (!checkNumber(temp))
            {
                cout << "Flight number must be a number!" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> temp;
                cout << endl;
            }
            Flight::displayFlightInfo(atoi(temp.c_str()));
        }
        else
        {
            cout << "There are no scheduled flights!" << endl;
        }
        break;
    case 5:
        if (!plist.empty())
        {
            cout << "Please insert passport number: ";
            cin >> temp;
            while (!Person::displayPersonInfo(atoi(temp.c_str())))
            {
                cout << "Wrong passport number!" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> temp;
                cout << endl;
            }
        }
        else
        {
            cout << "There are no registered clients at the moment!" << endl;
        }
        break;
    case 6:
        p.book();
        break;
    case 7:
        p.cancel();
        break;
    case 8:
        Menu::exit_prog();
        break;
    default:
        cout << "Invalid selection \n";
    }
}

void Menu::exit_prog()
{

    cout << "Thank you for using our system! \n";
    exit(1); // exit
}

void Menu::clearScreen()
{
    cout << "\033[H\033[2J"; // ANSI escape code to clear screen (Unix-like)
}

// Function to print a stylish centered text line with custom borders
void Menu::printStyledText(const string &text, char borderChar)
{
    int width = 80; // Assuming console width is 80 columns
    int textWidth = text.length();
    int leftMargin = (width - textWidth - 4) / 2; // 2 characters for left border, 2 for right border

    cout << "\t\t\t\t\t";
    cout << string(width, borderChar) << endl;

    cout << "\t\t\t\t\t" << borderChar << borderChar;
    cout << setw(leftMargin) << "" << text << setw(leftMargin) << "";
    cout << borderChar << borderChar << endl;

    cout << "\t\t\t\t\t";
    cout << string(width, borderChar) << endl
         << endl;
}