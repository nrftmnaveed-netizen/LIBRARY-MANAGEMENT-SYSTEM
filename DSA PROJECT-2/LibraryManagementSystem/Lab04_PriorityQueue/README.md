# Lab 04 - Library Urgent Book Requests (Priority Queue)

## 1. Real-world problem
A student who needs a book for an exam must be served before a student who wants it for general reading, even if the general-reading request arrived earlier.

## 2. Why a Priority Queue is required
Arrival order alone is not enough; urgency decides. Add() inserts each request at the position of its priority (equal priorities keep arrival order) and Remove() always takes the most urgent request from the front.

Priority levels (smaller number = higher priority):
- 1 = Exam / urgent requirement
- 2 = Assignment / project
- 3 = Normal reading

## 3. Node structure
```cpp
struct BookRequestNode {
    int studentID;
    std::string studentName;
    int bookID;
    std::string bookTitle;
    int priority;               // 1 (highest) to 3 (lowest)
    BookRequestNode* next;
};
```

## 4. Project files
| File | Purpose |
|------|---------|
| main.cpp | main() and menu |
| BookRequest.h | structure file (BookRequestNode) |
| PriorityQueue.h | class declaration |
| PriorityQueue.cpp | class member functions |

## 5. Compile and run
```
g++ main.cpp PriorityQueue.cpp -o app
./app
```
