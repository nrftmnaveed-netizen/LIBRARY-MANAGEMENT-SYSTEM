#ifndef BOOKREQUEST_H
#define BOOKREQUEST_H

#include <string>

// ---------------------------------------------------------
// STRUCTURE FILE
// One node = one book request from a student.
// The thing being queued is a REQUEST, not just a book,
// so the node stores both student and book information.
// 'next' makes the node self-referential.
// ---------------------------------------------------------
struct BookRequestNode
{
    int studentID;              // unique student ID
    std::string studentName;    // student name
    int bookID;                 // unique book ID
    std::string bookTitle;       // requested book title
    BookRequestNode* next;      // next request in the queue

    // Constructor: a new request always starts unlinked
    BookRequestNode(int sid, std::string sname, int id, std::string title)
        : studentID(sid), studentName(sname), bookID(id),
          bookTitle(title), next(nullptr) {}
};

#endif
