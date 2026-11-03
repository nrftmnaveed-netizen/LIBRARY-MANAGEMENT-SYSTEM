#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "BookRequest.h"

// ---------------------------------------------------------
// CLASS FILE (declaration only)
// Priority Queue of library book requests.
//   front -> highest-priority request (processed first)
//   rear  -> last request in the queue
// Requests with equal priority keep their arrival order.
// Member function bodies are in PriorityQueue.cpp
// ---------------------------------------------------------
class PriorityQueue
{
private:
    BookRequestNode* front;
    BookRequestNode* rear;
    int count;

    void Clear();                              // delete all nodes
    void CopyFrom(const PriorityQueue& other); // deep copy

public:
    PriorityQueue();                                       // constructor
    PriorityQueue(const PriorityQueue& other);             // copy constructor
    PriorityQueue& operator=(const PriorityQueue& other);  // assignment operator
    ~PriorityQueue();                                      // destructor

    void Add(BookRequestNode* request);   // add according to priority
    BookRequestNode* Remove();            // remove highest priority
    bool IsEmpty() const;
    bool IsNotEmpty() const;
    int GetCount() const;
    void PrintQueue() const;                 // highest -> lowest priority
};

#endif
