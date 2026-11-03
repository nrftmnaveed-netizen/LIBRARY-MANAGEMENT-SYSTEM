#ifndef BOOK_H
#define BOOK_H

#include <string>

// ---------------------------------------------------------
// STRUCTURE FILE
// One node = one title entry in a student's medical session.
// Two self-referential pointers make the list bidirectional:
//   left  -> previous title (older)
//   right -> next title (newer)
// ---------------------------------------------------------
struct BookNode
{
    int bookID;             // unique title book ID
    std::string title;    // title / procedure description
    std::string author;       // author who handled it
    BookNode* left;      // previous entry
    BookNode* right;     // next entry

    BookNode(int id, std::string t, std::string d)
        : bookID(id), title(t), author(d),
          left(nullptr), right(nullptr) {}
};

#endif
