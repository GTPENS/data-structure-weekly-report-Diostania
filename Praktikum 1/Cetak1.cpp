#include <iostream>
#include <string>

using namespace std;

struct Date {
  int month;
  int day;
  int year;
};
void print_date(const Date& date) {
  static const string month_names[] = {
      "Wrong month", "January", "February", "March",
      "April", "May", "June", "July", "August",
      "September", "October", "November", "December"};
  cout << "Today's date is " << month_names[date.month] << " " << date.day << ", " << date.year << endl;
}

int main() {
  Date today;
  cout << "Enter the current date (mm-dd-yyyy): ";
  cin >> today.month >> today.day >> today.year;
  print_date(today);
  return 0;
}
