#ifndef COURSE_CONTAINER_H
#define COURSE_CONTAINER_H

#include <vector>
#include <string>
#include "course.h"

class CourseContainer {
public:
    virtual ~CourseContainer() = default;

    virtual void addCourse(const Course& course);
    virtual void removeCourse(const std::string& courseName);
    virtual void listCourses() const;
    Course* findCourse(const std::string& courseName);

protected:
    std::vector<Course> courses;

private:
    virtual void printAdditionalInfo() const = 0;
};

#endif
