#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Book.h"

// ---------------------------------------------------------
// CLASS FILE (declaration only)
// Doubly linked list for one student's borrowing session.
//   head    -> oldest title
//   tail    -> newest title
//   current -> title the author is reviewing right now
// Member function bodies are in DoublyLinkedList.cpp
// ---------------------------------------------------------
class DoublyLinkedList
{
private:
    BookNode* head;
    BookNode* tail;
    BookNode* current;
    int count;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // Copying disabled: two lists must never share nodes
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    void InsertRight(BookNode* node);          // add at the end
    void InsertAfterCurrent(BookNode* node);   // add after current
    BookNode* RemoveCurrent();                 // remove current entry
    bool Next();                                    // move current forward
    bool Previous();                                // move current backward
    void PrintCurrent() const;                      // show current entry
    void PrintForward() const;                      // oldest -> newest
    void PrintBackward() const;                     // newest -> oldest

    bool IsEmpty() const;
    bool IsNotEmpty() const;
    int GetCount() const;
};

#endif
