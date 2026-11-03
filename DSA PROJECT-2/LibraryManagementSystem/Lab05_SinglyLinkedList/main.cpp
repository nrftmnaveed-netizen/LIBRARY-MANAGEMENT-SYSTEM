// ---------------------------------------------------------
// MAIN FILE - Lab 05 (Individual Project)
// Library Book Collection using a Singly Linked List
// ---------------------------------------------------------
#include <iostream>
#include <string>
#include <limits>
#include "Book.h"
#include "LinkedList.h"
using namespace std;

// Read an integer safely (keeps asking until the input is valid)
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
        cin.clear();                                            // clear error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    // discard bad input
        cout << "Invalid input. Enter a number.\n";
    }
}

// Read one full line of text (allows spaces)
string ReadLine(const string& prompt)
{
    string text;
    cout << prompt;
    getline(cin, text);
    return text;
}

// Ask the user for book details and build a node
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
    cout << "   LIBRARY BOOK COLLECTION (SINGLY LIST)\n";
    cout << "========================================\n";
    cout << "1.  Display All Books\n";
    cout << "2.  Add Book at Head\n";
    cout << "3.  Remove Book from Head\n";
    cout << "4.  Add Book at Index\n";
    cout << "5.  Remove Book at Index\n";
    cout << "6.  Swap Two Books\n";
    cout << "7.  Sort Books by ID\n";
    cout << "8.  Reverse Book List\n";
    cout << "9.  Check List Status\n";
    cout << "10. Exit\n";
}

int main()
{
    LinkedList books;

    // Demonstration data of the project (pre-loaded)
    books.InsertAt(new BookNode(103, "Operating Systems", "Silberschatz"), 0);
    books.InsertAt(new BookNode(101, "Data Structures", "Mark Weiss"), 1);
    books.InsertAt(new BookNode(105, "Computer Networks", "Tanenbaum"), 2);
    books.InsertAt(new BookNode(102, "Database Systems", "Elmasri"), 3);

    int choice = 0;
    do
    {
        ShowMenu();
        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1:   // show every book
            books.Print();
            break;

        case 2:   // insert at head
            books.Insert(ReadBook());
            cout << "Book added at head.\n";
            break;

        case 3:   // remove from head
        {
            BookNode* removed = books.Remove();
            if (removed == nullptr)
                cout << "List is empty.\n";
            else
            {
                cout << "Removed: " << removed->title << endl;
                delete removed;   // free memory of removed node
            }
            break;
        }

        case 4:   // insert at index
        {
            int index = ReadInt("Enter index: ");
            books.InsertAt(ReadBook(), index);
            cout << "Book added.\n";
            break;
        }

        case 5:   // remove at index
        {
            if (books.IsEmpty())
            {
                cout << "List is empty.\n";
                break;
            }
            int index = ReadInt("Enter index to remove: ");
            BookNode* removed = books.RemoveAt(index);
            cout << "Removed: " << removed->title << endl;
            delete removed;
            break;
        }

        case 6:   // swap two books
        {
            int a = ReadInt("Enter first index: ");
            int b = ReadInt("Enter second index: ");
            if (books.Swap(a, b))
                cout << "Books swapped.\n";
            else
                cout << "Invalid index.\n";
            break;
        }

        case 7:
            books.Sort();
            cout << "Sorted by book ID.\n";
            break;

        case 8:
            books.Reverse();
            cout << "List reversed.\n";
            break;

        case 9:   // status check using IsEmpty / IsNotEmpty
            if (books.IsEmpty())
                cout << "Status: EMPTY\n";
            else if (books.IsNotEmpty())
                cout << "Status: NOT EMPTY (" << books.GetCount() << " books)\n";
            break;

        case 10:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Enter 1-10.\n";
        }
    } while (choice != 10);   // repeat until Exit

    return 0;
}
