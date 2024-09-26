#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int*, int*);

main() {
	int d, m;

	printf("[1988.02.29] %d days\n", day_of_year(1988, 2, 1));
	month_day(1988, -60, &m, &d);
	printf("[1988.0%d.%d] 60 days\n", m, d);

	return 0;
}
/****************************************************************/
static int isleap(int);

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day		*/
int day_of_year(int year, int month, int day) {
	int i, leap;

	leap = isleap(year);
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year			*/
void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

	leap = isleap(year);
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

/* isleap: is the given year a leap year?			*/
static int isleap(int year) {
	return (year%4 == 0 && year%100 != 0 || year%400 == 0);
}


