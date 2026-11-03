// ---------------------------------------------------------
// MAIN FILE - Lab 06 (Individual Project)
// Featured Book Display Screen using a Circular Linked List
// ---------------------------------------------------------
#include <iostream>
#include <string>
#include <limits>
#include "Book.h"
#include "CircularLinkedList.h"
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
    cout << "  FEATURED BOOK DISPLAY (CIRCULAR LIST)\n";
    cout << "========================================\n";
    cout << "1.  Display All Books\n";
    cout << "2.  Insert Book at Head\n";
    cout << "3.  Remove Book from Head\n";
    cout << "4.  Insert Book at Index\n";
    cout << "5.  Remove Book at Index\n";
    cout << "6.  Swap Books\n";
    cout << "7.  Sort Books by ID\n";
    cout << "8.  Reverse Collection\n";
    cout << "9.  Move to Next Book\n";
    cout << "10. Show Display Rotation (wraps around)\n";
    cout << "11. Verify Circular Link (last -> first)\n";
    cout << "12. Check Collection Status\n";
    cout << "13. Exit\n";
}

int main()
{
    CircularLinkedList collection;

    // Demonstration data of the project (pre-loaded)
    collection.InsertAt(new BookNode(103, "Operating Systems", "Silberschatz"), 0);
    collection.InsertAt(new BookNode(101, "Data Structures", "Mark Weiss"), 1);
    collection.InsertAt(new BookNode(104, "Software Engineering", "Sommerville"), 2);
    collection.InsertAt(new BookNode(102, "Database Systems", "Elmasri"), 3);

    int choice = 0;
    do
    {
        ShowMenu();
        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1:
            collection.Print();
            break;

        case 2:   // insert next to pivot
            collection.Insert(ReadBook());
            cout << "Book inserted at head.\n";
            break;

        case 3:   // remove next to pivot
        {
            BookNode* removed = collection.Remove();
            if (removed == nullptr)
                cout << "Collection is empty.\n";
            else
            {
                cout << "Removed: " << removed->title << endl;
                delete removed;   // free removed node
            }
            break;
        }

        case 4:
        {
            int index = ReadInt("Enter index (wraps if out of range): ");
            collection.InsertAt(ReadBook(), index);
            cout << "Book inserted.\n";
            break;
        }

        case 5:
        {
            if (collection.IsEmpty())
            {
                cout << "Collection is empty.\n";
                break;
            }
            int index = ReadInt("Enter index (wraps if out of range): ");
            BookNode* removed = collection.RemoveAt(index);
            cout << "Removed: " << removed->title << endl;
            delete removed;
            break;
        }

        case 6:
        {
            int a = ReadInt("Enter first index: ");
            int b = ReadInt("Enter second index: ");
            collection.Swap(a, b);
            cout << "Swap done.\n";
            break;
        }

        case 7:
            collection.Sort();
            cout << "Sorted by book ID.\n";
            break;

        case 8:
            collection.Reverse();
            cout << "Collection reversed.\n";
            break;

        case 9:   // move display one step around the circle
        {
            BookNode* book = collection.MoveToNext();
            if (book == nullptr)
                cout << "Collection is empty.\n";
            else
                cout << "Now displaying: " << book->title << endl;
            break;
        }

        case 10:  // show repeated rotation without reaching nullptr
        {
            int turns = ReadInt("How many turns to show? ");
            collection.PrintRotation(turns);
            break;
        }

        case 11:
            collection.VerifyCircular();
            break;

        case 12:
            if (collection.IsEmpty())
                cout << "Status: EMPTY\n";
            else if (collection.IsNotEmpty())
                cout << "Status: NOT EMPTY (" << collection.GetCount() << " books)\n";
            break;

        case 13:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Enter 1-13.\n";
        }
    } while (choice != 13);

    return 0;
}
