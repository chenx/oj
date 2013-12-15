#include <iostream>
using namespace std;

// http://5dspace-time.org/Calendar/Algorithm.html
// get days from 1/1/1900 - is monday.
// y > 1900, m = 1..12, d = 1..31.
// acurrate for time after 1/1/0001.
int days(int y, int m, int d) {
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    //int n = (y - 1900) * 365 + (y - 1900)/4 - (y - 1900)/100 + (y - 1600)/400; //1600!
    int n = (y - 1) * 365 + y / 4 - y / 100 + y / 400; // based on 1/1/0001 - Monday
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0) ) { // is leap year
        if (m <= 2) n -= 1; // before march 1st, don't count the 1 more days.
    }
    for (int i = 0; i < m-1; i ++) {
        n += month[i];
    }
    n += d - 1;
    return n;
}

// Assumption: y >= 1, m = 1..12, d is reasonable for given month.
// return n = 0 ~ 6. week[n] is day of week in char format.
//
int dayOfWeek(int y, int m, int d) {
    char * week[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    int n = days(y, m, d);
    n %= 7;
    if (n < 0) n += 7; ///
    printf("%d/%d/%d is %s\n", m, d, y, week[n]);
    return n;
}

int showDays(int y, int m, int d) {
    int n = days(y, m, d);
    printf("days passed from %d/%d/%d: %d\n", m, d, y, n);  
    dayOfWeek(y, m, d);       
    return n; 
}

// get the 1st day of the month first.
// m = 1..12.
void make_calendar(int y, int m) {
    int d = dayOfWeek(y, m, 1);
    char * week[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (y % 4 == 0 || (y % 100 != 0 || y % 400 == 0)) month[1] += 1;
    int i;
    printf("== %d %d ==\n", m, y);
    for (i = 0; i < 7; i ++) { printf("  %s", week[i]); }
    puts("");
    for (i = 0; i < d; i ++) { printf("     "); }
    for (i = 0; i < month[m - 1]; i ++) {
        printf("%5d", 1+i);
        if ( (i + d) % 7 == 6) puts("");
    }
    puts("");
}

void testDays() {
    showDays(1900, 1, 1);
    showDays(1999, 12, 31);
    showDays(2000, 1, 1);
    showDays(2001, 1, 1);
            
    //return;
    showDays(1904, 1, 1);
    showDays(2000, 2, 29);
    showDays(2012, 12, 8);
    showDays(2012, 12, 9);
    showDays(2020, 2, 14);
    showDays(1776, 2, 14);
    showDays(1776, 7, 4);

    for (int i = 1; i <= 12; i ++) {   
      make_calendar(2012, i);
    }
}

int main() {
    testDays();
    return 0;
}
