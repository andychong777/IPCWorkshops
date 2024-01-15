 //Helper Functions
void getFormattedDateTime(const struct Appointment* appoints, char* formattedDate)
{
    sprintf(formattedDate, "%04d%02d%02d%02d%02d" , appoints->date.year,
                                                    appoints->date.month,
                                                    appoints->date.day, 
                                                    appoints->date.hour, 
                                                    appoints->date.min);
}


void sortAppointmentsByDateTime(struct Appointment appoints[], int max)
{
    int iterIDx, tstEkemIdx, curMinIdx;
    struct Appointment tempVal;

    char curMinDate[ 12 + 1 ] = { 0 };
    char testDate [12 + 1] = { 0 };

    for  (iterIDx = 0; iterIDx < max; iterIDx++)
    {
        curMinIdx = iterIDx;

        getFormattedDateTime(&appoints[curMinIdx], curMinDate);

        for (tstEkemIdx = iterIDx + 1; tstEkemIdx < max; tstEkemIdx++)
        {
            getFormattedDateTime(&appoints[tstEkemIdx], testDate);

            if (strcmp(testDate, curMinDate) < 0)
            {
                curMinIdx = tstEkemIdx;

                getFormattedDateTime(&appoints[curMinIdx], curMinDate);
            }
            
        }
        if (curMinIdx != iterIDx)
        {
            tempVal = appoints[iterIDx];
            appoints[iterIDx] = appoints[curMinIdx];
            appoints[curMinIdx] = tempVal;
        }
        
    }
}
/////////////////////////////////
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* clinicData)
{
    int i;
    char dateTimeStr[20];

    displayScheduleHeader();

    sortByDateTime(clinicData->appointments, clinicData->maxAppointments);

    for (i = 0; i < clinicData->maxAppointments; i++)
    {
        struct Appointment appointment = clinicData->appointments[i];
        struct Patient patient = clinicData->patients[getPatientIndex(clinicData->patients, clinicData->maxPatient, appointment.patientNumber)];

        getFormattedDateTime(appointment.date, appointment.time, dateTimeStr);

        printf("%-15d%-15s%-15s%-15s\n", appointment.patientNumber, dateTimeStr, patient.phone.number, patient.phone.description);
    }

    printf("\n");
}


// View appointment schedule for the user input date
// Todo:
// View appointment schedule for the user input date
void viewAppointmentSchedule(struct ClinicData* data) 
{
    struct Date date;
    int i, j, lastDay;
    
    printf("Year        : ");
    date.year = inputIntPositive();

    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);

    if (date.month == 2) 
    {
        if (date.year % 4 == 0) 
        {
            lastDay = 29;
        } 
        else 
        {
            lastDay = 28;
        }
    } 
    else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) 
    {
        lastDay = 30;
    } 
    else 
    {
        lastDay = 31;
    }

    printf("Day (1-%d)  : ", lastDay);
    date.day = inputIntRange(1, lastDay);
    printf("\n");

    struct Appointment appointmentsForDate[data->maxAppointments];
    int numAppointmentsForDate = 0;

    for (i = 0; i < data->maxAppointments; i++) 
    {
        if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day) 
        {
            appointmentsForDate[numAppointmentsForDate] = data->appointments[i];
            numAppointmentsForDate++;
        }
    }

    if (numAppointmentsForDate == 0) 
    {
        printf("No appointments scheduled for the selected date.\n\n");
        return;
    }

    sortByDateTime(appointmentsForDate, numAppointmentsForDate);

    displayScheduleTableHeader(&date, numAppointmentsForDate);
    for (i = 0; i < numAppointmentsForDate; i++) 
    {
        struct Appointment* currentAppointment = &appointmentsForDate[i];
        struct Patient* currentPatient = NULL;

        for (j = 0; j < data->maxPatient; j++) 
        {
            if (data->patients[j].patientNumber == currentAppointment->patientNumber) 
            {
                currentPatient = &data->patients[j];
                break;
            }
        }

        if (currentPatient != NULL) 
        {
            displayScheduleData(currentPatient, currentAppointment, i+1);
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
            // Taking the year, month and day as input
            printf("Year        : ");
            date.year = inputIntPositive();
            printf("Month (1-12): ");
            date.month = inputIntRange(1, 12);
            printf("Day (1-%d)  : ", lastDay);
            if (date.month == 4 || date.month == 9 || date.month == 11) {
                lastDay = 30;
            }
            if (date.month == 2) {
                lastDay = 28;
                if (date.year % 4 == 0) {
                    lastDay = 29;
                }
            }
            printf("%d", lastDay);
            date.day = inputIntRange(1, lastDay);

            // Taking the appointment time as input
            printf("Hour (0-23)  : ");
            time.hour = inputIntRange(0, 23);
            printf("Minute (0-59): ");
            time.min = inputIntRange(0, 59);

            // Checking whether time slot is available
            if (isTimeSlotAvailable(date, time, app, maxAppointments)) {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }
            else {
                // Validating the appointment time
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
    // Declaring temporary structs
    struct Date date;
    int patientNumber, index, appointmentIndex, lastDay = 31;

    // Taking the patient number as input
    printf("Patient Number: ");
    patientNumber = inputIntPositive();

    // Check if the patient exists
    index = findPatientIndexByPatientNum(patientNumber, pt, maxPatients);
    if (index < 0) {
        printf("\nERROR: Patient record not found!\n\n");
        return;
    }

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

    // Check if appointment exists for patient and date
    appointmentIndex = findAppointmentIndexByPatientNumAndDate(patientNumber, date, app, maxAppointments);
    if (appointmentIndex < 0 || app[appointmentIndex].patientNumber != patientNumber) {
        printf("\nERROR: Appointment not found for the specified patient and date!\n\n");
        return;
    }

    // Display patient information and confirm removal
    displayPatientInfo(pt[index]);
    printf("\nAre you sure you want to remove the appointment (Y/N)? ");
    if (confirm()) {
        // Set appointment to safe empty state
        app[appointmentIndex].patientNumber = -1;
        app[appointmentIndex].date.year = 0;
        app[appointmentIndex].date.month = 0;
        app[appointmentIndex].date.day = 0;
        app[appointmentIndex].time.hour = 0;
        app[appointmentIndex].time.min = 0;
        printf("\n*** Appointment removed! ***\n\n");
    } else {
        printf("\n*** Removal cancelled. ***\n\n");
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////
//add
/*void getFormattedDateTime(struct Date date, struct Time time, char* dateTimeStr)
{
    sprintf(dateTimeStr, "%02d/%02d/%d %02d:%02d", date.month, date.day, date.year, time.hour, time.min);
}*/



//Using insertion sort to sort the appointments
void sortByDateTime(struct Appointment* appointments, int numAppointments) {
    // Sort appointments by date and time using bubble sort
    for (int i = 0; i < numAppointments - 1; i++) 
    {
        for (int j = 0; j < numAppointments - i - 1; j++) 
        {
            // Get formatted date and time strings for comparison
            char dateTime1[17], dateTime2[17];
            getFormattedDateTime(&appointments[j].date, &appointments[j].time, dateTime1);
            getFormattedDateTime(&appointments[j+1].date, &appointments[j+1].time, dateTime2);

            // Compare formatted date and time strings
            if (strcmp(dateTime1, dateTime2) > 0) 
            {
                // Swap appointments
                struct Appointment temp = appointments[j];
                appointments[j] = appointments[j+1];
                appointments[j+1] = temp;
            }
        }
    }
}

void getFixedDate(const struct Appointment* appoints, char* fixedDate)
{

}

void appointmentDate(struct Date* date)
{

}

// Checks to see whether a time slot is available
int isTimeSlotAvailable(struct Date date, struct Time time, struct Appointment* app, int maxAppointments) 
{
   
}

// Checks to see which is the next slot that is available and returns the index
int findNextAvailableSlot(struct Appointment* app, int maxAppointments) 
{
    
}


// Checks to see if an appointment is valid
int isAppointmentValid(int patientNumber, struct Date date, struct Appointment* app, int maxAppointments) 
{
   
}



//Function to compare two appointments
int compare(struct Appointment a1, struct Appointment a2) 
{
   
}
//add

//add

//add
