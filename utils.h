#ifndef UTILS_H
#define UTILS_H

#include <stdexcept>
#include <string>
using namespace std;

void checkGreaterThanZero(double value, const std::string& name);
void checkNotEmpty(const std::string str, const std::string& name);
void checkGreaterThan(int big,int small, const std::string& bigName, const std::string& smallName);
void checkTimeValidity(int hour24, const string& name);
string convertTo12Hour(int hour24);

#endif

