/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

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

// Ask user for an int input
int inputInt(void) {
    int input;
    char newLine = ' ';

    do {
        scanf("%d%c", &input, &newLine);

        if (newLine != '\n') {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    } while (newLine != '\n');

    return input;
}

// Use inputInt() until a positive value is given
int inputIntPositive(void) {
    int input;

    do {
        input = inputInt();

        if (!(input > 0)) {
            printf("ERROR! Value must be > 0: ");
        }

    } while (!(input > 0));

    return input;

}

// Verify if received input is within established range
int inputIntRange(int lowerBound, int upperBound) {
    int input;

    do {
        input = inputInt();

        if (!(input >= lowerBound && input <= upperBound)) {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
    } while (!(input >= lowerBound && input <= upperBound));

    return input;
}

// Check if received input char is an existing option
char inputCharOption(const char stringInput[]) {
    char input[20];
    char* ptr = NULL;

    do {
        scanf("%s", input);
        clearInputBuffer();

        if (strlen(input) > 1) {
            printf("ERROR: Character must be one of [%s]: ", stringInput);
        }
        else {
            ptr = strchr(stringInput, input[0]);
            if (ptr == NULL) {
                printf("ERROR: Character must be one of [%s]: ", stringInput);
            }
        }
    } while (ptr == NULL);

    return input[0];
}

// This function ensures that a C string value is entered with a length within the range specified by the minChar and maxChar parameters
void inputCString(char* str, int minChar, int maxChar) {
    int validInput = 0;
    char inputChar = 'a';

    while (!validInput) {
        int inputLength = 0;

        // Reads input from the user until a newline character or the maximum allowed characters is reached.
        while (inputChar != '\n' && inputLength <= maxChar) {
            inputChar = getchar();
            str[inputLength] = inputChar;
            inputLength++;
        }

        // If the input length is less than or equal to maxChar, add a null terminator to the end of the string.
        if (inputChar == '\n' && inputLength <= (maxChar + 1)) {
            inputLength--;
            str[inputLength] = '\0';
        }
        // If the input length exceeds maxChar, add a null terminator to the end and discard any extra characters.
        else {
            str[maxChar] = '\0';
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        // Check the input length and provide an error message if necessary.
        if (minChar == maxChar && inputLength != minChar) {
            printf("ERROR: String length must be exactly %d chars: ", minChar);
            inputChar = 'a';
        }
        else if (inputLength < minChar || inputLength > maxChar) {
            if (inputLength > maxChar) {
                printf("ERROR: String length must be no more than %d chars: ", maxChar);
                inputChar = 'a';
            }
            else if (inputLength < minChar) {
                printf("ERROR: String length must be between %d and %d chars: ", minChar, maxChar);
                inputChar = 'a';
            }
        }
        else {
            validInput = 1;
        }
    }
    printf("\n");
}


// Verify received number string length considering a possible min and max value
void inputPhone(char* str, int minChar, int maxChar) {
    int flag = 1;
    char ch = 'a';

    while (flag) {
        int len = 0;
        // Takes a string as input until it sees a newline character
        while (ch != '\n' && len <= maxChar) {
            ch = getchar();
            str[len] = ch;
            len++;
        };

        // If the string is less than or equal to the maxChars we will just add '\0' to the end to mark the end of the string
        if (ch == '\n' && len <= (maxChar + 1)) {
            len--;
            str[len] = '\0';
        }
        // If length is more than maxChar, we will add '\0' to the end and ignore the extra characters. We will also remove the extra characters from the buffer.
        else {
            str[maxChar] = '\0';
            clearInputBuffer();
        }

        if (minChar == maxChar && len != minChar) {
            printf("Invalid 10-digit number! Number: ");
            ch = 'a';
        }
        else {
            flag = 0;
        }
    }
}


// Display phone numbers according to an established format
void displayFormattedPhone(const char* phoneNumber) {
    int i;
    int length = 0;
    int validNum = 0;

    if (phoneNumber == NULL || *phoneNumber == '\0') {
        printf("(___)___-____");
        return;
    }

    for (i = 0; phoneNumber[i] != '\0'; i++) {
        if (phoneNumber[i] < '0' || phoneNumber[i] > '9') {
            printf("(___)___-____");
            return;
        }
        validNum++;
        length++;
    }

    if (validNum != 10 || length != 10) {
        printf("(___)___-____");
        return;
    }

    printf("(");
    for (i = 0; i < 3; i++) {
        printf("%c", phoneNumber[i]);
    }
    printf(")");
    for (i = 3; i < 6; i++) {
        printf("%c", phoneNumber[i]);
    }
    printf("-");
    for (i = 6; i < 10; i++) {
        printf("%c", phoneNumber[i]);
    }
}
