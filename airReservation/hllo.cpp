#include <iostream>
#include <iomanip>

using namespace std;

// Function to clear the console screen (platform-independent)
void clearScreen()
{
    cout << "\033[H\033[2J"; // ANSI escape code to clear screen (Unix-like)
}

// Function to print a stylish centered text line with custom borders
void printStyledText(const string &text, char borderChar)
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

int main()
{
    clearScreen();

    // Customize the UI by changing text and border characters
    cout << "\033[32m";
    printStyledText("WELCOME TO", '*');
    printStyledText("BUS RESERVATION SYSTEM MANAGEMENT", '#');
    printStyledText("PROJECT", '+');

    cout << "\t\t\t\t\t--------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t\t  Developed By:-                             \t\n";
    cout << "\t\t\t\t\t\t\t\t\t                                            \t\n";
    cout << "\t\t\t\t\t\t\t\t\t  Jagadeesh B                            \t\n";
    cout << "\t\t\t\t\t--------------------------------------------------------------------------------\n\n";

    // Your program logic goes here

    return 0;
}