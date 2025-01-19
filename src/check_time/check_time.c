#include <stdio.h>
#include <time.h>
#include "image_reader.h"

uint8_t check_time(userTime *inputTime){

    time_t currentTime;
    struct tm *localTime;
    // Get the current time
    time(&currentTime); /* gives the time in seconds passed since January 1, 1970 (the Unix epoch) */
    /*(the Unix epoch) == This is how Unix and Unix-like systems track time. is it right*/
    // Convert the current time to the local time
    localTime = localtime(&currentTime);

    // Extract the various components of the time
    int hours = localTime->tm_hour % 12; // Convert hour to 12-hour format (0-11)
    if (hours == 0) {
        hours = 12; // Midnight case
    }
    // Determine AM or PM
    char* period = (localTime->tm_hour >= 12) ? "PM" : "AM";

    int minutes = localTime->tm_min;
    int seconds = localTime->tm_sec;

    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1; // tm_mon is 0-11, so we add 1
    int year = localTime->tm_year + 1900; // tm_year is years since 1900
    convertToUpper(period);
    // Print the current time and date
    printf(YELLOW"Current time: %02d:%02d:%02d %s\n"RESET, hours, minutes, seconds, period);
    printf(YELLOW"Current date: %02d-%02d-%d\n"RESET, day, month, year);

    if(inputTime->hour == hours && inputTime->min == minutes)
    {
        return 1;
    }
    else{
        return 0;
    }

    return 0;
}

