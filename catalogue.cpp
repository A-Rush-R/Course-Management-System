#include "catalogue.h"
#include <iostream>
using namespace std;

void Catalogue::printAdditionalInfo() const {
    cout << "Total courses in catalogue: " << courses.size() << endl;
}