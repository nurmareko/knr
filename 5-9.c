#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int*, int*);

main() {
	int d, m;

	printf("%d\n", day_of_year(2023, 3, 1));
	printf("%d\n", day_of_year(2024, 3, 1));

	month_day(1988, 60, &m, &d);
	printf("m: %d d: %d\n", m, d);

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
	char *p = daytab[isleap(year)];

	while (--month)
		day += *++p;
	return day;
}

/* month_day: set month, day from day of year			*/
void month_day(int year, int yearday, int *pmonth, int *pday) {
	int leap = isleap(year);
	char *p = daytab[leap];

	while (yearday > *++p)
		yearday -= *p;
	*pmonth = p - *(daytab + leap);
	*pday = yearday;
}

/* isleap: is the given year a leap year?			*/
static int isleap(int year) {
	return (year%4 == 0 && year%100 != 0 || year%400 == 0);
}


