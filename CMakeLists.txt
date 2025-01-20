cmake_minimum_required(VERSION 3.10)
project(ImageReader C)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add subdirectories
add_subdirectory(src/check_time)
add_subdirectory(src/menu)
add_subdirectory(src/validate_contact)

# Add executable
add_executable(image_reader 
    src/image_reader.c
)

# Link libraries
target_link_libraries(image_reader 
    check_time
    menu
    contact
)