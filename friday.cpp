/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: bpedrofl
TASK: friday
LANG: C++

Is Friday the 13th really an unusual event?

That is, does the 13th of the month land on a Friday less often than on 
any other day of the week? To answer this question, write a program that
will compute the frequency that the 13th of each month lands on Sunday, 
Monday, Tuesday, Wednesday, Thursday, Friday, and Saturday over a given 
period of N years. The time period to test will be from January 1, 1900 
to December 31, 1900+N-1 for a given number of years, N. N is positive 
and will not exceed 400.

Note that the start year is NINETEEN HUNDRED, not NINETEEN NINETY.

There are few facts you need to know before you can solve this problem:

January 1, 1900 was on a Monday.
Thirty days has September, April, June, and November, all the rest have 
31 except for February which has 28 except in leap years when it has 29.
Every year evenly divisible by 4 is a leap year (1992 = 4*498 so 1992 will
be a leap year, but the year 1990 is not a leap year)

The rule above does not hold for century years. Century years divisible by
400 are leap years, all other are not. Thus, the century years 1700, 1800,
1900 and 2100 are not leap years, but 2000 is a leap year.
Do not use any built-in date functions in your computer language.

Don't just precompute the answers, either, please.

*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <fstream>
#include <string>
using namespace std;
//minus 64
int main() {
	ifstream fin("friday.in");
	ofstream fout("friday.out");
    int year = 1900;
    int years = 0;
    int dayCount = 1;
    //sat, sun, mon, tue, wed, thu, fri
    int daysOfThirteenth[7] = {0,0,0,0,0,0,0};
    int monthLength[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    //jan[31], feb[29/28], mar[31], apr[30], may[31], jun[30], jul[31], aug[31], sep[30], oct[31], nov[30], dec[31]
    //check if leap year

    fin >> years;
    for (int i = 0; i < years; i++){
    	year = 1900+i;
    	if (year%4 == 0){
    		if (year%100 == 0 && year%400 != 0){
    			monthLength[1] = 28;
    		} else monthLength[1] = 29;
    	} else monthLength[1] = 28;

    	for (int j = 0; j < 12; j++){
    		for (int k = 0; k < monthLength[j]; k++){
    			dayCount++;
    			if (k == 12){
    				daysOfThirteenth[dayCount%7]++;
    			}
    		}
    	}
    }
    for (int l = 0; l < 7; l++){
    	 fout << daysOfThirteenth[l];
		 if (l != 6) {fout << " ";}
		 else {fout << endl;}
    }
    return 0;
}
