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
    printf("+----------------------+\n");
    
    do{
        putchar('\n');
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &numberOfIteration);

        if (loopType == 'D' || loopType == 'W' || loopType == 'F')
        {
            if (numberOfIteration >= 3 && numberOfIteration <=20)
            {
                //for d
                if (loopType == 'D')
                {
                    count = 0;
                    printf("DO-WHILE: ");
                    do{
                        putchar(loopType);
                        count++;
                    } while (count < numberOfIteration);
                    putchar('\n');
                }
                //for w
                else if (loopType == 'W')
                {
                    count = 0;
                    printf("WHILE   : ");
                    while (count < numberOfIteration)
                    {
                      putchar(loopType);
                      count++; 
                    }
                    putchar('\n');
                }
                //for f
                else if (loopType == 'F')
                {
                    printf("FOR     : ");
                    for (count = 0; count < numberOfIteration; count++)
                    {
                        putchar('F');
                    }
                    putchar('\n');
                }

            }
            //errors
            else
            {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
            }
        }
        else if (loopType == 'Q' && numberOfIteration != 0)
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n");
        }
        else if (loopType != 'Q' && loopType != 'D' && loopType != 'W' && loopType != 'F')
        {
            printf("ERROR: Invalid entered value(s)!\n");
        }
    
    } while (!(loopType == 'Q' && numberOfIteration == 0));

    putchar('\n');
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    

    return 0;
}