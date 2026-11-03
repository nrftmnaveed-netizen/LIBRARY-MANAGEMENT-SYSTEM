// ---------------------------------------------------------
// MAIN FILE - Lab 04
// Library Urgent Book Request Management using a Priority Queue
// ---------------------------------------------------------
#include <iostream>
#include <string>
#include <limits>
#include "BookRequest.h"
#include "PriorityQueue.h"
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

// Keep asking until the priority is 1, 2 or 3
int ReadPriority()
{
    int priority;
    do
    {
        priority = ReadInt("Enter Priority (1=Exam/Urgent, 2=Assignment/Project, 3=Normal Reading): ");
        if (priority < 1 || priority > 3)
            cout << "Priority must be 1, 2 or 3.\n";
    } while (priority < 1 || priority > 3);
    return priority;
}

void ShowMenu()
{
    cout << "\nLibrary Book Request System\n";
    cout << "1. Add Book Request\n";
    cout << "2. Process Highest Priority Request\n";
    cout << "3. Display All Requests\n";
    cout << "4. Check Queue Status\n";
    cout << "5. Exit\n";
}

int main()
{
    PriorityQueue requests;

    // Demonstration data (arrives in this order)
    requests.Add(new BookRequestNode(101, "Ali", 501, "Data Structures", 3));
    requests.Add(new BookRequestNode(102, "Ahmed", 502, "Database Systems", 1));
    requests.Add(new BookRequestNode(103, "Bilal", 503, "Operating Systems", 2));
    requests.Add(new BookRequestNode(104, "Hamza", 504, "Computer Networks", 1));

    int choice = 0;
    do
    {
        ShowMenu();
        choice = ReadInt("Enter your choice: ");

        switch (choice)
        {
        case 1:   // build node dynamically and add it by priority
        {
            int studentID = ReadInt("Enter Student ID: ");
            string studentName = ReadLine("Enter Student Name: ");
            int bookID = ReadInt("Enter Book ID: ");
            string bookTitle = ReadLine("Enter Book Title: ");
            int priority = ReadPriority();
            requests.Add(new BookRequestNode(studentID, studentName,
                                             bookID, bookTitle, priority));
            cout << "Request added.\n";
            break;
        }

        case 2:   // process the most urgent request
        {
            BookRequestNode* processed = requests.Remove();
            if (processed == nullptr)
                cout << "No pending requests.\n";
            else
            {
                cout << "\nProcessing request:\n";
                cout << "Student: " << processed->studentName << endl;
                cout << "Book: " << processed->bookTitle << endl;
                cout << "Priority: " << processed->priority << endl;
                delete processed;   // free memory
            }
            break;
        }

        case 3:
            requests.PrintQueue();
            break;

        case 4:   // status using IsEmpty / IsNotEmpty
            if (requests.IsEmpty())
                cout << "Queue status: EMPTY\n";
            else if (requests.IsNotEmpty())
                cout << "Queue status: NOT EMPTY ("
                     << requests.GetCount() << " pending)\n";
            break;

        case 5:
            cout << "Goodbye!\n";   // destructor frees remaining nodes
            break;

        default:
            cout << "Invalid choice. Enter 1-5.\n";
        }
    } while (choice != 5);

    return 0;
}
