#include "course_container.h"
#include "utils.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <bits/stdc++.h>

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

void CourseContainer::listCourses() {
    if (courses.empty()) {
        cout << "No courses available." << endl;
        return;
    }
    
    printHeader();
    cout << string(70, '-') << endl;

    printCourses();
    cout << string(70, '-') << endl;
    printAdditionalInfo();
}

Course* CourseContainer::findCourse(const string& courseName) {
    auto it = find_if(courses.begin(), courses.end(),
                           [&courseName](const Course& c) { return c.getName() == courseName; });
    return it != courses.end() ? &(*it) : nullptr;
}

void CourseContainer::printHeader() {
    for (const auto& column : columns) {
        switch (column) {
            case CourseColumn::NAME:
                cout << setw(30) << "Course Name" << endl;
                break;
            case CourseColumn::CREDITS:
                cout << setw(20) << "Credits" << endl;
                break;
            case CourseColumn::TIME:
                cout << setw(20) << "Time" << endl;
                break;
            case CourseColumn::APPLIED_CREDITS:
                cout << setw(20) << "Credits" << endl;
                break;
        }
    }
}

void CourseContainer::printCourses() {

    for ( auto course : courses) {
        for (const auto& column : columns) {
            switch (column) {
                case CourseColumn::NAME:
                    cout << setw(30) << course.getName() << endl;
                    break;
                case CourseColumn::CREDITS:
                    cout << setw(20) << (to_string(course.getMinCredits()) + "-" + to_string(course.getMaxCredits())) << endl;
                    break;
                case CourseColumn::TIME:
                    cout << setw(20) << (convertTo12Hour(course.getStartTime()) + "-" + convertTo12Hour(course.getEndTime())) << endl;
                    break;
                case CourseColumn::APPLIED_CREDITS:
                    cout << setw(20) << to_string(course.getCredits()) << endl;
                    break;
            }
        }
    }
}
