/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <time.h>
#include "report.h"

int main(int argc, char* argv[]) {
	week2(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	
	time_t current;
	struct tm* timeinfo;

	int year, month, day;
	char* WEEK[] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};
	printf("Enter YYYY MM DD : ");
	scanf("%d %d %d", &year, &month, &day);

	current = time(NULL);
	timeinfo = localtime(&current);

	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

	mktime(timeinfo);

	printf("% % % -> %s\n", year, month, day, WEEK[timeinfo->tm_wday]);
	
}