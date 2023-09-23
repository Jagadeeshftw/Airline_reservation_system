#include <iostream>
using namespace std;
#ifndef MENU_H
#define MENU_H

#pragma once

class Menu // class for managing the app's menu
{
public:
    static void welcomeScreen();                                      // displays the menu
    static void select(int selection);                                // receives user's input and performs the corresponding function
    static void exit_prog();                                          // exits the app
    static void printStyledText(const string &text, char borderChar); // print styled text
    static void clearScreen();                                        // clears screen
};

#endif