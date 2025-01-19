#ifndef IMAGE_READER_H
#define IMAGE_READER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// ANSI escape codes for text colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

// Define error codes
typedef enum {
    FILE_SUCCESS = 0,
    FILE_OPEN_ERROR = -1,
    FILE_SEEK_ERROR = -2,
    FILE_READ_ERROR = -3,
    FILE_SIZE_ERROR = -4,
    FILE_CLOSE_ERROR = -5,
    FILE_START_POSE_ERROR = -6

} FileError;

// Define error codes
typedef enum {
    TIME_SUCCESS = 1,
    TIME_ERROR = 0

} TimeError;

typedef struct {
    int code;
    long file_Size;
    char* message;
    int signature[4];
    char file_Name[200];
    
} FileStatus;

typedef struct {
    int hour;
    int min;
    int seconds;
    char period[3];
} userTime;

void menu_file_input(FileStatus *status);
void menu_time_input(userTime *status);
void read_file(FileStatus *status);
void error_handle(FileStatus *status);
void get_file_size(FileStatus *status);
void convertToUpper(char *str);
void sleep_seconds(int seconds);
void check_image_type(FileStatus *status);
void check_scanf_error_str(char *field, const char *prompt);
void check_scanf_error_int(int *field, const char *prompt);
uint8_t check_time(userTime *userTime);


#endif