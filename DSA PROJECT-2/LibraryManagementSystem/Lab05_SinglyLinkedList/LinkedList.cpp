// ---------------------------------------------------------
// CLASS MEMBER FUNCTION FILE
// Definitions of all LinkedList member functions
// ---------------------------------------------------------
#include <iostream>
#include <utility>
#include "LinkedList.h"
using namespace std;

// Constructor: start with an empty list
LinkedList::LinkedList()
{
    head = nullptr;
    count = 0;
}

// Destructor: delete every remaining node to avoid memory leaks
LinkedList::~LinkedList()
{
    while (IsNotEmpty())
        delete Remove();
}

// Walk from head and return the node at the given index
BookNode* LinkedList::GetNodeAt(int index)
{
    BookNode* current = head;
    // move forward 'index' times (stop early if list ends)
    for (int i = 0; i < index && current != nullptr; i++)
        current = current->next;
    return current;
}

// Exchange the data (not the links) of two nodes
void LinkedList::SwapData(BookNode* a, BookNode* b)
{
    swap(a->bookID, b->bookID);
    swap(a->title, b->title);
    swap(a->author, b->author);
}

// Insert at head: new node points to old head, then becomes head
void LinkedList::Insert(BookNode* book)
{
    if (book == nullptr)
        return;
    book->next = head;
    head = book;
    count++;
}

// Remove from head: head moves to the second node
BookNode* LinkedList::Remove()
{
    if (IsEmpty())
        return nullptr;
    BookNode* removed = head;
    head = head->next;
    removed->next = nullptr;   // fully detach the removed node
    count--;
    return removed;            // caller deletes it
}

// Insert at an index (invalid index is corrected into range)
void LinkedList::InsertAt(BookNode* book, int index)
{
    if (book == nullptr)
        return;

    // correct the index: below 0 -> 0, above count -> count (append)
    if (index < 0)
        index = 0;
    if (index > count)
        index = count;

    // index 0 is the same as inserting at head
    if (index == 0)
    {
        Insert(book);
        return;
    }

    // otherwise find the node just before the insertion point
    BookNode* previous = GetNodeAt(index - 1);
    book->next = previous->next;   // new node -> following node
    previous->next = book;         // previous node -> new node
    count++;
}

// Remove at an index (invalid index is corrected into range)
BookNode* LinkedList::RemoveAt(int index)
{
    if (IsEmpty())
        return nullptr;

    if (index < 0)
        index = 0;
    if (index >= count)
        index = count - 1;

    // removing index 0 is the same as removing from head
    if (index == 0)
        return Remove();

    BookNode* previous = GetNodeAt(index - 1);
    BookNode* removed = previous->next;
    previous->next = removed->next;   // bypass the removed node
    removed->next = nullptr;
    count--;
    return removed;
}

// Swap two books; returns false if an index is invalid
bool LinkedList::Swap(int index1, int index2)
{
    if (index1 < 0 || index1 >= count || index2 < 0 || index2 >= count)
        return false;
    if (index1 != index2)
        SwapData(GetNodeAt(index1), GetNodeAt(index2));
    return true;
}

// Sort ascending by bookID (compare each node with all later nodes)
void LinkedList::Sort()
{
    for (BookNode* i = head; i != nullptr; i = i->next)
    {
        for (BookNode* j = i->next; j != nullptr; j = j->next)
        {
            // if out of order, exchange their data
            if (i->bookID > j->bookID)
                SwapData(i, j);
        }
    }
}

// Reverse by flipping every 'next' pointer
void LinkedList::Reverse()
{
    BookNode* previous = nullptr;
    BookNode* current = head;
    while (current != nullptr)
    {
        BookNode* nextNode = current->next; // remember the rest
        current->next = previous;              // flip the link
        previous = current;                    // move both pointers ahead
        current = nextNode;
    }
    head = previous;   // last node is now the first
}

// Display all books with their index
void LinkedList::Print() const
{
    if (IsEmpty())
    {
        cout << "\nNo books in the list.\n";
        return;
    }
    cout << "\nIndex\tID\tTitle\t\tAuthor\n";
    cout << "-----------------------------------------------\n";
    BookNode* current = head;
    int index = 0;
    while (current != nullptr)
    {
        cout << index << "\t" << current->bookID << "\t"
             << current->title << "\t\t" << current->author << endl;
        current = current->next;   // move to the next node
        index++;
    }
    cout << "Total books: " << count << endl;
}

bool LinkedList::IsEmpty() const { return head == nullptr; }
bool LinkedList::IsNotEmpty() const { return head != nullptr; }
int LinkedList::GetCount() const { return count; }
