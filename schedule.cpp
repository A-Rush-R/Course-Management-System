#include "schedule.h"
#include "utils.h"
#include <iostream>
using namespace std;

void Schedule::addCourse(const Course& course) {
    try {

        checkGreaterThan(course.getMaxCredits(), course.getCredits(), "Max Credits", "Credits");
        checkGreaterThan(course.getCredits(), course.getMinCredits(), "Credits", "Min Credits");

        for ( Course c : courses) {
            if (c.getName() == course.getName()) {
                throw invalid_argument("Course already added");
            }
            else if ( c.clashesWith(course) ){
                throw invalid_argument("Course time conflict");
            }
        }
        
        courses.push_back(course);
    }
    catch (const invalid_argument& e) {
        cerr << "Error adding course: " << e.what() << endl;
    }
}

int Schedule::getTotalCredits() const {
    int totalCredits = 0;
    for (const auto& course : courses) {
        totalCredits += course.getMinCredits();
    }
    return totalCredits;
}

void Schedule::printAdditionalInfo() const {
    cout << "Total Credits: " << getTotalCredits() << endl;
}