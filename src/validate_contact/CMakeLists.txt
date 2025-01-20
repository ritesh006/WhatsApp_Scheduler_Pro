add_library(contact STATIC
    validate_contact.c
)

target_include_directories(contact PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)