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
    
    bool read(char name[]) {
        bool success = false;
        if (fscanf(fptr, "%[^\n]\n", name)){
            success = true;
        }
        return success;
    }
    bool read(int& empNum) {
        bool success = false;
        if (fscanf(fptr, "%d,", &empNum)) {
            success = true;
        }
        return success;
    }
    bool read(double& sal) {
        bool success = false;
        if (fscanf(fptr, "%lf,", &sal)){
            success = true;
        }
        return success;
    }
    
}