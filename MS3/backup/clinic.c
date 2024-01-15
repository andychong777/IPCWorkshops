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
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("\n");
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
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
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
void searchPatientData(const struct Patient patient[], int max) {
    int option;

    do {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");
        scanf("%d", &option);
        printf("\n");

        if (option == 1) {
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
        else if (option == 2) {
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
    } while (option != 0);
}


// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max) {
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
void editPatient(struct Patient patient[], int max) {
    int patientNum, patientIndex;
    printf("Enter the patient number: ");
    patientNum = inputInt();
    printf("\n");

    patientIndex = findPatientIndexByPatientNum(patientNum, patient, max);
    if (patientIndex == -1) {
        printf("ERROR: Patient record not found!\n");
        return;
    }

    menuPatientEdit(&patient[patientIndex]);
}


// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max) {
    int patientNum;
    char confirm;

    printf("Enter the patient number: ");
    patientNum = inputInt();
    printf("\n");

    int index = findPatientIndexByPatientNum(patientNum, patient, max);

    if (index != -1) {
        displayPatientData(&patient[index], FMT_FORM);
        printf("\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");
        
        confirm = inputCharOption("yn");

        switch (confirm) {

        case 'y':
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!\n");
            break;

        case 'n':
            printf("Operation aborted.\n");
            break;

        }
    }
    else {
        printf("ERROR: Patient record not found!\n");
    }
    printf("\n");
};





// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(struct ClinicData* data) {
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
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int input;

    printf("Search by patient number: ");
    scanf("%d", &input);
    printf("\n");

    int index = findPatientIndexByPatientNum(input, patient, max);

    if (index != -1) {
        displayPatientData(&patient[index], FMT_FORM);
        printf("\n");
    }
    else {
        printf("*** No records found ***\n\n");
    }

}

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    char input[PHONE_LEN + 1];
    int found = 0, i;

    printf("Search by phone number: ");
    scanf("%s", input);
    printf("\n");

    displayPatientTableHeader();
    for (i = 0; i < max; i++) {
        if (strcmp(patient[i].phone.number, input) == 0) {
            printf("%05d %-15s ", patient[i].patientNumber, patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);
            found = 1;
        }
    }
    printf("\n");

    if (!found) {
        printf("*** No records found ***\n\n");
    }
}

// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max) {
    int maxNumber = 0;
    int i;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber > maxNumber) {
            maxNumber = patient[i].patientNumber;
        }
    }
    return maxNumber + 1;
}


// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i;

    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == patientNumber) {
            return i;
        }
    }

    return -1;
}

// Checks to see whether a time slot is available
int isTimeSlotAvailable(struct Date date, struct Time time, struct Appointment* app, int maxAppointments) {
    int i;
    int slotAvailable = 0; // Initially, assume the time slot is not available

    for (i = 0; i < maxAppointments; i++) {
        // If the appointment is scheduled for the same date and time, the time slot is not available
        if (date.year == app[i].date.year && date.month == app[i].date.month && date.day == app[i].date.day && time.hour == app[i].time.hour && time.min == app[i].time.min) {
            slotAvailable = 1; 
            break; 
        }
    }
    return slotAvailable;
}

// Checks to see which is the next slot that is available and returns the index
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


// Checks to see if an appointment is valid
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

//Using insertion sort to sort the appointments
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

//Function to compare two appointments
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

void inputPatient(struct Patient* patient) {
    int i;
    char name[NAME_LEN + 1]; // Add one to hold null terminator

    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");

    do {
        inputCString(name, 1, NAME_LEN);

        if (strlen(name) > NAME_LEN) {
            printf("ERROR: String length must be no more than %d chars: ", NAME_LEN);
        }
        else {
            // Copy input to name field of patient struct and add null terminator
            for (i = 0; i < strlen(name) && i < NAME_LEN; i++) { // Add check for i < NAME_LEN
                patient->name[i] = name[i];
            }
            patient->name[i] = '\0';

            inputPhoneData(&patient->phone);
            break;
        }
    } while (1);
}


// Get user input for phone contact information
void inputPhoneData(struct Phone* phone) {
    int choice;
    char patientNumber[PHONE_LEN + 1];

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    choice = inputIntRange(1, 4);
    printf("\n");

    switch (choice) {
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
        *phone->number = 0;
        strcpy(phone->description, "TBD");
        return;
    default:
        printf("Invalid choice!\n");
        return;
    }

    if (choice == 1 || choice == 2 || choice == 3) {
        printf("Contact: %s\n", phone->description);
        printf("Number : "); 
        inputPhone(patientNumber, 10, 10);
        strcpy(phone->number, patientNumber);
        putchar('\n'); //added
    }
}





//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char* datafile, struct Patient patients[], int max) {
    int i = 0;

    FILE* fp;
    fp = fopen(datafile, "r");

    if (fp != NULL) {
        while (fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number) != EOF) {
            i++;
            if (i >= max)
                break;
        }
        fclose(fp);
    }

    else {
        printf("ERROR: File could not be read\n");
    }

    return i;
}



// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char* datafile, struct Appointment appoints[], int max) {
    int i, appointments = 0;

    FILE* fp;
    fp = fopen(datafile, "r");

    if (fp != NULL) {

        for (i = 0; i < max && !feof(fp); i++) {
            fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min);
            if (!feof(fp)) {
                appointments++;
            }
        }
        fclose(fp);
    }

    else {
        printf("ERROR: File could not be read\n");
    }
    return appointments;
}