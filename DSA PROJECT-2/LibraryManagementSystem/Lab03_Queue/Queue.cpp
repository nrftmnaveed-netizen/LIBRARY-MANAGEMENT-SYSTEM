// ---------------------------------------------------------
// CLASS MEMBER FUNCTION FILE
// Definitions of all Queue member functions
// ---------------------------------------------------------
#include <iostream>
#include "Queue.h"
using namespace std;

// Constructor: empty queue
Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
    count = 0;
}

// Copy constructor: independent copy of all requests
Queue::Queue(const Queue& other)
{
    front = nullptr;
    rear = nullptr;
    count = 0;
    CopyFrom(other);
}

// Assignment operator: replace contents with a copy of 'other'
Queue& Queue::operator=(const Queue& other)
{
    if (this == &other)   // guard against self-assignment
        return *this;
    Clear();
    CopyFrom(other);
    return *this;
}

// Destructor: release all nodes
Queue::~Queue()
{
    Clear();
}

// Delete every request in the queue
void Queue::Clear()
{
    while (IsNotEmpty())
        delete DeQueue();
}

// Copy requests one by one from front to rear (order is preserved)
void Queue::CopyFrom(const Queue& other)
{
    for (BookRequestNode* current = other.front; current != nullptr;
         current = current->next)
    {
        EnQueue(new BookRequestNode(current->studentID, current->studentName,
                                    current->bookID, current->bookTitle));
    }
}

// EnQueue: new request joins at the rear
void Queue::EnQueue(BookRequestNode* request)
{
    if (request == nullptr)
        return;
    request->next = nullptr;   // the last node never points forward

    if (rear == nullptr)
    {
        // queue was empty: the request is both front and rear
        front = rear = request;
    }
    else
    {
        rear->next = request;  // old rear points to the new request
        rear = request;        // new request becomes the rear
    }
    count++;
}

// DeQueue: remove and return the request at the front
BookRequestNode* Queue::DeQueue()
{
    if (front == nullptr)
        return nullptr;

    BookRequestNode* request = front;
    front = front->next;       // second request becomes the front
    if (front == nullptr)
        rear = nullptr;        // queue became empty
    request->next = nullptr;
    count--;
    return request;            // caller deletes it
}

bool Queue::IsEmpty() const { return front == nullptr; }
bool Queue::IsNotEmpty() const { return front != nullptr; }
int Queue::GetCount() const { return count; }

// Display all requests from FRONT to REAR
void Queue::PrintQueue() const
{
    if (IsEmpty())
    {
        cout << "\nNo book requests in the queue.\n";
        return;
    }
    cout << "\nFRONT\n";
    for (BookRequestNode* current = front; current != nullptr;
         current = current->next)
    {
        cout << current->studentID << " - " << current->studentName
             << " -> " << current->bookTitle
             << " (Book ID " << current->bookID << ")" << endl;
    }
    cout << "REAR\nTotal requests: " << count << endl;
}
