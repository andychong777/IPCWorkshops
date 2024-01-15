/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
Full Name  : Andy Chong
Student ID#: 150558229
Email      : achong11@myseneca.ca
Section    : NAA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_YEAR 2012 //define min/max years
#define MAX_YEAR 2022
#define LOG_DAYS 3 //Max days of data to collect from user

int main(void)
{
    //variables
    const int JAN = 1, DEC = 12;
    int validValue, moreLoop;
    int year, month;
    int i;
    double morningRating, eveningRating, morningSum = 0, eveningSum = 0;
    double avgMorning, avgEvening, avgRating;

    //general well-being log. Ask for year and month
    printf("General Well-being Log\n");
    printf("======================\n");

    //3 errors
    do{
        do{
            validValue = 1; //validValue = 1 (true) assume correct value would be entered

            printf("Set the year and month for the well-being log (YYYY MM): ");
            scanf("%d %d", &year, &month);    
        
                if (!(year >= MIN_YEAR && year <= MAX_YEAR))
                {   
                    validValue = 0;
                    printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
                }
                if (!(month >= JAN && month <= DEC))
                {   
                    validValue = 0;
                    printf("   ERROR: Jan.(1) - Dec.(12)\n");
                }
            
        } while (!validValue);
    
    putchar('\n');
    printf("*** Log date set! ***\n");  //log date set!
    putchar('\n');

    for (i = 1;i <= LOG_DAYS; i++)
    {
        switch (month)
        {
        case 1:
            printf("%d-JAN-0%d\n", year, i);
            break;
        case 2:
            printf("%d-FEB-0%d\n", year, i);
            break;
        case 3:
            printf("%d-MAR-0%d\n", year, i);
            break;
        case 4:
            printf("%d-APR-0%d\n", year, i);
            break;
        case 5:
            printf("%d-MAY-0%d\n", year, i);
            break;
        case 6:
            printf("%d-JUN-0%d\n", year, i);
            break;
        case 7:
            printf("%d-JUL-0%d\n", year, i);
            break;
        case 8:
            printf("%d-AUG-0%d\n", year, i);
            break;
        case 9:
            printf("%d-SEP-0%d\n", year, i);
            break;
        case 10:
            printf("%d-OCT-0%d\n", year, i);
            break;
        case 11:
            printf("%d-NOV-0%d\n", year, i);
            break;
        case 12:
            printf("%d-DEC-0%d\n", year, i);
            break;
        }
        do{
            validValue = 1;
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRating);

            if (morningRating < 0.0 || morningRating > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                validValue = 0;
            }
        }while (!validValue);

        do{
            validValue = 1;
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRating);

            if (eveningRating < 0.0 || eveningRating > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                validValue = 0;
            }

        }while (!validValue);

        putchar('\n');

        morningSum += morningRating; //total for morning/evening
        eveningSum += eveningRating;
    }

    //summary: total for morning/evening and avg for morning and evening
    avgMorning = morningSum/ LOG_DAYS;
    avgEvening = eveningSum / LOG_DAYS;
    avgRating = (avgMorning + avgEvening) / 2;

    printf("Summary\n");
    printf("=======\n");

    printf("Morning total rating: %.3lf\n", morningSum);
    printf("Evening total rating:  %.3lf\n", eveningSum);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", morningSum + eveningSum);

    printf("Average morning rating:  %.1lf\n", avgMorning);
    printf("Average evening rating:  %.1lf\n", avgEvening);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n\n", avgRating);

    moreLoop = 0;
    }while (moreLoop);
    
    return 0;
}