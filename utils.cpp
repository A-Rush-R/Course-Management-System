#include "utils.h"

void checkGreaterThanZero(double value, const std::string& name) {
    if (value <= 0) {
        throw std::invalid_argument(name + " must be greater than 0");
    }
}

void checkNotEmpty(const std::string str, const std::string& name){
    if ( str.empty() ) {
        throw std::invalid_argument(name + " must not be empty");
    }
}

void checkGreaterThan(int big,int small, const std::string& bigName, const std::string& smallName){
    if ( big < small ){
        throw std::invalid_argument(bigName + " must not me less than " + smallName);
    }
}

