#include "image_reader.h"


int main() 
{
    FileStatus status = {0, 0, "NO_PATH_STORED", 0, 0,0,0, "NO_INPUT_STORED"}; /* Structure Initialization */
    userTime time = {0, 0, 0,"AM"}; /* Structure Initialization */

    menu_file_input(&status);

    menu_time_input(&time);

    read_file(&status);

    if (status.code == FILE_SUCCESS) {
        error_handle(&status);
        get_file_size(&status);
        // Only print size if we got it successfully
        if (status.code == FILE_SUCCESS) {
            double size_kb = status.file_Size / 1024.0;
            double size_mb = size_kb / 1024.0;
            printf(GREEN"File size: %.2f MB (%.2f KB, %ld bytes)\n"RESET, 
                   size_mb, size_kb, status.file_Size);
        }
    }
    if (status.file_Size != 0)
    {
        check_image_type(&status);
    }

    while(1) 
    {  
        uint8_t time_match = check_time(&time);
        
        if(time_match == TIME_SUCCESS)
        {
            printf(CYAN"TIME MATCH..."RESET);
            break;
        }
        else if(time_match = TIME_ERROR)
        {
            printf(CYAN"TIME NOT MATCHING..."RESET);
        }
        
        sleep_seconds(60);  // Wait for 60 seconds before next check
    }

    

   

    return 0;
}

void error_handle(FileStatus *status)
{
    switch (status->code)
    {
        case FILE_SUCCESS: 
            printf(GREEN"Success: %s\n"RESET, status->message);
            break;
        case FILE_OPEN_ERROR: 
            printf(RED"Error: %s\n"RESET, status->message);
            break;
        case FILE_SEEK_ERROR:
            printf(RED"Error: %s\n"RESET, status->message);
            break;
        case FILE_START_POSE_ERROR:
            printf(RED"Error: %s\n"RESET, status->message);
            break;
        case FILE_CLOSE_ERROR:
            printf(RED"Error: %s\n"RESET, status->message);
            break;
        default: 
            printf("Unknown Error\n"RESET);
            break;
    }
}
void get_file_size(FileStatus *status)
{   FILE *image_file = fopen(status->file_Name, "rb");  // Open for reading
    if (image_file == NULL) {
        status->code = FILE_OPEN_ERROR;
        status->message = "Cannot open file for size check";
        return;
    }

    // storing current position 
    long current_pos = ftell(image_file);
    if (current_pos == FILE_START_POSE_ERROR) {
        status->code = FILE_START_POSE_ERROR;
        status->message = "Cannot get current position";
        fclose(image_file);
        return;
    }

    // Move to end of file
    if (fseek(image_file, 0L, SEEK_END) != FILE_SUCCESS) {
        status->code = FILE_SEEK_ERROR;
        status->message = "Cannot seek to end";
        fclose(image_file);
        return;
    }
    // Get position (which is file size)
    status->file_Size = ftell(image_file);

    // Restore original position
    if (status->file_Size == FILE_SIZE_ERROR) {
        status->code = FILE_SIZE_ERROR;
        status->message = "Cannot get file size";
        fclose(image_file);
        return;
    }

    if (fseek(image_file, current_pos, SEEK_SET) != 0) {
        status->code = FILE_SEEK_ERROR;
        status->message = "Cannot restore position";
        fclose(image_file);
        return;
    }

    status->code = FILE_SUCCESS;
    status->message = "File size obtained successfully";
    fclose(image_file);
}
void read_file(FileStatus *status)
{
    FILE *image_file = fopen(status->file_Name, "rb");  // Open for reading binary mode (rb)
    if(image_file == NULL) {
        status->code = FILE_OPEN_ERROR;
        status->message = "Cannot open file";
        return;
    }
    
    status->code = FILE_SUCCESS;
    status->message = "File opened successfully";
}

void check_image_type(FileStatus *status) {
    // Open file
    FILE *image_file = fopen(status->file_Name, "rb");
    if (image_file == NULL) {
        status->code = FILE_OPEN_ERROR;
        status->message = "Cannot open file";
        return;
    }
WhatsappContact contact; 
int test = validate_contact(contact.phone_number, contact.country_code);
    // Reset file pointer to beginning
    rewind(image_file);

    // Use unsigned char for precise byte reading
    unsigned char signature[4];
    size_t bytes_read = fread(signature, 1, 4, image_file);
    
    if (bytes_read < 4) {
        status->code = FILE_READ_ERROR;
        status->message = "Failed to read file signature";
        fclose(image_file);
        return;
    }

    // Print full signature
    printf(GREEN "Full Signature: " RESET);
    for (int i = 0; i < bytes_read; i++) {
        printf("%02X ", signature[i]);
    }
    printf("\n");

    // Signature checking
    unsigned char png_signature[] = {0x89, 0x50, 0x4E, 0x47};
    unsigned char jpeg_signature[] = {0xFF, 0xD8, 0xFF};
    unsigned char gif_signature[] = {0x47, 0x49, 0x46, 0x38};
    unsigned char bmp_signature[] = {0x42, 0x4D};

    // Store type in struct instead of printing directly
    if (memcmp(signature, png_signature, 4) == 0) {
        strncpy(status->type, "PNG Image", sizeof(status->type) - 1);
    } 
    else if (memcmp(signature, jpeg_signature, 3) == 0) {
        strncpy(status->type, "JPEG Image", sizeof(status->type) - 1);
    }
    else if (memcmp(signature, gif_signature, 4) == 0) {
        strncpy(status->type, "GIF Image", sizeof(status->type) - 1);
    }
    else if (memcmp(signature, bmp_signature, 2) == 0) {
        strncpy(status->type, "BMP Image", sizeof(status->type) - 1);
    }
    else {
        strncpy(status->type, "Unknown File Type", sizeof(status->type) - 1);
    }
    
    // Ensure null termination
    status->type[sizeof(status->type) - 1] = '\0';

    // Copy first 4 bytes to signature in struct
    memcpy(status->signature, signature, 4);

    printf(GREEN "File Type: %s\n" RESET, status->type);

    fclose(image_file);
}