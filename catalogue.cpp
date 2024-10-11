#include "catalogue.h"
#include "utils.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void Catalogue::addCourse(const Course& course) {
    courses.push_back(course);
    cout << "Course added to catalogue successfully." << endl;
}

void Catalogue::removeCourse(const string& courseName) {
    auto it = find_if(courses.begin(), courses.end(),
                           [&courseName](const Course& c) { return c.getName() == courseName; });
    if (it != courses.end()) {
        courses.erase(it);
        cout << "Course removed from catalogue successfully." << endl;
    } else {
        cout << "Course not found in the catalogue." << endl;
    }
}

void Catalogue::listCourses() const {
    if (courses.empty()) {
        cout << "No courses in the catalogue." << endl;
        return;
    }
    cout << "Courses in the catalogue:" << endl;
    
    cout << left
              << setw(30) << "Course Name"
              << setw(20) << "Credits"
              << setw(20) << "Time" << endl;
    
    cout << string(70, '-') << endl;

    for (const auto& course : courses) {
        cout << left
                  << setw(30) << course.getName()
                  << setw(20) << (to_string(course.getMinCredits()) + "-" + to_string(course.getMaxCredits()))
                  << setw(20) << (to_string(course.getStartTime()) + "-" + to_string(course.getEndTime()))
                  << endl;
    }
}

Course* Catalogue::findCourse(const string& courseName) {
    auto it = find_if(courses.begin(), courses.end(),
                           [&courseName](const Course& c) { return c.getName() == courseName; });
    return it != courses.end() ? &(*it) : nullptr;
}