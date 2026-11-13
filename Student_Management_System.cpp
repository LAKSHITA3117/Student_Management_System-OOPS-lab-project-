#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student
{
public:
    int rollNo;
    string name, course;
    int semester;
    int marks[5];
    bool marksEntered;

    Student()
    {
        rollNo = 0;
        name = "";
        course = "";
        semester = 1;
        marksEntered = false;

        for (int i = 0; i < 5; i++)
            marks[i] = 0;
    }

    void addStudent()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter Course: ";
        getline(cin, course);

        cout << "Enter Semester: ";
        cin >> semester;

        cout << "\nStudent Added Successfully!\n";
    }

    void updateStudent()
    {
        cin.ignore();
        cout << "Enter New Name: ";
        getline(cin, name);

        cout << "Enter New Course: ";
        getline(cin, course);

        cout << "Enter New Semester: ";
        cin >> semester;

        cout << "\nStudent Record Updated!\n";
    }

    void displayStudent()
    {
        cout << "\nRoll Number : " << rollNo;
        cout << "\nName        : " << name;
        cout << "\nCourse      : " << course;
        cout << "\nSemester    : " << semester << endl;
    }

    void enterMarks()
    {
        cout << "\nEnter marks of 5 subjects (out of 100):\n";

        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];

            while (marks[i] < 0 || marks[i] > 100)
            {
                cout << "Enter marks between 0 and 100: ";
                cin >> marks[i];
            }
        }

        marksEntered = true;
        cout << "\nMarks Entered Successfully!\n";
    }

    int totalMarks()
    {
        int total = 0;

        for (int i = 0; i < 5; i++)
            total = total + marks[i];

        return total;
    }

    float percentage()
    {
        return totalMarks() / 5.0;
    }

    string grade()
    {
        if (percentage() >= 90)
            return "A+";
        else if (percentage() >= 80)
            return "A";
        else if (percentage() >= 70)
            return "B";
        else if (percentage() >= 60)
            return "C";
        else if (percentage() >= 50)
            return "D";
        else if (percentage() >= 33)
            return "E";
        else
            return "F";
    }

    void resultReport()
    {
        displayStudent();

        if (marksEntered == false)
        {
            cout << "\nMarks are not entered yet.\n";
            return;
        }

        cout << "\n--------- RESULT REPORT ---------\n";

        for (int i = 0; i < 5; i++)
            cout << "Subject " << i + 1 << " Marks: " << marks[i] << endl;

        cout << "Total Marks : " << totalMarks() << " / 500";
        cout << fixed << setprecision(2);
        cout << "\nPercentage  : " << percentage() << "%";
        cout << "\nGrade       : " << grade();

        bool pass = true;
        for (int i = 0; i < 5; i++)
        {
            if (marks[i] < 33)
                pass = false;
        }

        if (pass)
            cout << "\nResult      : PASS\n";
        else
            cout << "\nResult      : FAIL\n";

        cout << "---------------------------------\n";
    }
};

int main()
{
    Student s[100];
    int count = 0;
    int choice, roll, i, found;

    do
    {
        cout << "\n====================================\n";
        cout << "       STUDENT MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Add Student Record\n";
        cout << "2. Update Student Record\n";
        cout << "3. Search Student Details\n";
        cout << "4. Display All Students\n";
        cout << "5. Enter Student Marks\n";
        cout << "6. Generate Student Result Report\n";
        cout << "7. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (count < 100)
            {
                s[count].addStudent();
                count++;
            }
            else
            {
                cout << "Student list is full!\n";
            }
            break;

        case 2:
            cout << "Enter Roll Number to Update: ";
            cin >> roll;
            found = -1;

            for (i = 0; i < count; i++)
            {
                if (s[i].rollNo == roll)
                {
                    found = i;
                    break;
                }
            }

            if (found != -1)
                s[found].updateStudent();
            else
                cout << "Student Not Found!\n";
            break;

        case 3:
            cout << "Enter Roll Number to Search: ";
            cin >> roll;
            found = -1;

            for (i = 0; i < count; i++)
            {
                if (s[i].rollNo == roll)
                {
                    found = i;
                    break;
                }
            }

            if (found != -1)
                s[found].displayStudent();
            else
                cout << "Student Not Found!\n";
            break;

        case 4:
            if (count == 0)
            {
                cout << "No Student Records Available.\n";
            }
            else
            {
                cout << "\n--------- ALL STUDENTS ---------\n";
                for (i = 0; i < count; i++)
                {
                    s[i].displayStudent();
                    cout << "-------------------------------\n";
                }
            }
            break;

        case 5:
            cout << "Enter Roll Number: ";
            cin >> roll;
            found = -1;

            for (i = 0; i < count; i++)
            {
                if (s[i].rollNo == roll)
                {
                    found = i;
                    break;
                }
            }

            if (found != -1)
                s[found].enterMarks();
            else
                cout << "Student Not Found!\n";
            break;

        case 6:
            cout << "Enter Roll Number for Result: ";
            cin >> roll;
            found = -1;

            for (i = 0; i < count; i++)
            {
                if (s[i].rollNo == roll)
                {
                    found = i;
                    break;
                }
            }

            if (found != -1)
                s[found].resultReport();
            else
                cout << "Student Not Found!\n";
            break;

        case 7:
            cout << "\nThank You for Using Student Management System!\n";
            break;

        default:
            cout << "Invalid Choice! Please Try Again.\n";
        }

    } while (choice != 7);

    return 0;
}
