add_library(menu STATIC
    menu.c
)

target_include_directories(menu PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)