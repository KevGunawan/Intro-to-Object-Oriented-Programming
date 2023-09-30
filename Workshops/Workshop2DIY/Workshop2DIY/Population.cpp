#include <iostream>
#include "cstring.h"
#include "Population.h"
#include "File.h"

using namespace std;
namespace sdds {
    int noOfAddresses;
    Population* population;

    void sort() {
        int i, j;
        Population temp;
        for (i = noOfAddresses - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (population[j].pop > population[j + 1].pop) {
                    temp = population[j];
                    population[j] = population[j + 1];
                    population[j + 1] = temp;
                }
            }
        }
    }
    bool load(Population& population) {
        bool ok = false;
        char post[128];
        if (read(post) && read(population.pop)) {
            int len = (strLen(post) + 1);
            population.postal = new char[len];
            strCpy(population.postal, post);
            ok = true;
        }
        return ok;
    }
    bool load(const char * datafilename) {
        bool ok = false;
        int i = 0;
        if (openFile(datafilename)) {
            noOfAddresses = noOfRecords();
            population = new Population[noOfAddresses];
            for (i=0; i < noOfAddresses; i++) {
                load(population[i]);
            }
            if (i != noOfAddresses) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else {
                ok = true;
            }
        }
        else {
            cout << "Could not open data file: " << datafilename << endl;
        }
        closeFile();
        return ok;
    }
    void display(Population& population) {
        cout << population.postal << ":  " << population.pop << endl;
    }
    void display() {

        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        int total = 0;
        for (int i = 0; i < noOfAddresses; i++) {
            cout << i + 1 << "- ";
            display(population[i]);
            total += population[i].pop;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << total << endl;
    }
    void deallocateMemory() {
        int i = 0;
        for (i = 0; i < noOfAddresses; i++) {
            delete[] population[i].postal;
            population[i].postal = nullptr;
        }
        
        delete[] population;
        population = nullptr;
    }

}