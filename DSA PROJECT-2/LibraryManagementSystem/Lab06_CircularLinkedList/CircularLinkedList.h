#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include "Book.h"

// ---------------------------------------------------------
// CLASS FILE (declaration only)
// Circular linked list for the featured book display.
//   head       -> points to the LAST node (the "pivot")
//   head->next -> is the FIRST node
//   displayed     -> book currently on display (moves around the circle)
// Member function bodies are in CircularLinkedList.cpp
// ---------------------------------------------------------
class CircularLinkedList
{
private:
    BookNode* head;     // last node (pivot)
    BookNode* displayed;   // book currently on display
    int count;            // number of books

    BookNode* GetNodeAt(int index);               // node at index (0 = first)
    void SwapData(BookNode* a, BookNode* b);    // swap data of two nodes
    int NormalizeIndex(int index) const;            // wrap index into 0..count-1

public:
    CircularLinkedList();
    ~CircularLinkedList();

    // Copying disabled: two lists must never share nodes
    CircularLinkedList(const CircularLinkedList&) = delete;
    CircularLinkedList& operator=(const CircularLinkedList&) = delete;

    void Insert(BookNode* book);               // insert next to pivot (front)
    BookNode* Remove();                          // remove node next to pivot
    void InsertAt(BookNode* book, int index);  // insert at index
    BookNode* RemoveAt(int index);               // remove at index
    void Swap(int index1, int index2);             // swap two books
    void Sort();                                   // sort by book ID
    void Reverse();                                // reverse the circle
    void Print() const;                            // display all books once

    BookNode* MoveToNext();                      // shift display to next book
    BookNode* GetDisplayed() const;                 // book now on display
    void PrintRotation(int turns);                 // show display for N turns (wraps)
    void VerifyCircular() const;                   // prove last -> first link

    bool IsEmpty() const;
    bool IsNotEmpty() const;
    int GetCount() const;
};

#endif
