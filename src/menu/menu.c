#include <stdio.h>

#include "image_reader.h"

void menu_file_input(FileStatus *status) {

    printf("Enter Your file Name: ");
    //scanf("%199s",status.file_Name); 
    strcpy(status->file_Name, "C:/Users/USER/Desktop/my_Space/my_Project/image_Processing/using_C/WhatsAutoPost/imge_data/image.png");

    printf("%s\n",status->file_Name);/* Debug print */
}

void menu_time_input(userTime *inputTime) {
    int result = 0;

    do
    {
        printf("   Enter Hour: ");
        check_scanf_error_int(&inputTime->hour, "Invalid input! Please enter a valid numerical value for the Hour (0-12).");
        
        printf("Enter Minutes: ");
        check_scanf_error_int(&inputTime->min, "Invalid input! Please enter a valid numerical value for Minutes (0-59).");
        
        printf("   Enter Period (AM/PM): ");
        scanf("%s", inputTime->period);
        
        // Convert to 24-hour format before validation
        userTime twenty_4_hour_format = convert12To24(inputTime);
        
        result = is_time_valid(&twenty_4_hour_format);
        
        if (result == -1) {
            printf("Please enter a future time\n");
        }
    } while (result == -1);

    printf("Input time: %02d:%02d:%02d %s\n", inputTime->hour, inputTime->min, inputTime->seconds, inputTime->period);   
}

void check_scanf_error_int(int *field, const char *prompt) {
    // Loop until a valid integer input is provided
    while (scanf("%d", field) != 1) {
        printf(RED"%s\n"RESET, prompt);
        // Clear the input buffer by consuming characters until the newline is found
        while (getc(stdin) != '\n');  // Discard the invalid input
        printf("   Enter again: ");
    }
}

void check_scanf_error_str(char *field, const char *prompt) {
    // Loop until a valid string input is provided
    while (scanf("%2s", field) != 1 || (strcmp(field, "AM") != 0 && strcmp(field, "PM") != 0)
    && (strcmp(field, "am") != 0 && strcmp(field, "pm") != 0)) {
        printf(RED"%s\n"RESET, prompt);
        // Clear the input buffer by consuming characters until the newline is found
        while (getc(stdin) != '\n');  // Discard the invalid input
        printf("   Enter again: ");
    }
}

void convertToUpper(char *str) {
    while (*str) {
        *str = toupper(*str);  // Convert each character to uppercase
        str++;
    }
}

void sleep_seconds(int seconds) {
    #ifdef _WIN32
        Sleep(seconds * 1000);
    #else
        sleep(seconds);
    #endif
}