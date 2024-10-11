#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <vector>
#include "course.h"
using namespace std;
class Catalogue {
public:
    void addCourse(const Course& course);
    void removeCourse(const string& courseName);
    void listCourses() const;
    Course* findCourse(const string& courseName);

private:
    vector<Course> courses;
};

#endif