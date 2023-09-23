#include <bits/stdc++.h>
using namespace std;
#include "Menu.h"
#include "flight.h"
#include "queue.h"
#ifndef PERSON_H
#define PERSON_H

#pragma once


class Person // class for managing the functions of a passenger
{
private:
    int passportNo, tel;
    list<int> flights;
    string name, surname, nationallity, address;

public:
    /* --BOOK FLIGHT-- */
    void book();                 // book flight for each customer (Menu Option Νο 6)
    void bookFromQueue(int num); // book flight for the oldest customer in
                                 // (call ONLY when a reservation is cancelled)
    void cancel();               // cancel a reservation (Menu Option Νο 7)

    /* --SHOW PASSENGER'S INFO-- */
    static bool displayPersonInfo(int passport);

    /* --CHECHKER FOR UNIQUE PASSPORT-- */
    static bool uniquePass(int passport);

    /* --GETTERS-- */
    int getPassport() { return this->passportNo; }
    string getName() { return this->name; }
    string getSurname() { return this->surname; }
};

#endif