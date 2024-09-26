#include <stdio.h>

#define ERROR -1

int day_of_year(int, int, int);
void month_day(int, int, int*, int*);
int isleap(int);

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

enum Boolean {FALSE, TRUE};

main() {
	int d, m;

	/* day_of_year error case				*/
	day_of_year(0, 1, 1);
	day_of_year(1, 0, 1);
	day_of_year(1, 13, 1);
	day_of_year(1, 1, 0);
	day_of_year(2023, 2, 29);
	day_of_year(2024, 2, 30);
	day_of_year(2023, 3, 32);
	day_of_year(2023, 4, 31);
	
	/* month_day error case					*/
	month_day(0, 1, &m, &d);
	month_day(1, 0, &m, &d);
	month_day(2023, 366, &m, &d);
	month_day(2024, 367, &m, &d);

	return 0;
}

/* day_of_year: set day of year from month & day		*/
int day_of_year(int year, int month, int day) {
	int i, leap = isleap(year);

	if (year <= 0) {
		printf("day_of_year: year must be (0 < year), but received %d\n", year);
		return ERROR;
	} else if (month <= 0 || month > 12) {
		printf("day_of_year: month must be (0 < month <= 12), but received %d\n", month);
		return ERROR;
	} else if (day <= 0) {
		printf("day_of_year: day must be (0 < day), but received %d\n", day);
		return ERROR;
	} else if (day > daytab[leap][month]){
		printf("day_of_year: there is only %d day in year %d month %d, but received %d\n", daytab[leap][month], year, month, day);
		return ERROR;
	} else {
		for (i = 1; i < month; i++)
			day += daytab[leap][i];
		return day;
	}
}

/* month_day: set month, day from day of year			*/
void month_day(int year, int yearday, int *pmonth, int *pday) {
	int error = FALSE, i, leap = isleap(year);

	if (year <= 0) {
		printf("month_day: year must be greater than 0, but received %d\n", year);
		error = TRUE;
	} else if (yearday <= 0) {
		printf("month_day: yearday must be greater than 0, but received %d\n", yearday);
		error = TRUE;
	} else if (isleap && yearday > 366) {
		printf("month_day: there is only 366 day in year %d, but received %d\n", year, yearday);
		error = TRUE;
	} else if (yearday > 365) {
		printf("month_day: there is only 365 day in year %d, but received %d\n", year, yearday);
		error = TRUE;
	}

	if (error) {
		*pmonth = -1;
		*pday = -1;
	} else {
		for (i = 1; yearday > daytab[leap][i]; i++)
			yearday -= daytab[leap][i];
		*pmonth = i;
		*pday = yearday;
	}
}

/* isleap: is the given year a leap year?			*/
int isleap(int year) {
	return (year%4 == 0 && year%100 != 0 || year%400 == 0);
}
