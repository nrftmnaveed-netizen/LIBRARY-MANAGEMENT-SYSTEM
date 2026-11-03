// ---------------------------------------------------------
// MAIN FILE - Lab 07 (Individual Project)
// Library Borrowing Session Navigator using a Doubly Linked List
// ---------------------------------------------------------
#include <iostream>
#include <string>
#include <limits>
#include "Book.h"
#include "DoublyLinkedList.h"
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

// Build a title node from user input
BookNode* ReadBook()
{
    int id = ReadInt("Enter book ID: ");
    string title = ReadLine("Enter title: ");
    string author = ReadLine("Enter author name: ");
    return new BookNode(id, title, author);
}

void ShowMenu()
{
    cout << "\n========================================\n";
    cout << " LIBRARY BORROWING SESSION (DOUBLY LIST)\n";
    cout << "========================================\n";
    cout << "1. Display Current Book\n";
    cout << "2. Move to Next Book\n";
    cout << "3. Move to Previous Book\n";
    cout << "4. Add Book at the End\n";
    cout << "5. Insert Book After Current\n";
    cout << "6. Remove Current Book\n";
    cout << "7. Display Session from First to Last\n";
    cout << "8. Display Session from Last to First\n";
    cout << "9. Exit\n";
}

int main()
{
    DoublyLinkedList session;

    // Demonstration data: books in a student borrowing session
    session.InsertRight(new BookNode(101, "Data Structures", "Mark Weiss"));
    session.InsertRight(new BookNode(102, "Database Systems", "Elmasri"));
    session.InsertRight(new BookNode(103, "Operating Systems", "Silberschatz"));

    int choice = 0;
    do
    {
        ShowMenu();
        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1:
            session.PrintCurrent();
            break;

        case 2:   // forward navigation
            if (session.Next())
                session.PrintCurrent();
            else
                cout << "No next title.\n";
            break;

        case 3:   // backward navigation
            if (session.Previous())
                session.PrintCurrent();
            else
                cout << "No previous title.\n";
            break;

        case 4:
            session.InsertRight(ReadBook());
            cout << "Book added at the end.\n";
            break;

        case 5:
            session.InsertAfterCurrent(ReadBook());
            cout << "Book inserted after current.\n";
            break;

        case 6:   // remove the entry being reviewed
        {
            BookNode* removed = session.RemoveCurrent();
            if (removed == nullptr)
                cout << "Session is empty.\n";
            else
            {
                cout << "Removed: " << removed->title << endl;
                delete removed;   // free removed node
                session.PrintCurrent();
            }
            break;
        }

        case 7:
            session.PrintForward();
            break;

        case 8:
            session.PrintBackward();
            break;

        case 9:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Enter 1-9.\n";
        }
    } while (choice != 9);

    return 0;
}
