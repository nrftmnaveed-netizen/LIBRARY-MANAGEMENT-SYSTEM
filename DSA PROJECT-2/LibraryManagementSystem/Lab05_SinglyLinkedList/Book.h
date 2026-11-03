#ifndef BOOK_H
#define BOOK_H

#include <string>

// ---------------------------------------------------------
// STRUCTURE FILE
// One node = one book record.
// The node is "self-referential": it holds a pointer ('next')
// to another BookNode, which is how nodes get chained.
// ---------------------------------------------------------
struct BookNode
{
    int bookID;          // unique book ID
    std::string title;       // book title
    std::string author;    // book author
    BookNode* next;      // pointer to the next book in the list

    // Constructor: new node always starts unlinked (next = nullptr)
    BookNode(int id, std::string n, std::string d)
        : bookID(id), title(n), author(d), next(nullptr) {}
};

#endif
