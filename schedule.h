#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "course_container.h"

class Schedule : public CourseContainer {
public:
    void addCourse(const Course& course) override;
    int getTotalCredits() const;
    Schedule() {
        columns.push_back(CourseColumn::NAME);
        columns.push_back(CourseColumn::APPLIED_CREDITS);
        columns.push_back(CourseColumn::TIME);
    }


private:
    void printAdditionalInfo() const override;
};

#endif