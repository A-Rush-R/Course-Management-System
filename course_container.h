#ifndef COURSE_CONTAINER_H
#define COURSE_CONTAINER_H

#include <bits/stdc++.h>
#include "course.h"
using namespace std;

enum class CourseColumn {
    NAME,
    CREDITS,
    TIME,
    APPLIED_CREDITS
};

class CourseContainer {
public:
    virtual ~CourseContainer() = default;

    virtual void addCourse(const Course& course);
    virtual void removeCourse(const string& courseName);
    virtual void listCourses();
    Course* findCourse(const string& courseName);
    virtual void printCourses() ;
    virtual void printHeader() ;

public:
    vector<Course> courses;
    vector<string> details;
    vector<CourseColumn> columns;

private:
    virtual void printAdditionalInfo() const = 0;
};

#endif
