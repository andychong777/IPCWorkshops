/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : JUAN JOSE MONCAYO GONZALEZ
Student ID#: 112572227
Email      : jgonzalez23@myseneca.ca
Section    : NEE

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

// Display phone numbers according to an established format
void displayFormattedPhone(const char* phoneNumber);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

 // Ask user for an int input
int inputInt(void);

// Use inputInt() until a positive value is given
int inputIntPositive(void);

// Verify if received input is within established range
int inputIntRange(int lowerBound, int upperBound);

// Check if received input char is an existing option
char inputCharOption(const char stringInput[]);

// Verify received input string length considering a possible min and max value
void inputCString(char* string, int min, int max);

// Verify received number string length considering a possible min and max value
void inputPhone(char* str, int minChar, int maxChar);


// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H

