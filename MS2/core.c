/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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
#include <string.h>
#include "core.h"
//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// Integer value is entered and returned. If invalid, error
int inputInt(void)
{
    int value, validValue;
    char character = '\0';
    
    do {
        validValue = 1;
        scanf("%d%c", &value, &character);

        if (character != '\n') 
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
            validValue = 0;
        }
    } while (!validValue);

    //return valid int
    return value;
}

//Positive integer value is entered and returned. If negative or zero, error
int inputIntPositive(void) 
{
    int value, validValue;

    do {
        validValue = 1;
        value = inputInt();

        if (value <= 0) 
        {
            printf("ERROR! Value must be > 0: ");
            validValue = 0;
        }

    } while (!validValue); 

    //Return input int positive
    return value;
}

//Integer value is entered within range and returned. If outside range, error
int inputIntRange(int lowerBound, int upperBound) 
{
    int value, validValue;
 
    do {
        validValue = 1;
        value = inputInt();

        if (value < lowerBound || value > upperBound) 
        {
            printf("ERROR! Value must be between %d and %d inclusive: " ,lowerBound ,upperBound);
            validValue = 0;
        }
    } while (!validValue);

    //Return after checks are done
    return value;
}

//Single character is entered within list, If not in list Error
char inputCharOption(const char str[])
{
    int validvalue;
    char correctInput;
    char *validInput = NULL;
    char input[1000 + 1] = { 0 };

    do {
        validvalue = 0;
        scanf("%s", input);
        clearInputBuffer();

        correctInput = input[0];
       
        if (input[1] == '\0') 
        {
            validvalue = 1;
            validInput = strchr(input, correctInput);
        }
        if (validInput == NULL) 
        {
            validvalue = 1;
            printf("ERROR: Character must be one of [%s]: ", str);
        }
    } while (!validvalue);

    // After checks return input
    return correctInput;
}

//Cstring is entered containing the number of chars in range specified
void inputCString(char* cStr, int min, int max)
{
    int validValue;
    int length = 0; 
    char tmp [1000 + 1] = { 0 };
    
    do
    {   
        validValue = 1;      

        scanf("%1000[^\n]", tmp);
        clearInputBuffer();

        length = strlen(tmp);

        if (length < min || length > max)
        {
            if (min == max) 
            {
                printf("ERROR: String length must be exactly %d chars: ", min);
            }
            else if (length > max) 
            {
                printf("ERROR: String length must be no more than %d chars: ", max);
            }
            else if (length < min)
            {
                printf("ERROR: String length must be between %d and %d chars: ", min, max);   
            }
        }
        else
        {
            strcpy(cStr, tmp);
            validValue = 1;
        }

    } while (!validValue);

}

//display phone number
void displayFormattedPhone(const char* cStr)
{
    int i, validValue = 1; 
    int length = 0;

    if (cStr == NULL)
    {
        printf("(___)___-____");
    }
    else
    {
        for (i = 0; cStr[i] != '\0'; i++)
        {
            length++;

            if (cStr[i] > '9' || cStr[i] < '0')
            {
                validValue = 0;
            }
        }
        if (length != 10 || !validValue)
        {
            printf("(___)___-____");
        }
        else
        {
            for (i = 0; cStr[i] != '\0'; i++)
            {
                if (i == 0)
                {
                    putchar('(');
                }
                else if (i == 3)
                {
                    putchar(')');
                }
                else if (i == 6)
                {
                    putchar('-');
                }
                printf("%c", cStr[i]);
            }
            
        }
    }
}