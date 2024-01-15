#include "ddpn_lib.h"

template <typename ...Args>
void _log(char* prefix, char* msg, TextColor textColor, Args... args) {
    static char* TextColorTable[TEXT_COLOR_COUNT] = {
        "\x1b[30m",
        "\x1b[31m",
        "\x1b[32m",
        "\x1b[33m",
        "\x1b[34m",
        "\x1b[35m",
        "\x1b[36m",
        "\x1b[37m",
        "\x1b[90m",
        "\x1b[91m",
        "\x1b[92m",
        "\x1b[93m",
        "\x1b[94m",
        "\x1b[95m",
        "\x1b[96m",
        "\x1b[97m",
    };
    char formatBuffer[8192] = {};
    sprintf(formatBuffer, "%s %s %s \033[0m", TextColorTable[textColor], prefix, msg);
    char textBuffer[89120] = {};
    sprintf(textBuffer, formatBuffer, args...);
    puts(textBuffer);
}

// ---------- Bump Allocator Functions ----------

BumpAllocator make_bump_allocator(size_t size) {
    BumpAllocator ba = {};
    ba.memory = (char*) malloc(size);
    if (ba.memory) {
        ba.capacity = size;
        memset(ba.memory, 0, size);
    } else {
        SM_ASSERT(false, "Failed to allocate memory!")
    }
}

char* bump_alloc(BumpAllocator* bumpAllocator, size_t size) {
    char* result = nullptr;

    size_t allignedSize = (size + 7) & ~ 7; // sets first 4 bits to 0
    if (bumpAllocator->used + allignedSize <= bumpAllocator->capacity) {
        result = bumpAllocator->memory + bumpAllocator->used;
        bumpAllocator->used += allignedSize;
    } else {
        SM_ASSERT(false, "BumpAllocator is full")
    }
    
    return result;
}

// ---------- File IO ----------

long long get_timestamp(char* file) {
    struct stat file_stat = {};
    stat(file, &file_stat);
    return file_stat.st_mtime;
}

bool file_exists(char* filePath) {
    SM_ASSERT(filePath, "No filePath supplied!");
    auto file = fopen(filePath, "rb");
    if (!file) {
        return false;
    }
    fclose(file);
    return true;
}

long get_file_size(char* filePath) {
    SM_ASSERT(filePath, "No filePath supplied!");

    long fileSize = 0;
    auto file = fopen(filePath, "rb");
    if (!file) {
        SM_ERROR("Failed opening File: %s", filePath);
        return 0;
    }
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    fclose(file);

    return fileSize;
}

char* read_file(char* filePath, int* fileSize, char* buffer) {
    SM_ASSERT(filePath, "No filePath supplied!");
    SM_ASSERT(fileSize, "No fileSize supplied!");
    SM_ASSERT(buffer, "No buffer supplied!");

    *fileSize = 0;
    auto file = fopen(filePath, "rb");
    if (!file) {
        SM_ERROR("Failed opening file: %s", filePath);
        return nullptr;
    }

    fseek(file, 0, SEEK_END);
    *fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    memset(buffer, 0, *fileSize + 1); //+1 assures it has a nullptr
    fread(buffer, sizeof(char), *fileSize, file);

    fclose(file);

    return buffer;
}

char* read_file(char* filePath, int* fileSize, BumpAllocator* bumpAllocator) {
    char* file = nullptr;
    long fileSize2 = get_file_size(filePath);

    if (fileSize2) {
        char* buffer = bump_alloc(bumpAllocator, fileSize2 + 1);
        file = read_file(filePath, fileSize, buffer);
    }
    return file;
}

void write_file(char* filePath, char* buffer, int size) {
    SM_ASSERT(filePath, "No filePath supplied!");
    SM_ASSERT(buffer, "No buffer supplied!");
    auto file = fopen(filePath, "wb");
    if(!file) {
        SM_ERROR("Filed opening file: %s", filePath);
        return;
    }
    fwrite(buffer, sizeof(char), size, file);
    fclose(file);
}

bool copy_file(char* fileName, char* outputName, char* buffer) {
    int fileSize = 0;
    char* data = read_file(fileName, &fileSize, buffer);
    auto outputFile = fopen(outputName, "wb");
    if (!outputFile) {
        SM_ERROR("Failed opening file: %s", outputName);
        return false;
    }
    int result = fwrite(data, sizeof(char), fileSize, outputFile);
    if (!result) {
        SM_ERROR("Failed opening file: %s", outputName);
    }
    fclose(outputFile);
    return true;
}

bool copy_file(char* fileName, char* outputName, BumpAllocator* BumpAllocator) {
    char* file = 0;
    long fileSize2 = get_file_size(fileName);
    if (fileSize2) {
        char* buffer = bump_alloc(BumpAllocator, fileSize2 + 1);
        return copy_file(fileName, outputName, buffer);
    }
    return false;
}