# Lab 06 - Featured Book Display Screen (Circular Linked List)

## 1. Real-world problem
A screen at the library entrance rotates through featured books. After the last book it must return to the first book and continue forever.

## 2. Why this linked list is suitable
In a circular list the last node points back to the first, so rotation never reaches nullptr and no special 'go back to start' logic is needed.

## 3. Node structure
```cpp
struct BookNode {
    int bookID;
    std::string title;
    std::string author;
    BookNode* next;   // last node's next = first node
};
```

## 4. Project files
| File | Purpose |
|------|---------|
| main.cpp | main() and menu |
| Book.h | structure file (BookNode) |
| CircularLinkedList.h | class declaration |
| CircularLinkedList.cpp | class member functions |

## 5. Compile and run
```
g++ main.cpp CircularLinkedList.cpp -o app
./app
```
