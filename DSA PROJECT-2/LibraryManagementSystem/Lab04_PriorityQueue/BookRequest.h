#ifndef BOOKREQUEST_H
#define BOOKREQUEST_H

#include <string>

// ---------------------------------------------------------
// STRUCTURE FILE
// One node = one book request from a student.
// Priority levels (smaller number = higher priority):
//   1 = Exam / urgent requirement
//   2 = Assignment / project
//   3 = Normal reading
// 'next' makes the node self-referential.
// ---------------------------------------------------------
struct BookRequestNode
{
    int studentID;              // unique student ID
    std::string studentName;    // student name
    int bookID;                 // unique book ID
    std::string bookTitle;      // requested book title
    int priority;               // 1 (highest) to 3 (lowest)
    BookRequestNode* next;      // next request in the queue

    // Constructor: a new request always starts unlinked
    BookRequestNode(int sid, std::string sname, int bid,
                    std::string title, int p)
        : studentID(sid), studentName(sname), bookID(bid),
          bookTitle(title), priority(p), next(nullptr) {}
};

#endif
