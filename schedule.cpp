#include "schedule.h"
#include "utils.h"
#include <iostream>
using namespace std;

void Schedule::addCourse(const Course& course) {
    try {
        int newTotalCredits = getTotalCredits() + course.getMinCredits();
        checkGreaterThanZero(newTotalCredits, "Total Credits");
        CourseContainer::addCourse(course);
    } catch (const invalid_argument& e) {
        cerr << "Error adding course to schedule: " << e.what() << endl;
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