#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    Lee Sek Heng
 *  \date      2015 
 *  \note      150629Z
 */

//*******************************************************************//
// Linked list stuff
//*******************************************************************//
LinkedList::LinkedList()
{
    head = new Node();
}

LinkedList::~LinkedList()
{
    while (head != 0)
    {
        Node *curr = head;
        head = head->next;
        delete curr;
    }
}

void LinkedList::push_front(int data)
{
    if (size() == 0)
    {
        head->next = new Node(data);
    }
    else
    {
        Node *curr = new Node(data);
        curr->next = head->next->next;
        head->next = curr;
    }
}

void LinkedList::push_back(int data)
{
    if (size() == 0)
    {
        head->next = new Node(data);
    }
    else
    {
        Node *decoy = head;
        while (decoy->next != 0)
            decoy = decoy->next;
        Node *curr = new Node(data);
        decoy->next = curr;
    }
}

int LinkedList::pop_front()
{
    if (size() == 0)
    {
        return  0;
    }
    int data = head->data;
    Node *curr = head;
    head = head->next;
    delete curr;
    return data;
}

int LinkedList::pop_back()
{
    if (size() == 0)
    {
        return 0;
    }
    else if (size() == 1)
    {
        int data = head->data;
        head = 0;
        return data;
    }
    else
    {
        Node *decoy = head;
        while (decoy->next != 0)
        {
            decoy = decoy->next;
        }
        Node *curr = head;
        while (curr->next != decoy)
        {
            curr = curr->next;
        }
        curr->next = 0;
        int data = decoy->data;
        delete decoy;
        return data;
    }
}

void LinkedList::insert_at(int pos, int data)
{

}

int LinkedList::pop_at(int pos)
{
    return 0;
}

size_t LinkedList::size()
{
    size_t count = 0;
    if (head == 0)
    {
        return 0;
    }
    Node *curr = head;
    while (curr->next != 0)
    {
        ++count;
        curr = curr->next;
    }
    return count;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue()
{
    front = new Node();
    back = new Node();
}

Queue::~Queue()
{
    delete front;
    delete back;
}

void Queue::enqueue(int)
{

}

int Queue::dequeue()
{
    return 0;
}

size_t Queue::size()
{
    return 0;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack()
{
    top = new Node();
}

Stack::~Stack()
{
    delete top;
}

void Stack::push(int)
{

}

int Stack::pop()
{
    return 0;
}

size_t Stack::size()
{
    return 0;
}
