#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }
    void closeFile() {
        if (fptr) fclose(fptr);
    }
    bool read(char postal[]) {
        bool success = false;
        if (fscanf(fptr, "%[^,],", postal)) {
            success = true;
        }
        return success;
    }
    bool read(int& pop) {
        bool success = false;
        if (fscanf(fptr, "%d\n", &pop)) {
            success = true;
        }
        return success;
    }
}