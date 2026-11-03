#ifndef BOOK_H
#define BOOK_H

#include <string>

// ---------------------------------------------------------
// STRUCTURE FILE
// One node = one book in the display collection.
// 'next' points to the next book; the LAST book points
// back to the FIRST, so the collection repeats forever.
// ---------------------------------------------------------
struct BookNode
{
    int bookID;                 // unique book ID
    std::string title;             // book title
    std::string author;   // e.g. Cardiology
    BookNode* next;             // next book in the circle

    BookNode(int id, std::string n, std::string s)
        : bookID(id), title(n), author(s), next(nullptr) {}
};

#endif
