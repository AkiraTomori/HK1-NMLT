#include "Support.h"

bool isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
int getDaysInMonth(int month, int year)
{
    if (month == 2) return isLeapYear(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    else
        return 31;
}

void header1(){
    cout << "---------------------------------------------------------\n";
}

void header2(){
    cout << "=========================================================\n";
}