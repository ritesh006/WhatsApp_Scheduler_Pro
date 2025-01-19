add_library(check_time STATIC
    check_time.c
)

target_include_directories(check_time PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)