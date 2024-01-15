#pragma once
#include <iostream>
#include <stdio.h>
// For malloc
#include <stdlib.h>
// For memset
#include <string.h>
// To edit file timestamps
#include <sys/stat.h>

#ifdef __WIN32
#define DEBUG_BREAK() __debugbreak()
#elif __linux__
#define DEBUG_BREAK() __builtin_trap(); // possibly __builtin_debugtrap() ?
#elif __APPLE__
#define DEBUG_BREAK() __builtin_trap()
#endif

enum TextColor {
    TEXT_COLOR_BLACK,
    TEXT_COLOR_RED,
    TEXT_COLOR_GREEN,
    TEXT_COLOR_YELLOW,
    TEXT_COLOR_BLUE,
    TEXT_COLOR_MAGENTA,
    TEXT_COLOR_CYAN,
    TEXT_COLOR_WHITE,
    TEXT_COLOR_BRIGHT_BLACK,
    TEXT_COLOR_BRIGHT_RED,
    TEXT_COLOR_BRIGHT_GREEN,
    TEXT_COLOR_BRIGHT_YELLOW,
    TEXT_COLOR_BRIGHT_BLUE,
    TEXT_COLOR_BRIGHT_MAGENTA,
    TEXT_COLOR_BRIGHT_CYAN,
    TEXT_COLOR_BRIGHT_WHITE,
    TEXT_COLOR_COUNT
};

template <typename ...Args>
void _log(char* prefix, char* msg, TextColor textColor, Args... args);

#define SM_TRACE(msg, ...) _log("TRACE: ", msg, TEXT_COLOR_GREEN, ##__VA_ARGS__);
#define SM_WARN(msg, ...) _log("WARN: ", msg, TEXT_COLOR_YELLOW, ##__VA_ARGS__);
#define SM_ERROR(msg, ...) _log("ERROR: ", msg, TEXT_COLOR_RED, ##__VA_ARGS__);

#define SM_ASSERT(x, msg, ...) {      \
    if (!x) {                         \
        SM_ERROR(msg, ##__VA_ARGS__); \
        DEBUG_BREAK();                \
    }                                 \
}

// ---------- Bump Allocator ----------

struct BumpAllocator {
    size_t capacity;
    size_t used;
    char* memory;
};

BumpAllocator make_bump_allocator(size_t size);

char* bump_alloc(BumpAllocator* bumpAllocator, size_t size);

// ---------- File IO ----------

/*
* Recieves the timestamp of a file
*/
long long get_timestamp(char* file);

/*
* Checks to see if a file exists
*/
bool file_exists(char* filePath);

/*
* Returns the size of a given file
*/
long get_file_size(char* filePath);

/*
* Reads a file into a suppied buffer
*/
char* read_file(char* filePath, int* fileSize, char* buffer);

/*
* Reads a file into our bump allocator
*/
char* read_file(char* filePath, int* fileSize, BumpAllocator* bumpAllocator);

/*
* Writes to a file in the given path
*/
void write_file(char* filePath, char* buffer, int size);

bool copy_file(char* fileName, char* outputName, char* buffer);

bool copy_file(char* fileName, char* outputName, BumpAllocator* BumpAllocator);