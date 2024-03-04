#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_STUDENTS = 20;

struct Date {
    int month;
    int day;
    int year;
};
struct Student {
    string name;
    Date birthday;
};
int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    char again;
    do {
        cout << "Name: ";
        getline(cin, students[numStudents].name);  
        cout << "Birthday (mm-dd-yyyy): ";
        cin >> students[numStudents].birthday.month >> students[numStudents].birthday.day >> students[numStudents].birthday.year;
        cout << endl;
        numStudents++;
        cout << "Enter 'Y' to add another student, or 'N' to finish: ";
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    } while (toupper(again) == 'Y'); 

    cout << "DATA SISWA" << endl;

    for (int i = 0; i < numStudents; i++) {
        cout << i + 1 << ". Name: " << students[i].name << endl;
        cout << "  Birthday: " << students[i].birthday.month << "-"
             << students[i].birthday.day << "-" << students[i].birthday.year << endl << endl;
    }

    return 0;
}