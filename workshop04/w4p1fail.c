/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{
    int numberOfIteration, count;
    char loopType;

    //start
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");
do{

    printf("D = do/while | W = while | F = for | Q = quit\n");
    printf("Enter loop type and the number of times to iterate (Quit=Q0: ");
    scanf(" %c%d", &loopType, &numberOfIteration);

    if (loopType == 'D' || loopType == 'W' || loopType == 'F')
    {
        if (numberOfIteration >= 3 && numberOfIteration <=20)
        {
            if (loopType == 'D')
            {
                printf("DO-WHILE: ");
                for (count = 0; count < numberOfIteration; count++)
                {
                    putchar('D');
                }
                printf("\n\n");
            }
            else if (loopType == 'W')
            {
                printf("WHILE   : ");
                for (count = 0; count < numberOfIteration; count++)
                {
                    putchar('W');
                }
                printf("\n\n");
            }
            else if (loopType = 'F')
            {
                printf("FOR     : ");
                for (count = 0; count < numberOfIteration; count++)
                {
                    putchar('F');
                }
                printf("\n\n");
            }
        }
        else
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
        }
    }
    else if (loopType == 'Q')
    {
        if (numberOfIteration != 0)
        {
            printf("ERROR: to quit..must be 0");
        
    }
    else if  (loopType != 'D' || loopType != 'W'|| loopType != 'F'|| loopType != 'Q' )
    {
        printf("ERROR: Invalid entered value(s)!");
    }
    
} while (loopType != 'Q' && numberOfIteration != 0);
    return 0;
}