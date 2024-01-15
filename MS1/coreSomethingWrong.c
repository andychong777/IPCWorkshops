/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  : Andy Chong
Student ID#: 150558229
Email      : achong11@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#include <stdio.h>
#include "core.h"

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

int inputInt(void)
{
    char character = '\0';
    int value, validValue;

    do {
        validValue = 1;
        scanf("%d%c", &value, &character);

        if (character != '\n') 
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else
        {
            validValue = 0;
        }
    }
    while (!validValue);

    //return valid int
    return value;
}

int inputIntPositive(void)
{
    char character = '\0';
    int value, validValue;

    do {
        validValue = 1;
        scanf("%d%c", &value, &character);
        clearInputBuffer();
        if (character != '\n') 
        {
            //valid 
            printf("Error! Input a number: ");
        }
        else if (value <= 0) //just else
        {
            //valid
            printf("ERROR! Value must be > 0: ");
        }
        else
        {
            validValue = 0;
        }
    } while (validValue); //change to make it !valid

    //Return input int positive
    return value;
}

int inputIntRange(int lowerBound, int upperBound)
{
    char character = '\0';
    int value, validValue;
    int lowRange = lowerBound;
    int highRange = upperBound; //just use lower and upper

    do {
        validValue = 1;
        scanf("%d%c", &value, &character);

        if (character != '\n') 
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else if (value < lowRange || value > highRange) 
        {
            printf("ERROR! Value must be between %d and %d inclusive: " ,lowerBound ,upperBound);
        }
        else
        {
            validValue = 0;
        }
    }
    while (validValue);

    //Return after checks are done
    return value;
}

char inputCharOption(const char str[])
{
    int i, validvalue, count = 0;//del this
    char input;

    do {
        validvalue = 1;
        scanf("%c", &input);
        clearInputBuffer();

        for (i = 0; str[i] != '\0'; i++) 
        {
            if (input == str[i]) 
            {
                count = 1; //valid = 1
            }
        }
        if (!count) //!valid
        {
            printf("ERROR: Character must be one of [%s]: ", str);
        }
        else
        {
            validvalue = 0; //get rid of this
        }

    } while (validvalue); //not valid

    // After checks return input
    return input;
}

void inputCString(char* cStr, int min, int max)
{
    int validValue, i;
    int length;
    char tmp [1000 + 1] = { 0 };
    
    do
    {   
        validValue = 1;
        length = 0;       

        scanf("%1000[^\n]", tmp);
        clearInputBuffer();

        for (i = 0; tmp[i] != '\0'; i++)
        {
            length++;
        }

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
            validValue = 0;
        }

    }while (!validValue);
    
    for (i = 0; i < length; i++)
    {
        cStr[i] = tmp[i];
    }
    cStr[length] = '\0';

}

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
        else //loop
        {
            printf("(%c%c%c)%c%c%c-%c%c%c%c", cStr[0], cStr[1], cStr[2], cStr[3],
                   cStr[4], cStr[5], cStr[6], cStr[7], cStr[8], cStr[9]);
        }
    }
}
