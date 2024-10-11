#include "utils.h"
#include <iostream>
using namespace std;

void checkGreaterThanZero(double value, const string& name) {
    if (value <= 0) {
        throw invalid_argument(name + " must be greater than 0");
    }
}

void checkNotEmpty(const string str, const string& name){
    if ( str.empty() ) {
        throw invalid_argument(name + " must not be empty");
    }
}

void checkGreaterThan(int big,int small, const string& bigName, const string& smallName){
    if ( big < small ){
        throw invalid_argument(bigName + " must not me less than " + smallName);
    }
}

void checkTimeValidity(int hour24, const string& name){
    if (hour24 < 0 || hour24 > 23) {
        throw invalid_argument(name + " must be between 0 and 23");
    }
}

string convertTo12Hour(int hour24) {
    int hour12 = (hour24 % 12 == 0) ? 12 : hour24 % 12;
    string period = (hour24 < 12) ? "AM" : "PM";

    return to_string(hour12) + " " + period;
}

