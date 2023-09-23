#include <bits/stdc++.h>
using namespace std;
#include "queue.h"
#include "Menu.h"
#include "person.h"
#include "flight.h"


Queue::Queue(int queueId)
{

    this->queueNo = queueId;
    this->rear = NULL;
    this->front = NULL;
}

void Queue::enqueue(Person p)
{

    Node *temp = new Node;

    temp->person = p;
    temp->next = NULL;

    if (this->front == NULL)
    {
        this->front = temp;
    }
    else
    {
        this->rear->next = temp;
    }
    this->rear = temp;
}

void Queue::dequeue()
{

    Node *temp = new Node;

    temp = this->front;

    this->front = this->front->next;

    delete temp;
}

void Queue::display(int num)
{

    for (std::list<Queue>::iterator i = qlist.begin(); i != qlist.end(); ++i)
    {
        if (num == i->queueNo)
        {
            Node *p = new Node;
            p = i->front;

            if (i->front == NULL)
            {
                cout << "\nEmpty queue.\n";
            }
            else
            {
                cout << "\nPassengers waiting on queue:" << endl;
                cout << left << setw(15) << "Passport" << left << setw(15) << "Name" << left << setw(15) << "Surame" << endl;
                while (p != NULL)
                {
                    cout << left << setw(15) << p->person.getPassport() << left << setw(15) << p->person.getName() << left << setw(15) << p->person.getSurname() << endl;
                    p = p->next;
                }
            }
        }
    }
}

Person Queue::oldest()
{

    return this->front->person;
}

bool Queue::isEmpty()
{
    if (this->front == NULL && this->rear == NULL)
    {
        return true;
    }

    return false;
}