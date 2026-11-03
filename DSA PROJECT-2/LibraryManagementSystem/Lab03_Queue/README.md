# Lab 03 - Library Book Request Management (Queue)

## 1. Real-world problem
Students request books that are currently unavailable. When a copy becomes available, the student who asked first must be served first.

## 2. Why FIFO is required
Requests must be handled in the order they arrive (First In, First Out). New requests join at the rear and the next available copy goes to the request at the front. Operations: EnQueue, DeQueue, IsEmpty, IsNotEmpty, PrintQueue, plus copy constructor, assignment operator and destructor.

## 3. Node structure
```cpp
struct BookRequestNode {
    int studentID;
    std::string studentName;
    int bookID;
    std::string bookTitle;
    BookRequestNode* next;
};
```

## 4. Project files
| File | Purpose |
|------|---------|
| main.cpp | main() and menu |
| BookRequest.h | structure file (BookRequestNode) |
| Queue.h | class declaration |
| Queue.cpp | class member functions |

## 5. Compile and run
```
g++ main.cpp Queue.cpp -o app
./app
```
