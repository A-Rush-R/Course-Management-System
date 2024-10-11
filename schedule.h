#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "course_container.h"

class Schedule : public CourseContainer {
public:
    void addCourse(const Course& course) override;
    int getTotalCredits() const;

private:
    void printAdditionalInfo() const override;
};

#endif