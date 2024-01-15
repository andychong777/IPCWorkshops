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

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;
    int count = 0;

    displayPatientTableHeader();

    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt);
            count++;
        }
    }
    if (count == 0) {
        printf("*** No records found ***\n\n");
    }
    printf("\n");
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
    int optionNum, valid = 0;

    do {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");
        optionNum = inputIntRange(0, 2);

        if (optionNum == 1) {
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
        else if (optionNum == 2) {
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
    } while (optionNum != 0);
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int index;

    index = findPatientIndexByPatientNum(0, patient, max);

    if (index != -1) {
        patient[index].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[index]);
        //clearInputBuffer();
        printf("*** New patient record added ***\n\n");
    }
    else {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max) 
{
    int patientNumber, index;

    printf("Enter the patient number: ");
    patientNumber = inputIntPositive();
    putchar('\n');
    
    index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1) 
    {
        puts("ERROR: Patient record not found!");
        return;
    }
    
    menuPatientEdit(&patient[index]);
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
    int patientNumber, index;

    printf("Enter the patient number: ");

    patientNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNumber, patient, max);
    //putchar('\n');

    if (index == -1) 
    {
        putchar('\n');
        printf("ERROR: Patient record not found!\n");
        putchar('\n');
        return;
    }
    putchar('\n');

    displayPatientData(&patient[index], FMT_FORM);
    putchar('\n');

    printf("Are you sure you want to remove this patient record? (y/n): ");
    if (inputCharOption("yn") == 'y') 
    {
        patient[index].patientNumber = 0; 
        printf("Patient record has been removed!\n");
    }
    else 
    {
        printf("Operation aborted.\n");
    }
    putchar('\n'); //edit
}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data) 
{
    int i, index;

    sort(data->appointments, data->maxAppointments);

    displayScheduleTableHeader(NULL, 1);
    for (i = 0; i < data->maxAppointments; i++) {
        index = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);
            if (index != -1) {

                    displayScheduleData(&data->patients[index], &data->appointments[i], 1);
            }
    }
    printf("\n");
}


// View appointment schedule for the user input date
// Todo:
// View appointment schedule for the user input date
void viewAppointmentSchedule(struct ClinicData* data) {
    struct Date date;

    int i, j, lastDay = 31;

    printf("Year        : ");
    date.year = inputIntPositive();

    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);

    printf("Day (1-");
    if (date.month == 4 || date.month == 9 || date.month == 11) {
        lastDay = 30;
    }
    if (date.month == 2) {
        lastDay = 28;
    }
    if (date.year % 4 == 0 && date.month == 2) {
        lastDay = 29;
    }
    printf("%d)  : ", lastDay);
    date.day = inputIntRange(1, lastDay);
    printf("\n");

    sort(data->appointments, data->maxAppointments);

    displayScheduleTableHeader(&date, 0);
    for (i = 0; i < data->maxAppointments; i++) {
        for (j = 0; j < data->maxPatient; j++) {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber) {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) {
                    if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day) {
                        displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                    }
                }
            }
        }
    }
    printf("\n");
}


// Add an appointment record to the appointment array
// Todo:
// Add an appointment record to the appointment array
void addAppointment(struct Appointment* app, int maxAppointments, struct Patient* pt, int maxPatients) {
    // Declaring two temporary structs
    struct Date date;
    struct Time time;

    // Declaring variables
    int lastDay = 31;
    int patientNumber, index, slotNotAvailable = 1;

    // Taking the patient number as input
    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNumber, pt, maxPatients);

    if (index >= 0) {
        while (slotNotAvailable)
        {
            // Taking the year as input
            printf("Year        : ");
            date.year = inputIntPositive();

            // Taking the month as input
            printf("Month (1-12): ");
            date.month = inputIntRange(1, 12);

            // Taking the day as input
            printf("Day (1-");
            if (date.month == 4 || date.month == 9 || date.month == 11) {
                lastDay = 30;
            }
            if (date.month == 2) {
                lastDay = 28;
            }
            if (date.year % 4 == 0 && date.month == 2) {
                lastDay = 29;
            }

            printf("%d)  : ", lastDay);
            date.day = inputIntRange(1, lastDay);

            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);

            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);

            // Checking whether time slot is available
            if (isTimeSlotAvailable(date, time, app, maxAppointments)) {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }
            else {
                while ((time.hour < START_HOUR || time.hour > END_HOUR) || (time.hour == END_HOUR && time.min > 0) || (time.min % MINUTE_INTERVAL != 0)) {
                    printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START_HOUR, END_HOUR, MINUTE_INTERVAL);
                    printf("Hour (0-23)  : ");
                    time.hour = inputIntRange(0, 23);
                    printf("Minute (0-59): ");
                    time.min = inputIntRange(0, 59);
                }
                slotNotAvailable = 0;
            }
        }

        // Assigning the values to the next available slot
        index = findNextAvailableSlot(app, maxAppointments);
        app[index].date = date;
        app[index].time = time;
        app[index].patientNumber = patientNumber;
        printf("\n*** Appointment scheduled! ***\n\n");
    }
    else {
        printf("\nERROR: Patient record not found!\n\n");
    }
    return;
}



// Remove an appointment record from the appointment array
// Todo:
// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment* app, int maxAppointments, struct Patient* pt, int maxPatients) {
    struct Date date;
    int index, patientNumber, lastDay = 0, aptIndex;

    // Taking the patient number as input
    printf("Patient Number: ");
    patientNumber = inputIntPositive();
    index = findPatientIndexByPatientNum(patientNumber, pt, maxPatients);

    if (index >= 0) {
        // Taking the year as input
        printf("Year        : ");
        date.year = inputIntPositive();

        // Taking the month as input
        printf("Month (1-12): ");
        date.month = inputIntRange(1, 12);

        // Taking the day as input
        printf("Day (1-");
        if (date.month == 4 || date.month == 9 || date.month == 11) {
            lastDay = 30;
        }
        if (date.month == 2) {
            lastDay = 28;
        }
        if (date.year % 4 == 0 && date.month == 2) {
            lastDay = 29;
        }
        printf("%d)  : ", lastDay);
        date.day = inputIntRange(1, lastDay);

        aptIndex = isAppointmentValid(patientNumber, date, app, maxAppointments);

        if (aptIndex >= 0) {
            printf("\n");

            displayPatientData(&pt[index], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");

            if (inputCharOption("yn") == 'y') {
                app[aptIndex].patientNumber = 0;
                printf("\nAppointment record has been removed!\n\n");
            }

            else {
                printf("ERROR: No appointment for this date!\n\n");
            }
        }
    }
    else {
        printf("ERROR: Patient record not found!\n\n");
    }
}




//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int patientNum, index;
    
    printf("Search by patient number: ");
    patientNum = inputIntPositive();
    putchar('\n');
    
    index = findPatientIndexByPatientNum(patientNum, patient, max);

    if (index != -1) 
    {
        displayPatientData(&patient[index], FMT_FORM);
        printf("\n");
    }
    else {
        printf("*** No records found ***\n\n");
    }
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, count = 0, record = 0;
    char phoneNumber[PHONE_LEN + 1] = {'\0'};

    printf("Search by phone number: ");
    inputCString(phoneNumber, PHONE_LEN, PHONE_LEN);
    putchar('\n');

    
    displayPatientTableHeader();

    for (i = 0; i < max; i++) 
    {
        record = strcmp(patient[i].phone.number, phoneNumber);

        if (record == 0)
        {
            displayPatientData(&patient[i], FMT_TABLE);
            count++;
        }
    }

    if (count == 0) 
    {
        putchar('\n');
        printf("*** No records found ***\n");
    }
    putchar('\n');
    suspend();
}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, nextNumber;
    int maxNumber = patient[0].patientNumber;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > maxNumber)
        {
            maxNumber = patient[i].patientNumber;
        }
        
    }

    nextNumber = ++maxNumber;
    return nextNumber;
    
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber,
                                 const struct Patient patient[], int max)
{
    int i;

    for (i = 0; i < max; i++) 
    {
        if (patient[i].patientNumber == patientNumber) 
        {
            return i;
        }
    }

    // If anything is not found, return -1
    return -1;
}

//NEW FUNCTIONS
int isTimeSlotAvailable(struct Date date, struct Time time, struct Appointment* app, int maxAppointments)
{
    int i, timeAvailable = 0;

    for (i = 0; i < maxAppointments; i++) {
        // If the appointment is scheduled for the same date and time, the time slot is not available
        if (date.year == app[i].date.year && date.month == app[i].date.month
            && date.day == app[i].date.day && time.hour == app[i].time.hour && 
            time.min == app[i].time.min) 
        {
            timeAvailable = 1; 
            break; 
        }
    }
    return timeAvailable;
}

int findNextAvailableSlot(struct Appointment* app, int maxAppointments) {
    int i = 0;
    int availableSlotIndex = -1; // Initialize the slot index to -1 to indicate that no available slot was found

    while (i < maxAppointments && availableSlotIndex == -1) {
        if (app[i].patientNumber < 1) { // If the appointment is empty, it is an available slot
            availableSlotIndex = i; 
        }
        i++;
    }
    return availableSlotIndex;
}

int isAppointmentValid(int patientNumber, struct Date date, struct Appointment* app, int maxAppointments) {
    int i = 0;
    int validAppointmentIndex = -1; // Initialize the valid appointment index to -1 to indicate that no valid appointment was found

    while (i < maxAppointments && validAppointmentIndex == -1) {
        if (app[i].patientNumber == patientNumber && app[i].date.day == date.day && app[i].date.month == date.month && app[i].date.year == date.year) {
            validAppointmentIndex = i; // Save the index of the valid appointment
        }
        i++;
    }
    return validAppointmentIndex;
}

void sort(struct Appointment* appointments, int max) {
    int i, j;

    //Using insertion sort to sort the appointments
    for (i = 1; i < max; i++) {
        struct Appointment currentElement = appointments[i];
        j = i - 1;
        while (j >= 0 && compare(appointments[j], currentElement) > 0) {
            appointments[j + 1] = appointments[j];
            j--;
        }
        appointments[j + 1] = currentElement;
    }
}

int compare(struct Appointment a1, struct Appointment a2) {
    if (a1.date.year != a2.date.year) {
        return a1.date.year - a2.date.year;
    }
    else if (a1.date.month != a2.date.month) {
        return a1.date.month - a2.date.month;
    }
    else if (a1.date.day != a2.date.day) {
        return a1.date.day - a2.date.day;
    }
    else if (a1.time.hour != a2.time.hour) {
        return a1.time.hour - a2.time.hour;
    }
    else {
        return a1.time.min - a2.time.min;
    }
}
//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);

    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');

    inputPhoneData(&patient->phone);
}


// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
    int selection;
    char patientNumber[PHONE_LEN + 1];

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    selection = inputIntRange(1, 4);
    putchar('\n');

    switch (selection)
    {
    case 1:
        strcpy(phone->description, "CELL");
        break;
    case 2:
        strcpy(phone->description, "HOME");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        break;
    case 4:
        strcpy(phone->description, "TBD");
        *phone->number = 0;
        return;
    default:
        printf("Invalid choice!\n");
        return;
    }

    if (selection == 1 || selection == 2 || selection == 3) 
    {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, PHONE_LEN, PHONE_LEN);
        //putchar('\n'); //putback
    }
}



//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    FILE* fp = fopen(datafile, "r");

    int count = 0;

    if (fp != NULL) 
    {
        while (count < max && fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]",
                                     &patients[count].patientNumber, patients[count].name,
                                     patients[count].phone.description, patients[count].phone.number) != EOF) 
        {
            count++;
        }

        fclose(fp);
        fp = NULL;
    } 
    else 
    {
        puts("ERROR: File could not be read\n");
        count = -1;
    }

    return count;
}


// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    // Opening the file
    FILE* fp = fopen(datafile, "r");

    int count = 0;
    int i;

    // Checking for null pointer
    if (fp != NULL)
    {
        while (count < max && fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[count].patientNumber, 
                                    &appoints[count].date.year, &appoints[count].date.month, 
                                    &appoints[count].date.day, &appoints[count].time.hour,
                                    &appoints[count].time.min) == 6)
        {
            count++;
        }

        fclose(fp);
        fp = NULL;
    }
    else
    {
        puts("ERROR: File could not be read\n");
    }

    // Returning the number of records read
    return count;
}