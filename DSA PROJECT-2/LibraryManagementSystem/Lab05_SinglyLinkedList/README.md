# Lab 05 - Library Book Collection (Singly Linked List)

## 1. Real-world problem
A library keeps a collection of books. New books are added at any position, damaged or lost books are removed, and the collection must be sorted by ID or reversed for reports.

## 2. Why this linked list is suitable
The collection grows and shrinks all the time, so a fixed array would waste space or run out. Inserting or removing in the middle only changes pointers; no elements are shifted.

## 3. Node structure
```cpp
struct BookNode {
    int bookID;
    std::string title;
    std::string author;
    BookNode* next;   // links to next book
};
```

## 4. Project files
| File | Purpose |
|------|---------|
| main.cpp | main() and menu |
| Book.h | structure file (BookNode) |
| LinkedList.h | class declaration |
| LinkedList.cpp | class member functions |

## 5. Compile and run
```
g++ main.cpp LinkedList.cpp -o app
./app
```
