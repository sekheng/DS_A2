#include "DetectMemoryLeak.h"
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

/******************************************************************************/
/*!
\brief
push a new node to the front of the linked list

\exception if size happens to be 0, head->next becomes the new node
*/
/******************************************************************************/
void LinkedList::push_front(int data)
{
    if (size() == 0)
    {
        head->next = new Node(data);
    }
    else
    {
        Node *curr = new Node(data);
        curr->next = head->next;
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
        Node *decoy = head->next;
        while (decoy->next != 0)
            decoy = decoy->next;
        Node *curr = new Node(data);
        decoy->next = curr;
    }
}

/******************************************************************************/
/*!
\brief
pop the front node of the linked list

\exception if size() happens to be 0, return 0

\exception if size() happens to be 1, head->next will be pointing to 0
*/
/******************************************************************************/
int LinkedList::pop_front()
{
    if (size() == 0)
    {
        return  0;
    }
    else if (size() == 1)
    {
        int data = head->next->data;
        Node *curr = head->next;
        head->next = 0;
        delete curr;
        return data;
    }
    else
    {
        int data = head->next->data;
        Node *curr = head->next;
        head->next = head->next->next;
        delete curr;
        return data;
    }
}

int LinkedList::pop_back()
{
    if (size() == 0)
    {
        return 0;
    }
    else
    {
        Node *decoy = head->next;
        while (decoy->next != 0)
        {
            decoy = decoy->next;
        }
        if (size() != 1)
        {
            Node *curr = head->next;
            while (curr->next != decoy)
            {
                curr = curr->next;
            }
            curr->next = 0;
        }
        else
        {
            head->next = 0;
        }
        int data = decoy->data;
        delete decoy;
        return data;
    }
}

void LinkedList::insert_at(int pos, int data)
{
    if (pos == 0 || size() == 0)
    {
        push_front(data);
    }
    else
    {
        Node * curr = head->next;
        for (int num = 1; num < pos; ++num)
        {
            if (curr->next == 0)
                break;
            curr = curr->next;
        }
        Node *new_node = new Node(data);
        if (curr->next != 0)
        {
            new_node->next = curr->next;
        }
        curr->next = new_node;
    }
}

int LinkedList::pop_at(int pos)
{
    if (size() == 0)
        return 0;
    else if (pos == 0)
    {
        int data = pop_front();
        return data;
    }
    else
    {
        Node *curr = head->next;
        for (int num = 0; num < pos; ++num)
        {
            curr = curr->next;
            if (curr == 0)
                break;
        }
        if (curr == 0)
            return 0;
        else if (curr->next == 0)
        {
            int data = pop_back();
            return data;
        }
        int data = curr->data;
        Node *decoy = head->next;
        while (decoy->next != curr)
            decoy = decoy->next;
        decoy->next = curr->next;
        delete curr;
        return data;
    }
}

size_t LinkedList::size()
{
    size_t count = 0;
    Node *curr = head;
    while (curr->next != 0)
    {
        curr = curr->next;
        ++count;
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
    back->next = front;
}

Queue::~Queue()
{
    Node *curr = front->next;
    while (curr != 0)
    {
        Node *decoy = curr;
        curr = curr->next;
        delete decoy;
    }
    delete front;
    delete back;
}

void Queue::enqueue(int data)
{
    Node *curr = new Node(data);
    Node *decoy = back->next;
    decoy->next = curr;
    back->next = curr;
}

int Queue::dequeue()
{
    if (back->next == front)
        return 0;
    else
    {
        int data = front->next->data;
        Node *curr = front->next;
        front->next = front->next->next;
        if (front->next == 0)
        {
            back->next = front;
        }
        delete curr;
        return data;
    }
}

size_t Queue::size()
{
    size_t data = 0;
    Node *curr = front;
    while (curr->next != 0)
    {
        curr = curr->next;
        ++data;
    }
    return data;
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
    Node *curr = top;
    while (curr != 0)
    {
        Node *decoy = curr;
        curr = curr->next;
        delete decoy;
    }
}

void Stack::push(int data)
{
    Node *curr = new Node(data);
    curr->next = top->next;
    top->next = curr;
}

int Stack::pop()
{
    if (size() == 0)
        return 0;
    else
    {
        int data = top->next->data;
        Node *curr = top->next;
        if (size() == 1)
        {
            top->next = 0;
        }
        else
        {
            top->next = top->next->next;
        }
        delete curr;
        return data;
    }
}

size_t Stack::size()
{
    size_t data = 0;
    Node *curr = top;
    while (curr->next != 0)
    {
        curr = curr->next;
        ++data;
    }
    return data;
}
