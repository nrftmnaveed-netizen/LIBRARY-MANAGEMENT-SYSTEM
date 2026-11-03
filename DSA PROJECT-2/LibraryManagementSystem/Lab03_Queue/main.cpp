// ---------------------------------------------------------
// MAIN FILE - Lab 03 (Individual Project)
// Library Book Request Management using a Queue (FIFO)
// ---------------------------------------------------------
#include <iostream>
#include <string>
#include <limits>
#include "BookRequest.h"
#include "Queue.h"
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

void ShowMenu()
{
    cout << "\n===== Library Book Request Management System =====\n";
    cout << "1. Add Book Request\n";
    cout << "2. Serve Next Request\n";
    cout << "3. Display All Requests\n";
    cout << "4. Check if Queue is Empty\n";
    cout << "5. Check if Queue is Not Empty\n";
    cout << "6. Exit\n";
}

int main()
{
    Queue requests;

    // Demonstration data: students waiting for unavailable books
    requests.EnQueue(new BookRequestNode(101, "Ali", 501, "Database Systems"));
    requests.EnQueue(new BookRequestNode(102, "Ahmed", 501, "Database Systems"));
    requests.EnQueue(new BookRequestNode(103, "Bilal", 501, "Database Systems"));

    int choice = 0;
    do
    {
        ShowMenu();
        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1:   // take data at runtime, create node with new, EnQueue it
        {
            int studentID = ReadInt("Enter Student ID: ");
            string studentName = ReadLine("Enter Student Name: ");
            int bookID = ReadInt("Enter Book ID: ");
            string bookTitle = ReadLine("Enter Book Title: ");
            requests.EnQueue(new BookRequestNode(studentID, studentName,
                                                 bookID, bookTitle));
            cout << "Request added to the rear of the queue.\n";
            break;
        }

        case 2:   // DeQueue, show details, delete the served node
        {
            BookRequestNode* served = requests.DeQueue();
            if (served == nullptr)
                cout << "No requests to serve.\n";
            else
            {
                cout << "\nServed Request:\n";
                cout << "Student: " << served->studentName
                     << " (ID " << served->studentID << ")\n";
                cout << "Book: " << served->bookTitle
                     << " (ID " << served->bookID << ")\n";
                delete served;   // free memory
            }
            break;
        }

        case 3:
            requests.PrintQueue();
            break;

        case 4:
            if (requests.IsEmpty())
                cout << "Queue status: EMPTY\n";
            else
                cout << "Queue status: NOT empty\n";
            break;

        case 5:
            if (requests.IsNotEmpty())
                cout << "Queue status: contains " << requests.GetCount()
                     << " request(s)\n";
            else
                cout << "Queue status: no requests\n";
            break;

        case 6:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Enter 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}
