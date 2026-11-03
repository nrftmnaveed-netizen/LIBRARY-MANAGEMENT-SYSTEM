# Lab 07 - Library Borrowing Session (Doubly Linked List)

## 1. Real-world problem
A librarian processes books for a student's borrowing session. The librarian moves back and forth through the books, inserts a book after the current one, or removes a wrongly entered book.

## 2. Why this linked list is suitable
Each node knows its previous and next book, so moving in both directions is O(1) and a node can be removed directly without searching for its predecessor.

## 3. Node structure
```cpp
struct BookNode {
    int bookID;
    std::string title;
    std::string author;
    BookNode* left;    // previous book
    BookNode* right;   // next book
};
```

## 4. Project files
| File | Purpose |
|------|---------|
| main.cpp | main() and menu |
| Book.h | structure file (BookNode) |
| DoublyLinkedList.h | class declaration |
| DoublyLinkedList.cpp | class member functions |

## 5. Compile and run
```
g++ main.cpp DoublyLinkedList.cpp -o app
./app
```
