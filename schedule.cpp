#include "schedule.h"
#include "utils.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Schedule::addCourse(const Course& course) {
    try {
        int newTotalCredits = getTotalCredits() + course.getMinCredits();
        checkGreaterThanZero(newTotalCredits, "Total Credits");
        courses.push_back(course);
        cout << "Course added successfully." << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error adding course: " << e.what() << endl;
    }
}

void Schedule::removeCourse(const string& courseName) {
    auto it = find_if(courses.begin(), courses.end(),
                           [&courseName](const Course& c) { return c.getName() == courseName; });
    if (it != courses.end()) {
        courses.erase(it);
        cout << "Course removed successfully." << endl;
    } else {
        cout << "Course not found in the schedule." << endl;
    }
}

void Schedule::listCourses() const {
    if (courses.empty()) {
        cout << "No courses in the schedule." << endl;
        return;
    }
    cout << "Courses in the schedule:" << endl;
    for (const auto& course : courses) {
        cout << "- " << course.getName() << " (Credits: " << course.getMinCredits()
                  << "-" << course.getMaxCredits() << ")" << endl;
    }
    cout << "Total credits: " << getTotalCredits() << endl;
}

int Schedule::getTotalCredits() const {
    int totalCredits = 0;
    for (const auto& course : courses) {
        totalCredits += course.getMinCredits();
    }
    return totalCredits;
}
