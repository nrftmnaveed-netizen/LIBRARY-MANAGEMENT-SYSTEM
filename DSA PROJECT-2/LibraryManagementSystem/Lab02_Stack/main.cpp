// ---------------------------------------------------------
// MAIN FILE - Lab 02 (Individual Project)
// Library Returned-Book Processing System using a Stack (LIFO)
// ---------------------------------------------------------
#include <iostream>
#include <string>
#include <limits>
#include "Book.h"
#include "Stack.h"
using namespace std;

// Read an integer safely
int ReadInt(const string& prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a number.\n";
    }
}

// Read a full line of text
string ReadLine(const string& prompt)
{
    string text;
    cout << prompt;
    getline(cin, text);
    return text;
}

// Build a book node from user input
BookNode* ReadBook()
{
    int id = ReadInt("Enter book ID: ");
    string title = ReadLine("Enter book title: ");
    string author = ReadLine("Enter author: ");
    return new BookNode(id, title, author);
}

void ShowMenu()
{
    cout << "\n========================================\n";
    cout << "   RETURNED-BOOK PROCESSING (STACK)\n";
    cout << "========================================\n";
    cout << "1. Add Returned Book (Push)\n";
    cout << "2. Process Top Book (Pop)\n";
    cout << "3. View Top Book (Peek)\n";
    cout << "4. Check if Stack is Empty\n";
    cout << "5. Check if Stack is Not Empty\n";
    cout << "6. Display All Books in the Pile\n";
    cout << "7. Test Copy Constructor and Assignment\n";
    cout << "8. Exit\n";
}

int main()
{
    Stack pile;

    // Demonstration data: pile of returned books (DSA ends up on top)
    pile.Push(new BookNode(104, "PF", "Deitel"));
    pile.Push(new BookNode(103, "OOP", "Stroustrup"));
    pile.Push(new BookNode(102, "DBMS", "Elmasri"));
    pile.Push(new BookNode(101, "DSA", "Mark Weiss"));

    int choice = 0;
    do
    {
        ShowMenu();
        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1:   // Push
            pile.Push(ReadBook());
            cout << "Book placed on top of the pile.\n";
            break;

        case 2:   // Pop
        {
            BookNode* removed = pile.Pop();
            if (removed == nullptr)
                cout << "The pile is empty. Nothing to process.\n";
            else
            {
                cout << "Processed book: " << removed->title << endl;
                delete removed;   // free memory of removed node
            }
            break;
        }

        case 3:   // Peek
        {
            BookNode* top = pile.GetTopValue();
            if (top == nullptr)
                cout << "The pile is empty.\n";
            else
                cout << "Top book: " << top->title
                     << " (" << top->author << ")\n";
            break;
        }

        case 4:
            cout << (pile.IsEmpty() ? "The pile is EMPTY.\n"
                                       : "The pile is NOT empty.\n");
            break;

        case 5:
            cout << (pile.IsNotEmpty() ? "The pile contains books.\n"
                                          : "The pile has no books.\n");
            break;

        case 6:
            pile.PrintStack();
            break;

        case 7:   // prove the copy is independent from the original
        {
            Stack copied(pile);     // copy constructor
            Stack assigned;
            assigned = pile;        // assignment operator

            // changing the copy must not change the original
            BookNode* removed = copied.Pop();
            delete removed;
            cout << "Original has " << pile.GetCount()
                 << " books, copy (after one Pop) has "
                 << copied.GetCount() << ", assigned has "
                 << assigned.GetCount() << ".\n";
            break;
        }

        case 8:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Enter 1-8.\n";
        }
    } while (choice != 8);

    return 0;
}
