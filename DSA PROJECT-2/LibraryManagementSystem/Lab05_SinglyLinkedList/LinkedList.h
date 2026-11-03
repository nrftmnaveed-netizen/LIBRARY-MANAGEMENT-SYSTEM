#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Book.h"

// ---------------------------------------------------------
// CLASS FILE (declaration only)
// Singly linked list that manages the library book collection.
// Member function bodies are in LinkedList.cpp
// ---------------------------------------------------------
class LinkedList
{
private:
    BookNode* head;   // first book in the list
    int count;           // number of books currently in the list

    BookNode* GetNodeAt(int index);            // find node at an index
    void SwapData(BookNode* a, BookNode* b); // swap data of two nodes

public:
    LinkedList();
    ~LinkedList();

    // Copying is disabled so two lists can never share the same nodes
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void Insert(BookNode* book);              // insert at head
    BookNode* Remove();                          // remove from head
    void InsertAt(BookNode* book, int index); // insert at any index
    BookNode* RemoveAt(int index);               // remove from any index
    bool Swap(int index1, int index2);              // swap two books
    void Sort();                                    // sort by book ID
    void Reverse();                                 // reverse the list
    void Print() const;                             // display all books

    bool IsEmpty() const;
    bool IsNotEmpty() const;
    int GetCount() const;
};

#endif
