#include <bits/stdc++.h>
using namespace std;
#include "Menu.h"
#include "person.h"
#include "flight.h"

#ifndef QUEUE_H
#define QUEUE_H

#pragma once

class Queue // class that stores passengers on each flight's queue
{

private:
    int queueNo;
    Node *rear;
    Node *front;

public:
    /* --CREATE NEW QUEUE-- */
    Queue(int queueId); // queueID is the same as the flight number for each flight

    /* --ADD/REMOVE ELEMENTS-- */
    void enqueue(Person p); // add a new passenger
    void dequeue();         // remove the passenger add last

    /* --ΠΡΟΒΟΛΗ ΣΤΟΙΧΕΙΩΝ ΟΥΡΑΣ-- */
    static void display(int num); // εμφανίζει τους πελάτες, που βρίσκονται κατοχυρωμένοι
                                  // στην ουρά αναμονής της εκάστοτε πτήσης

    /* --ΕΠΙΣΤΡΟΦΗ ΑΡΧΑΙΟΤΕΡΟΥ ΧΡΗΣΤΗ-- */
    Person oldest(); // επιστρέφει το αντικέιμενο του αρχαιότερου πελάτη, μέσω της κλάσης Person

    /* --CHECK FOR EMPTY QUEUE-- */
    bool isEmpty(); // returns true if queue is empty

    /* --GETTERS-- */
    int getNo() { return this->queueNo; }
    Node *getFront() { return this->front; }
    Node *getRear() { return this->rear; }

    /* --SETTERS-- */
    void setFront(Node *f)
    {
        if (f == 0)
        {
            this->front = NULL;
        }
        else
        {
            this->front = f;
        }
    }
    void setRear(Node *r)
    {
        this->rear = r;
    }
};

#endif