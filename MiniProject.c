#include <stdio.h>
#include <stdlib.h>

void day()
{
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int date, mon, year, i, r, s = 0;
char week[7]
[10]={"Sunday","Monday","Tuesday","Wednesday","Thursday",
"Friday","Saturday"};
printf("Enter a valid date (dd/mm/yyyy) : ");
scanf("%d / %d / %d", &date, &mon, &year);
if( (year / 4 == 0) && (year % 400 == 0) && (year % 100 != 0))
month[1] = 29;
for(i = 0 ; i< mon - 1 ; i++)
s = s + month[i];
s = s + (date + year + (year / 4) - 2);
s = s % 7;
printf("\nThe day is : %s\n\n", week[s]);
printf("**********************************************\n");
}


void printCalendar()
{
   int year,month,day,daysInMonth,weekDay=0,startingDay;
   printf("\nEnter the year:");
   scanf("%d",&year);


   char months[12][12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
   int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};


   if((year%4 == 0 && year%100!=0) || year%400 == 0)
   {
       monthDay[1]=29;
   }
   startingDay=(((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;


   for(month=0;month<12;month++){


      daysInMonth=monthDay[month];
      printf("\n\n *************%s****************\n",months[month]);
      printf("\n Sun Mon Tues Wed Thur Fri Sat\n");


      for(weekDay=0;weekDay<startingDay;weekDay++)
        printf(" ");


      for(day=1;day<=daysInMonth;day++){
        printf("%5d",day);


        if(++weekDay>6){
            printf("\n");
            weekDay=0;
        }
        startingDay=weekDay;
      }
      if(month==11){printf("\n\n");printf("**********************************************\n");}

   }

}

int main(){
    int choice;
    while (1) {
        printf("The Task that you "
               "want to perform\n\n");
        printf("1. Find the day of a date \n");
        printf("2. Print the calendar of a year \n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
        case 1:
            day();
            break;
        case 2:
            printCalendar();
            break;
        case 3:
	    exit(0);
	    break;
        }
    }
return 0;
}
