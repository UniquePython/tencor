cmake_minimum_required(VERSION 3.16)
project(tencor LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)               # -std=c11, not gnu11
set(CMAKE_C_VISIBILITY_PRESET hidden)     # -fvisibility=hidden
set(CMAKE_POSITION_INDEPENDENT_CODE ON)   # -fPIC
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)     # for clangd / clang-tidy

file(GLOB_RECURSE TENCOR_SOURCES CONFIGURE_DEPENDS src/*.c)

add_library(tencor SHARED ${TENCOR_SOURCES})

target_include_directories(tencor
    PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(TENCOR_WARNINGS
    -Werror
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
    -Wconversion
    -Wsign-conversion
    -Wcast-qual
    -Wwrite-strings
    -Wformat=2
    -Wundef
    -Wstrict-prototypes
    -Wold-style-definition
    -Wimplicit-fallthrough
    -Wcast-align
    -Wvla
    -Wnull-dereference
    -Wdouble-promotion
    -Wstrict-overflow=5
    -Wswitch-enum
    -Wpointer-arith
    -Winit-self)

if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
    list(APPEND TENCOR_WARNINGS
        -Walloc-zero
        -Wlogical-op
        -Wformat-overflow=2
        -Wformat-truncation=2
        -Warray-bounds=2
        -Wstringop-overflow=4)
endif()

target_compile_options(tencor PRIVATE ${TENCOR_WARNINGS})
target_link_options(tencor PRIVATE -Wl,-z,defs)

set_target_properties(tencor PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
