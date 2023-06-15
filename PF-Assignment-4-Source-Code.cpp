#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100; // Maximum number of students in the array

struct Student {
    int rollNumber;
    string name;
    float marks;
};

Student students[MAX_STUDENTS]; // Array of structures to store student records
int numStudents = 0; // Current number of students in the array

void addStudent() {
    if (numStudents >= MAX_STUDENTS) {
        cout << "Maximum number of students reached." << endl;
        return;
    }

    Student newStudent;

    cout << "Enter roll number: ";
    cin >> newStudent.rollNumber;

    cout << "Enter name: ";
    cin.ignore(); // Ignore the newline character from previous input
    getline(cin, newStudent.name);

    cout << "Enter marks: ";
    cin >> newStudent.marks;

    students[numStudents] = newStudent;
    numStudents++;

    cout << "Student added successfully." << endl;
}

void displayStudents() {
    if (numStudents == 0) {
        cout << "No students found." << endl;
        return;
    }

    cout << "Student Records:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "Roll Number: " << students[i].rollNumber << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Marks: " << students[i].marks << endl;
        cout << endl;
    }
}

void searchStudent(int rollNumber) {
    bool found = false;

    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            cout << "Student Found:" << endl;
            cout << "Roll Number: " << students[i].rollNumber << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Marks: " << students[i].marks << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

void deleteStudent(int rollNumber) {
    bool found = false;

    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            // Move the last student to the current position to maintain array continuity
            students[i] = students[numStudents - 1];
            numStudents--;

            cout << "Student deleted successfully." << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found." << endl;
    }
}

int main() {
    int choice;
    int rollNumber;

    while (true) {
        cout << "Student Management System" << endl;
        cout << "1. Add a student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Search for a student" << endl;
        cout << "4. Delete a student" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                cout << "Enter roll number to search: ";
                cin >> rollNumber;
                searchStudent(rollNumber);
                break;
            case 4:
                cout << "Enter roll number to delete: ";
                cin >> rollNumber;
                deleteStudent(rollNumber);
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}

