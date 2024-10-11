#include "course_container.h"
#include "utils.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

void CourseContainer::addCourse(const Course& course) {
    courses.push_back(course);
    cout << "Course added successfully." << endl;
}

void CourseContainer::removeCourse(const string& courseName) {
    auto it = find_if(courses.begin(), courses.end(),
                           [&courseName](const Course& c) { return c.getName() == courseName; });
    if (it != courses.end()) {
        courses.erase(it);
        cout << "Course removed successfully." << endl;
    } else {
        cout << "Course not found." << endl;
    }
}

void CourseContainer::listCourses() const {
    if (courses.empty()) {
        cout << "No courses available." << endl;
        return;
    }
    
    cout << left
              << setw(30) << "Course Name"
              << setw(20) << "Credits"
              << setw(20) << "Time" << endl;
    
    cout << string(70, '-') << endl;

    for (const auto& course : courses) {
        cout << left
                  << setw(30) << course.getName()
                  << setw(20) << (to_string(course.getMinCredits()) + "-" + to_string(course.getMaxCredits()))
                  << setw(20) << (convertTo12Hour(course.getStartTime()) + "-" + convertTo12Hour(course.getEndTime()))
                  << endl;
    }

    cout << string(70, '-') << endl;
    printAdditionalInfo();
}

Course* CourseContainer::findCourse(const string& courseName) {
    auto it = find_if(courses.begin(), courses.end(),
                           [&courseName](const Course& c) { return c.getName() == courseName; });
    return it != courses.end() ? &(*it) : nullptr;
}
