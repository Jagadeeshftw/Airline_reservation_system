#include <bits/stdc++.h>
using namespace std;
#include "Menu.h"
#include "person.h"
#include "queue.h"
#ifndef FLIGHT_H
#define FLIGHT_H

#pragma once


class Flight // class for managing the availabe functions of a flight
{
private:
    int flightNo, cost, seats, booked_seats;
    string from, to, plane_type;
    Time t_leave, t_arrive;

public:
    /* --ADD/REMOVE FLIGHTS--*/
    void addFlight();                  // διαχειρίζεται την προσθήκη πτήσεων (επιλογή μενού Νο 1)
    static void deleteFlight(int num); // διαχειρίζεται την αφαίρεση πτήσεων (επιλογή μενού Νο 2)

    /* --DISPLAY FLIGHTS--*/
    static void displayFlightInfo(int num); // προβάλλει τις πληροφορίες μιας πτήσης (επιλογή μενού Νο 3)
    static void displaySchedule();          // προβάλλει τις πτήσεις που υπάρχουν καταχωρημένες στο σύστημα (επιλογή μενού Νο 4)

    /* --BOOK SEATS--*/
    static void resSeat(int num, int val); // αυξομειώνει τις κατοχυρωμένες θέσεις μιας πτήσεις

    /* --FLIGHT CHECKERS--*/
    static bool flightExists(int num);  // check flight is booked
    static bool checkForSeats(int num); // checks for already registerd flight in the system

    /* --GETTERS--*/
    int getFlightNo() { return this->flightNo; }
    Time getLeavingTime() { return this->t_leave; }
    Time getArrivingTime() { return this->t_arrive; }
    string getDeparture() { return this->from; }
    string getDestination() { return this->to; }
};

#endif