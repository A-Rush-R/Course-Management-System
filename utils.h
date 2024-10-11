#ifndef UTILS_H
#define UTILS_H

#include <stdexcept>
#include <string>

void checkGreaterThanZero(double value, const std::string& name);
void checkNotEmpty(const std::string str, const std::string& name);
void checkGreaterThan(int big,int small, const std::string& bigName, const std::string& smallName);

#endif // UTILS_H

