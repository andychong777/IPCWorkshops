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
// function prototypes

//Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue 
void suspend(void);

// Integer value is entered and returned. If invalid, error
int inputInt(void);

//Positive integer value is entered and returned. If negative or zero, error
int inputIntPositive(void);

//Integer value is entered within range and returned. If outside range, error
int inputIntRange(int lowerBound, int upperBound);

//Single character is entered within list, If not in list Error
char inputCharOption(const char str[]);

//Cstring is entered containing the number of chars in range specified
void inputCString(char* cStr, int min, int max);

//display phone number
void displayFormattedPhone(const char* cStr);
