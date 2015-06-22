// ISBN Processor
// OOP244.132 - Assignment 1
// a1main.cpp
// Version 1.1
// Chris Szalwinski
// Jan 14 2011

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

#define  PREFIX_LIST "prefixRanges.txt"
#include "ISBNPrefix.h"
#include "ISBN.h"

int main() {
    int keepgoing;
    char isbn[11];
    FILE* prefixFile = NULL;
    char area[6], publisher[8], title[7];

    cout << "ISBN Processor\n"
         << "==============\n";

    prefixFile = open(PREFIX_LIST);
    if (prefixFile == NULL)
        cerr << "Could not open file " << PREFIX_LIST << endl;
    else {
        keepgoing = 1;
        do {
            cout << "ISBN (0 to quit) : ";
            cin.getline(isbn, 11);
            if (!cin) {
                cin.clear();
                cin.ignore(2000, '\n');
                cerr << "Error. Try Again " << endl;
            }
            else if (strcmp(isbn, "0") == 0) {
                keepgoing = 0;
            }
            else if (strlen(isbn) != 10) {
                cerr << " Incorrect number of digits. Try again." << endl;
            }
            else if (isValid(isbn) == 0) {
                cerr << " Invalid check digit. Try again." << endl;
            }
            else if (isRegistered(prefixFile, isbn, area, publisher,
             title) == 0) {
                cerr << " This ISBN does not have a registered prefix."
                 << endl;
            }
            else {
                cout << " Area            : " << area << endl;
                cout << " Publisher       : " << publisher << endl;
                cout << " Title           : " << title << endl;
            }
            cout << endl;
        } while (keepgoing == 1);

        close(prefixFile);

        cout << "Signing off ... " << endl;
    }

    return 0;
}
