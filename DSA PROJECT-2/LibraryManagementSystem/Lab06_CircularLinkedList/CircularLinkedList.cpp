// ---------------------------------------------------------
// CLASS MEMBER FUNCTION FILE
// Definitions of all CircularLinkedList member functions
// ---------------------------------------------------------
#include <iostream>
#include <utility>
#include "CircularLinkedList.h"
using namespace std;

// Constructor: empty collection
CircularLinkedList::CircularLinkedList()
{
    head = nullptr;
    displayed = nullptr;
    count = 0;
}

// Destructor: delete all nodes
CircularLinkedList::~CircularLinkedList()
{
    while (IsNotEmpty())
        delete Remove();
}

// Return node at index, counting from the first node (head->next)
BookNode* CircularLinkedList::GetNodeAt(int index)
{
    if (head == nullptr)
        return nullptr;
    BookNode* current = head->next;   // first node
    for (int i = 0; i < index; i++)
        current = current->next;
    return current;
}

// Exchange data (not links) of two nodes
void CircularLinkedList::SwapData(BookNode* a, BookNode* b)
{
    swap(a->bookID, b->bookID);
    swap(a->title, b->title);
    swap(a->author, b->author);
}

// Map any integer (even negative or huge) into 0..count-1
int CircularLinkedList::NormalizeIndex(int index) const
{
    return ((index % count) + count) % count;
}

// Insert as the first node (the node next to the pivot)
void CircularLinkedList::Insert(BookNode* book)
{
    if (book == nullptr)
        return;

    if (head == nullptr)
    {
        // first book: points to itself, forming a circle of one
        head = book;
        book->next = book;
        displayed = book;
    }
    else
    {
        // put the new node between pivot and old first node
        book->next = head->next;
        head->next = book;
    }
    count++;
}

// Remove the first node (the node next to the pivot)
BookNode* CircularLinkedList::Remove()
{
    if (IsEmpty())
        return nullptr;

    BookNode* first = head->next;

    // if the removed book is on display, display passes to the next one
    if (displayed == first)
        displayed = (first == head) ? nullptr : first->next;

    if (first == head)
        head = nullptr;            // it was the only node
    else
        head->next = first->next;  // pivot now skips the removed node

    first->next = nullptr;
    count--;
    return first;
}

// Insert at an index; wraps around the circle if index is out of range
void CircularLinkedList::InsertAt(BookNode* book, int index)
{
    if (book == nullptr)
        return;

    // empty list: same as a normal first insert
    if (count == 0)
    {
        Insert(book);
        return;
    }

    if (index < 0)
        index = NormalizeIndex(index);   // negative index wraps around
    if (index > count)
        index %= count;                  // too large index wraps around

    if (index == 0)                      // insert at front
    {
        Insert(book);
        return;
    }

    if (index == count)                  // insert at end: becomes new pivot
    {
        book->next = head->next;
        head->next = book;
        head = book;
        count++;
        return;
    }

    // insert in the middle, after the node at (index - 1)
    BookNode* previous = GetNodeAt(index - 1);
    book->next = previous->next;
    previous->next = book;
    count++;
}

// Remove at an index; index wraps around the circle
BookNode* CircularLinkedList::RemoveAt(int index)
{
    if (IsEmpty())
        return nullptr;

    index = NormalizeIndex(index);
    if (index == 0)
        return Remove();

    BookNode* previous = GetNodeAt(index - 1);
    BookNode* target = previous->next;

    // display passes forward if the removed book was on display
    if (displayed == target)
        displayed = target->next;

    previous->next = target->next;   // bypass the removed node
    if (target == head)
        head = previous;             // removed the last node -> new pivot

    target->next = nullptr;
    count--;
    return target;
}

// Swap two books' data; indexes wrap around
void CircularLinkedList::Swap(int index1, int index2)
{
    if (IsEmpty())
        return;
    index1 = NormalizeIndex(index1);
    index2 = NormalizeIndex(index2);
    if (index1 != index2)
        SwapData(GetNodeAt(index1), GetNodeAt(index2));
}

// Sort ascending by bookID
void CircularLinkedList::Sort()
{
    if (count < 2)
        return;

    BookNode* current = head->next;
    // outer loop: fix one position at a time
    for (int i = 0; i < count - 1; i++)
    {
        BookNode* nextNode = current->next;
        // inner loop: compare with every later node (count-based, no nullptr)
        for (int j = i + 1; j < count; j++)
        {
            if (current->bookID > nextNode->bookID)
                SwapData(current, nextNode);
            nextNode = nextNode->next;
        }
        current = current->next;
    }
}

// Reverse the circle by flipping every 'next' pointer
void CircularLinkedList::Reverse()
{
    if (count < 2)
        return;

    BookNode* oldTail = head;          // old last node
    BookNode* oldFirst = head->next;   // old first node
    BookNode* previous = oldTail;
    BookNode* current = oldFirst;

    // flip links until we come back around to the old tail
    while (current != oldTail)
    {
        BookNode* nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    oldTail->next = previous;   // old tail becomes the new first node
    head = oldFirst;            // old first becomes the new last (pivot)
}

// Print exactly 'count' nodes (a circle never reaches nullptr)
void CircularLinkedList::Print() const
{
    if (IsEmpty())
    {
        cout << "\nNo books in the collection.\n";
        return;
    }
    cout << "\nIndex\tID\tTitle\t\tAuthor\n";
    cout << "-----------------------------------------------\n";
    BookNode* current = head->next;
    for (int i = 0; i < count; i++)
    {
        cout << i << "\t" << current->bookID << "\t" << current->title
             << "\t\t" << current->author;
        if (current == displayed)
            cout << "  <-- NOW DISPLAYED";
        cout << endl;
        current = current->next;
    }
    cout << "Total books: " << count << endl;
}

// Move display to the next book; after the last book it returns to the first
BookNode* CircularLinkedList::MoveToNext()
{
    if (IsEmpty())
        return nullptr;
    displayed = displayed->next;
    return displayed;
}

BookNode* CircularLinkedList::GetDisplayed() const
{
    return displayed;
}

// Show who is on display for N consecutive turns (wraps around the circle)
void CircularLinkedList::PrintRotation(int turns)
{
    if (IsEmpty())
    {
        cout << "No books in the collection.\n";
        return;
    }
    BookNode* current = displayed;
    for (int turn = 1; turn <= turns; turn++)
    {
        cout << "Turn " << turn << ": " << current->title
             << " (" << current->author << ")\n";
        current = current->next;   // never becomes nullptr
    }
}

// Prove that the last node links back to the first node
void CircularLinkedList::VerifyCircular() const
{
    if (IsEmpty())
    {
        cout << "No books in the collection.\n";
        return;
    }
    cout << "Last node : " << head->title << endl;
    cout << "First node: " << head->next->title << endl;
    if (head->next != nullptr)
        cout << "Last node's next pointer leads back to the first node: YES\n";
}

bool CircularLinkedList::IsEmpty() const { return count == 0; }
bool CircularLinkedList::IsNotEmpty() const { return count > 0; }
int CircularLinkedList::GetCount() const { return count; }
