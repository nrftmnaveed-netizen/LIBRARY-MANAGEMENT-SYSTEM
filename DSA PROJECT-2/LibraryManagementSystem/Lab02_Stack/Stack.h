#ifndef STACK_H
#define STACK_H

#include "Book.h"

// ---------------------------------------------------------
// CLASS FILE (declaration only)
// Stack (LIFO) of returned books waiting to be processed.
// The most recently returned book is on TOP and is the
// first one the librarian processes.
// Member function bodies are in Stack.cpp
// ---------------------------------------------------------
class Stack
{
private:
    BookNode* top;   // most recently returned book
    int count;              // number of books in the stack

    void Clear();                    // delete all nodes
    void CopyFrom(const Stack& other); // deep copy (keeps same order)

public:
    Stack();                                   // constructor
    Stack(const Stack& other);                 // copy constructor
    Stack& operator=(const Stack& other);      // assignment operator
    ~Stack();                                  // destructor

    void Push(BookNode* book);   // place on top
    BookNode* Pop();                    // remove from top
    BookNode* GetTopValue() const;      // look at top without removing
    bool IsEmpty() const;
    bool IsNotEmpty() const;
    int GetCount() const;
    void PrintStack() const;                   // display top -> bottom
};

#endif
