#include <stdio.h>
#include <time.h>
#include "image_reader.h"

int is_time_valid(userTime *twenty_4_hour_format)
{
    time_t currentTime;
    struct tm *localTime;
    
    // Get the current time
    time(&currentTime);
    localTime = localtime(&currentTime);
    
    // Debug prints to see what we're comparing
    printf("System time: %02d:%02d\n", localTime->tm_hour, localTime->tm_min);
    printf("Input time: %02d:%02d\n", twenty_4_hour_format->hour, twenty_4_hour_format->min);
    
    // Convert 24-hour format hour to 12-hour for comparison
    int currentHour = localTime->tm_hour;
    
    if (twenty_4_hour_format->hour == currentHour) {
        // Same hour, check minutes
        if (twenty_4_hour_format->min <= localTime->tm_min) {
            printf("Input time is earlier than or equal to current time\n");
            return -1;
        } else {
            printf("Input time is valid future time\n");
            return 1;
        }
    } else if (twenty_4_hour_format->hour < currentHour) {
        printf("Input time is earlier than current time\n");
        return -1;
    } else {
        printf("Input time is valid future time\n");
        return 1;
    }
}

// Convert 12-hour to 24-hour format
userTime convert12To24(userTime *inputTime) {
    userTime result = *inputTime;  // Copy all fields
    
    if (strcasecmp(inputTime->period, "PM") == 0 && inputTime->hour != 12) {
        result.hour = inputTime->hour + 12;
    } else if (strcasecmp(inputTime->period, "AM") == 0 && inputTime->hour == 12) {
        result.hour = 0;
    } else {
        result.hour = inputTime->hour;
    }
    return result;
}

uint8_t check_time(userTime *inputTime){

    time_t currentTime;
    struct tm *localTime;
    // Get the current time
    time(&currentTime); /* gives the time in seconds passed since January 1, 1970 (the Unix epoch) */
    /*(the Unix epoch) == This is how Unix and Unix-like systems track time. is it right*/
    // Convert the current time to the local time
    localTime = localtime(&currentTime);

    printf(YELLOW"Current time: %02d:%02d:%02d\n"RESET, localTime->tm_hour, localTime->tm_min, localTime->tm_sec);

    // Extract the various components of the time
    int hours = localTime->tm_hour % 12; // Convert hour to 12-hour format (0-11)
    if (hours == 0) {
        hours = 12; // Midnight case
    }
    // Determine AM or PM
    char period[3];
    strcpy(period, (localTime->tm_hour >= 12) ? "PM" : "AM");

    int minutes = localTime->tm_min;
    int seconds = localTime->tm_sec;

    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1; // tm_mon is 0-11, so we add 1
    int year = localTime->tm_year + 1900; // tm_year is years since 1900
    // printf(YELLOW"in before covert time..."RESET);

    convertToUpper(period);
    // printf(YELLOW"in after covert time..."RESET);

    // Print the current time and date
    printf(YELLOW"Current time: %02d:%02d:%02d %s\n"RESET, hours, minutes, seconds, period);
    printf(YELLOW"Current date: %02d-%02d-%d\n"RESET, day, month, year);

    if(inputTime->hour == hours && inputTime->min == minutes)
    {printf(GREEN"Current time: %02d:%02d:%02d %s\n"RESET, hours, minutes, seconds, period);
     printf(GREEN"  INPUT TIME: %02d:%02d:%02d %s\n"RESET, inputTime->hour, inputTime->min, inputTime->seconds, inputTime->period);

        return 1;
    }
    else{
        return 0;
    }

    return 0;
}

