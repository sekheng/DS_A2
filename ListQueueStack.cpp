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
    Node *curr = new Node(data);
    curr->next = head->next;
    head = curr;
}

void LinkedList::push_back(int data)
{

}

int LinkedList::pop_front()
{
    return 0;
}

int LinkedList::pop_back()
{
    return 0;
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
    return 0;
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
