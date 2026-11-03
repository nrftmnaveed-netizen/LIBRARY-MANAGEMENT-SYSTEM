#ifndef BOOK_H
#define BOOK_H

#include <string>

// ---------------------------------------------------------
// STRUCTURE FILE
// One node = one returned book on the pile.
// The node is "self-referential": 'next' points to another
// BookNode, which is how the stack is chained together.
// ---------------------------------------------------------
struct BookNode
{
    int bookID;      // unique book ID
    std::string title;      // book title
    std::string author;     // book author
    BookNode* next;  // node below this one in the stack

    // Constructor: a new node always starts unlinked
    BookNode(int id, std::string n, std::string c)
        : bookID(id), title(n), author(c), next(nullptr) {}
};

#endif
