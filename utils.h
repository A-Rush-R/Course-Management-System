#include <iostream>
#include "utils.h"

int main() {
    double credits = -5.0;
    double age = 0;

    try {
        checkGreaterThanZero(credits, "Credits");
        checkGreaterThanZero(age, "Age");
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

