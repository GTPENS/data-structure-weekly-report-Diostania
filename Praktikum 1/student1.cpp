#include <iostream>
#include <string>
using namespace std;

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
  Student mhs;
  mhs.name = "MUHAMMAD IHSAN"; 
  mhs.birthday.month = 8;
  mhs.birthday.day = 10;
  mhs.birthday.year = 1970;
  cout << "Name: " << mhs.name << endl;
  cout << "Birthday: " << mhs.birthday.month << "/" << mhs.birthday.day << "/"
       << mhs.birthday.year << endl;
  return 0;
}