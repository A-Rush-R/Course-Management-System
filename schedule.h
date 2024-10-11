#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include "course.h"
using namespace std;

class Schedule {
public:
    void addCourse(const Course& course);
    void removeCourse(const string& courseName);
    void listCourses() const;
    int getTotalCredits() const;

private:
    vector<Course> courses;
};

#endif 