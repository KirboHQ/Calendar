#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int writeCalendar(){
	
	int monthDays, firstMonthWday, update = 1;
	
	time_t rawtime = time(NULL);
	struct tm *pt = localtime(&rawtime);
	
	switch (pt->tm_wday) {						// A switch to write the current day of the week
		
		case 0:
			printf ("Sunday");
		break;
		case 1:
			printf ("Monday");
		break;
		case 2:
			printf ("Tuesday");
		break;
		case 3:
			printf ("Wednesday");
		break;
		case 4:
			printf ("Thursday");
		break;
		case 5:
			printf ("Friday");
		break;
		case 6:
			printf ("Saturday");
		break;
	}
	
	printf (" %02d ", pt->tm_mday);					// Outputting the current month day
	
	switch (pt->tm_mon + 1) {					// A switch to write the current month and to save how many days there are in that month
		case 1:
			printf ("January");
			monthDays = 31;
		break;
		case 2:
			printf ("February");
			if ((pt->tm_year + 1900) % 4 == 0) {
				
				monthDays = 29;
			}
			else {
				
				monthDays = 28;
			}
		break;
		case 3:
			printf ("March");
			monthDays = 31;
		break;
		case 4:
			printf ("April");
			monthDays = 30;
		break;
		case 5:
			printf ("May");
			monthDays = 31;
		break;
		case 6:
			printf ("June");
			monthDays = 30;
		break;
		case 7:
			printf ("July");
			monthDays = 31;
		break;
		case 8:
			printf ("August");
			monthDays = 31;
		break;
		case 9:
			printf ("September");
			monthDays = 30;
		break;
		case 10:
			printf ("October");
			monthDays = 31;
		break;
		case 11:
			printf ("November");
			monthDays = 30;
		break;
		case 12:
			printf ("December");
			monthDays = 31;
		break;
	}
	
	printf (" %d\n\nSund  Mond  Tues  Wedn  Thur  Frid  Satu\n", pt->tm_year + 1900);	// Outputting the current year
	
	firstMonthWday = pt->tm_wday;
		
	for (int i = pt->tm_mday; i > 1; i--) {
		
		if (firstMonthWday < 0) {
			
			firstMonthWday = 6;
		}
		else {
			firstMonthWday--;
		}
	}
	
	int currentWday = 0;
	
	for (int i = 1; i <= monthDays; i++) {							// Outputting the calendar
		
		if (i == 1 && currentWday != firstMonthWday) {
			
			printf ("    ");
			i--;
		}
		else if (i == pt->tm_mday){
			printf ("[%02d]", i);
		}
		else {
			printf (" %02d ", i);
			
		}
		
		currentWday++;
		
		if (currentWday <= 6) {
			
			printf ("  ");
		}
		else {
			
			currentWday = 0;
			printf ("\n");
		}
	}
	
	printf("\n\n");
}

int main () {
	
	writeCalendar();
	
	for (;;) {
		
		time_t rawtime = time(NULL);
		struct tm *pt = localtime(&rawtime);
		printf ("\r%02d:%02d:%02d                               ", pt->tm_hour, pt->tm_min, pt->tm_sec);	// Outputting the current time
	}
}
