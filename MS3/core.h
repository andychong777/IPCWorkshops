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

// SAFE-GUARD:
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

#include <stdio.h>
//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Integer value is entered and returned. If invalid, error
int inputInt(void);

//Positive integer value is entered and returned. If negative or zero, error
int inputIntPositive(void);

//Integer value is entered within range and returned. If outside range, error
int inputIntRange(int lowerBound, int upperBound);

//Single character is entered within list, If not in list Error
char inputCharOption(const char stringInput[]);

//Cstring is entered containing the number of chars in range specified
void inputCString(char* cStr, int min, int max);

//Check number string for min and max
void inputPhone(char* str, int minChar, int maxChar);

// Display phone numbers according to an established format
void displayFormattedPhone(const char* cStr);

// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H

