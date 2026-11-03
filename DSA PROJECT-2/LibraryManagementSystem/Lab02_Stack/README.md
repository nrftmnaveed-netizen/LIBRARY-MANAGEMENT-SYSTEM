# Lab 02 - Library Returned-Book Processing (Stack)

## 1. Real-world problem
Returned books are placed one on top of another on a small shelf. The librarian can only take the top book; books below cannot be reached directly.

## 2. Why LIFO is required
The most recently returned book must be the first one processed (Last In, First Out). No value-based ordering is needed and no book in the middle can be accessed directly, which is exactly how a stack works. Operations: Push, Pop, GetTopValue, IsEmpty, IsNotEmpty, PrintStack, plus copy constructor, assignment operator and destructor.

## 3. Node structure
```cpp
struct BookNode {
    int bookID;
    std::string title;
    std::string author;
    BookNode* next;   // book below in the pile
};
```

## 4. Project files
| File | Purpose |
|------|---------|
| main.cpp | main() and menu |
| Book.h | structure file (BookNode) |
| Stack.h | class declaration |
| Stack.cpp | class member functions |

## 5. Compile and run
```
g++ main.cpp Stack.cpp -o app
./app
```
