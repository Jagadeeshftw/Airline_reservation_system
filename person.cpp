#include <bits/stdc++.h>
using namespace std;
#include "person.h"
#include "Menu.h"
#include "flight.h"
#include "queue.h"


void Person::book()
{

    /* ----INITIALISE VARS----*/
    /* --FLIGHTS-- */
    string temp; // temp to store user's input, to be checked
    int num;     // stores flight's number, after successful check

    /* --VARS FOR NON DIRECT FLIGHTS-- */
    int counter = 1; // stores the amount(>=2) of the non-direct flights
    string choice;   // stores user's choice for adding or not more flights to their reservation
    Time tArriving;
    Time tLeaving;
    string Departure;
    string Destination;
    list<int> nums;                        // store flights' numbers
    list<int>::iterator i1 = nums.begin(); // iterator for accessing List nums

    /* --VAR FOR LOOPS-- */
    bool flag = true;

    // clean stream
    cin.clear();
    cin.ignore(256, '\n');

    if (!flist.empty())
    {
        cout << "Insert y (yes) for a new client or n (no) for an existing client. ";
        getline(cin, choice);

        // enter if client is new
        if (choice == "y" || choice == "Y")
        {

            cout << "Please give us your personal info. " << endl;

            /* --NAME-- */
            cout << "Name: ";
            flag = false;

        // check input
        LOOP8:
            do
            {
                getline(cin, this->name);
                if ((this->name.length() <= 10) && (checkString(this->name)))
                {
                    flag = true;
                }
                else
                {
                    cout << "Please insert a valid Name! ";
                    goto LOOP8;
                }
            } while (!flag);

            /* --SURNAME-- */
            cout << "Surname: ";
            flag = false;

        // check input
        LOOP9:
            do
            {
                getline(cin, this->surname);
                if ((this->surname.length() <= 10) && (checkString(this->surname)))
                {
                    flag = true;
                }
                else
                {
                    cout << "Please insert a valid Surname! ";
                    goto LOOP9;
                }
            } while (!flag);

            /* --PASPPORT No-- */
            cout << "Passport number: ";

        // check input
        LOOP10:
            do
            {

                getline(cin, temp);
                flag = true;

                if (!checkNumber(temp))
                {
                    cout << "Please insert a valid passport number" << endl;
                    flag = false;
                    goto LOOP10;
                }
                else if (!Person::uniquePass(atoi(temp.c_str())))
                {
                    cout << "Please check the validity of your passport number" << endl;
                    flag = false;
                    goto LOOP10;
                }
                else
                {
                    flag = true;
                    this->passportNo = atoi(temp.c_str());
                }
            } while (!flag);

            /* --NATIONALLITY-- */
            cout << "Nationallity: ";
            flag = false;

        // check input
        LOOP11:
            do
            {

                getline(cin, this->nationallity);

                if ((this->nationallity.length() <= 10) && (checkString(this->nationallity)))
                {
                    flag = true;
                }
                else
                {
                    cout << "Please insert a valid Nationallity! ";
                    goto LOOP11;
                }
            } while (!flag);

            /* --ADDRESS-- */
            cout << "Address: ";
            getline(cin, this->address);

            /* --TEL-- */
            cout << "Telephone: ";
            getline(cin, temp);

            // check input
            while (!checkNumber(temp))
            {
                cout << "Please insert a valid telephone number!" << endl;
                getline(cin, temp);
            }
            this->tel = atoi(temp.c_str());
        }
        else
        { // existing customer
            cout << "Pleas give us your passport No: ";
            getline(cin, temp);

            // check input
            while (!checkNumber(temp))
            {
                cout << "Please insert a valid passport number!" << endl;
                flag = false;
                getline(cin, temp);
            }

            // check if passport No is unique
            if (!(Person::uniquePass(atoi(temp.c_str()))))
            {
                for (std::list<Person>::iterator i = plist.begin(); i != plist.end(); ++i)
                {
                    if (atoi(temp.c_str()) == i->passportNo)
                    {
                        this->name = i->name;
                        this->surname = i->surname;
                        this->passportNo = i->passportNo;
                        this->nationallity = i->nationallity;
                        this->address = i->address;
                        this->tel = i->tel;

                        for (std::list<int>::iterator i2 = i->flights.begin(); i2 != i->flights.end(); ++i2)
                        {
                            this->flights.push_back(*i2);
                        }

                        // after copying the customers info,
                        // delete the old object pointing to them
                        i = plist.erase(i);
                        break;
                    }
                }
            }
            else
            {
                cout << "Wrong passport number!" << endl;
                return;
            }
        }

        // display flights
        Flight::displaySchedule();

        /* --FLIGTH No-- */
        cout << "\n\nEnter the number of the flight you 're intrested in: ";
        getline(cin, temp);
        flag = true;

        // check input
        while (!checkNumber(temp) && !Flight::flightExists(atoi(temp.c_str())))
        {
            cout << "Please insert a valid Flight No!" << endl;
            getline(cin, temp);
        }
        num = atoi(temp.c_str());

        /*
        ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                            BOOK CUSTOMER'S CHOSEN FLIGHT(S)
        ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        */

        // DIRECT FLIGHT
        if (Flight::checkForSeats(num))
        { // check for vacancy
            this->flights.push_back(num);
            Flight::resSeat(num, 1);
            cout << "Your flight with No: " << num << " was successfully booked." << endl;

            // NONO-DIRECT FLIGHT
        }
        else
        {
            choice = "y";

            cout << "There are no available direct flights for this destination." << endl;
            cout << "Please enter the special numbers for the alternative flights.";

            while (choice == "y" || choice == "Y")
            { // exit if user doesn't want to add more flights

            LOOP12:
                cout << "\nNumber #" << counter << " : ";
                getline(cin, temp);

                // check input
                while (!checkNumber(temp) && !Flight::flightExists(atoi(temp.c_str())))
                {
                    cout << "Please insert a valid Flight No!" << endl;
                    cin >> temp;
                }

                num = atoi(temp.c_str());

                if (counter > 1)
                { // enter if user has entered 2 or more flights

                    // store the arrival, departure time and the departure, arriving city
                    for (std::list<Flight>::iterator i2 = flist.begin(); i2 != flist.end(); ++i2)
                    {
                        if (*i1 == i2->getFlightNo())
                        {
                            tArriving = i2->getArrivingTime();
                            Destination = i2->getDestination();
                        }
                        else if (num == i2->getFlightNo())
                        {
                            tLeaving = i2->getLeavingTime();
                            Departure = i2->getDeparture();
                        }
                    }

                    // check validity of each flight
                    if (!(checkTime2(tLeaving, tArriving) && !Departure.compare(Destination)))
                    {
                        cout << "Please enter a flight to a valid Destination!" << endl;
                        goto LOOP12;
                    }
                }

                nums.push_back(num); // add the flight's number
                i1++;

                if (counter >= 2)
                {
                    cout << "Do you want to add more flight numbers?(y/n) ";
                    getline(cin, choice);
                }

                counter++;
            }

            // check for vacancies in the chosen flights
            // and add all of the flight's numbers to the specific node of the list flights
            for (std::list<int>::iterator i = nums.begin(); i != nums.end(); ++i)
            {
                flag = Flight::checkForSeats(*i) and flag;
                this->flights.push_back(*i);
            }

            // enter ONLY if there are vacant seats and reserve a seat to each chosen flight
            if (flag)
            {
                for (std::list<int>::iterator i = nums.begin(); i != nums.end(); ++i)
                {
                    Flight::resSeat(*i, 1);
                }
                cout << "Your flights were successfully booked." << endl;

                // if, at least, one flight is fully booked add the customer to the queues of each flight
            }
            else
            {
                cout << endl;
                cout << "Some of the flights you inserted were over booked." << endl;

                for (std::list<int>::iterator i = nums.begin(); i != nums.end(); ++i)
                {
                    for (std::list<Queue>::iterator i2 = qlist.begin(); i2 != qlist.end(); ++i2)
                    {
                        if (*i == i2->getNo())
                        {
                            i2->enqueue(*this);
                        }
                    }
                }
                cout << "We have added you in queues for each of these flights." << endl;
            }
        }
        plist.push_back(*this); // add object to plist
    }
    else
    {
        cout << "There are no available flights at the moment." << endl;
        return;
    }
}

void Person::bookFromQueue(int num)
{ // is called only from cancel()

    bool flag = true;
    Person queueFront; // object of the customer added last

    // find the oldest customer
    for (std::list<Queue>::iterator it = qlist.begin(); it != qlist.end(); ++it)
    {
        if (num == it->getNo())
        {
            if (!(it->isEmpty()))
            {
                queueFront = it->oldest();
                break;
            }
            else
            {
                return;
            }
        }
    }

    // check if all of the customer's chosen flights have vacant seats
    for (std::list<int>::iterator i = queueFront.flights.begin(); i != queueFront.flights.end(); ++i)
    {
        flag = Flight::checkForSeats(*i) and flag;
    }

    // enter ONLY if there are vacancies in ALL of the customer's chosen flights
    // and book them
    if (flag)
    {
        Node *p = new Node;

        // find the flights of the oldest customer
        for (std::list<int>::iterator i = queueFront.flights.begin(); i != queueFront.flights.end(); ++i)
        {

            // delete him from the queues
            for (std::list<Queue>::iterator i2 = qlist.begin(); i2 != qlist.end(); ++i2)
            {
                if (*i == i2->getNo())
                {
                    p = i2->getFront();
                    while (p != NULL)
                    {
                        if (queueFront.passportNo == p->person.passportNo)
                        {
                            i2->dequeue();
                            Flight::resSeat(*i, 1);
                        }
                        p = p->next;
                    }
                }
            }
        }
    }
}

void Person::cancel()
{

    string passport, num;
    int counter = 1;          // counter that stores user's wrong inputs
    bool flightFound = false; // is false if customer has already booked a seat in a flight
    bool isInQueue = false;   // is false if the customer, that will be deleted, doesn't belong in
                              //  the queue of each flight

    if (!plist.empty())
    {
        // clean stream
        cin.clear();
        cin.ignore(256, '\n');

        cout << "Please give us your passport number: ";
        getline(cin, passport);
        cout << endl;

        // check input
        while (!checkNumber(passport))
        {
            cout << "Please insert a valid passport number!" << endl;
            getline(cin, passport);
            cout << endl;
        }

        while (!Person::displayPersonInfo(atoi(passport.c_str())))
        {

            // έξοδος από το πρόγραμμα αν δοθεί λανθασμένος αριθμός διαβατηρίου 5 φορές
            if (counter == 5)
            {
                cout << "Wrong passporst number was given too many times.";
                return;
            }
            else
            {
                cout << "Please check your Passport Number." << endl;
                getline(cin, passport);
                cout << endl;

                // έλεγχος αν ο αριθμός διαβατηρίου αποτελείται μόνο από ψηφία
                while (!checkNumber(passport))
                {
                    cout << "Please insert a valid passport number!" << endl;
                    getline(cin, passport);
                    cout << endl;
                }
            }
            counter++;
        }

        cout << "\nWhich flight do you want to cancel (enter the flight number)? ";
        getline(cin, num);
        counter = 1;

        // check input
        while (!checkNumber(num))
        {
            cout << "Please insert a valid flight number!" << endl;
            getline(cin, num);
            cout << endl;
        }

        // iterate through the passenger's flights
        for (std::list<Person>::iterator i = plist.begin(); i != plist.end(); ++i)
        {
            if (atoi(passport.c_str()) == i->passportNo)
            {

                // check input and exit if counter = 5
                do
                {
                    for (std::list<int>::iterator i2 = (i->flights).begin(); i2 != (i->flights).end(); ++i2)
                    {
                        if (atoi(num.c_str()) == *i2)
                        {
                            flightFound = true;
                            i2 = flights.erase(i2); // delete flight from passenger's info
                            break;
                        }
                    }

                    if (counter == 5)
                    {
                        cout << "Wrong flight number was given too many times.";
                        return;
                    }
                    else if (!flightFound)
                    {
                        cout << "Please check your flight number!.";
                        getline(cin, num);
                        cout << endl;

                        // check input
                        while (!checkNumber(num))
                        {
                            cout << "Please insert a valid flight number!" << endl;
                            getline(cin, num);
                            cout << endl;
                        }
                    }
                    counter++;
                } while (!flightFound);
                break;
            }
        }

        // delete client from the queue of the flight, if they are a part of it
        for (std::list<Queue>::iterator i = qlist.begin(); i != qlist.end(); ++i)
        {
            if (atoi(num.c_str()) == i->getNo())
            {
                if (!i->isEmpty())
                {
                    Node *p = new Node;
                    Node *previousNode;
                    p = i->getFront();

                    while (p != NULL)
                    {
                        if (atoi(passport.c_str()) == p->person.passportNo)
                        {
                            isInQueue = true;

                            // enter if the client is on the first position
                            if (p == i->getFront())
                            {
                                i->setFront(p->next);
                                // enter if queue has only one element
                                if (i->getFront() == i->getRear())
                                {
                                    i->setRear(NULL);
                                }
                            }
                            else if (p == i->getRear())
                            { // enter if client is in the last poitsion of the queue
                                previousNode->next = NULL;
                            }
                            else
                            {
                                previousNode->next = p->next;
                            }
                            delete (p);
                            break;
                        }
                        previousNode = p;
                        p = p->next;
                    }
                }
            }
        }

        // enter if passenger is NOT part of the current queue
        if (!isInQueue)
        {
            Flight::resSeat(atoi(num.c_str()), -1);

            this->bookFromQueue(atoi(num.c_str()));
        }
        cout << "\nYour reservation was successfully removed! \n"
             << endl;
    }
    else
    {
        cout << "There are no registered clients at the moment!" << endl;
    }
}

bool Person::displayPersonInfo(int passport)
{

    for (std::list<Person>::iterator i = plist.begin(); i != plist.end(); ++i)
    {

        if (passport == i->passportNo)
        {

            cout << "\n\t\t\t\t PERSONAL INFO" << endl
                 << endl;
            cout << left << setw(15) << "NAME" << left << setw(15) << "SURNAME" << left << setw(15) << "PASSPORT_No" << left << setw(15) << "NATIONALLITY" << left << setw(15) << "ADDRESS" << left << setw(15) << "TELEPHONE" << endl;

            cout << left << setw(15) << i->name << left << setw(15) << i->surname << left << setw(15) << i->passportNo << left << setw(15) << i->nationallity << left << setw(15) << i->address << left << setw(15) << i->tel << endl
                 << endl;
            cout << "Your flight(s): ";

            for (std::list<int>::iterator i2 = (i->flights).begin(); i2 != (i->flights).end(); ++i2)
            {

                cout << *i2 << "  ";
            }
            cout << endl;
            return true;
        }
    }
    cout << "Passport number was not found. Check again!" << endl;
    return false;
}

bool Person::uniquePass(int passport)
{
    for (std::list<Person>::iterator i = plist.begin(); i != plist.end(); ++i)
    {
        if (passport == i->getPassport())
        {
            return false;
        }
    }
    return true;
}