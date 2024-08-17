#include <iostream>
#include <string>

using namespace std;

string dayOfProgrammer(int year) {
    if (year == 1918) {
        // Special case for the year 1918, the transition year from Julian to Gregorian calendar in Russia
        return "26.09.1918";
    } else if ((year < 1918 && year % 4 == 0) || 
               (year > 1918 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))) {
        // Leap year cases for Julian calendar (before 1918) and Gregorian calendar (after 1918)
        return "12.09." + to_string(year);  // Return the date as a string
    } else {
        // Common year cases
        return "13.09." + to_string(year);  // Return the date as a string
    }
}

int main() {
    int year = 2024;
    string result = dayOfProgrammer(year);
    cout << "Day of the Programmer in " << year << ": " << result << endl;

    return 0;
}