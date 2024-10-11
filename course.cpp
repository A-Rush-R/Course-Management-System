#include<iostream>
#include "utils.h"
#include "course.h"


Course::CourseBuilder& Course::CourseBuilder::WithName(const std::string& name){
    this->name = name;
    return *this;
}

Course::CourseBuilder& Course::CourseBuilder::WithMinCredits(int credits){
    this->minCredits = credits;
    return *this;
}

Course::CourseBuilder& Course::CourseBuilder::WithMaxCredits(int credits){
    this->maxCredits = credits;
    return *this;
}

Course::CourseBuilder& Course::CourseBuilder::WithStartTime(int time){
    this->startTime = time;
    return *this;
}

Course::CourseBuilder& Course::CourseBuilder::WithEndTime(int time){
    this->endTime = time;
    return *this;
}

Course Course::CourseBuilder::build() const {

    try {
        checkGreaterThanZero(startTime, "Start Time");
        checkGreaterThanZero(endTime, "End Time");
        checkGreaterThanZero(minCredits, "Minimum Credits");
        checkGreaterThanZero(maxCredits, "Maximum Credits");

        checkNotEmpty(name, "Name");

        checkGreaterThan(maxCredits, minCredits, "Maximum Credits", "Minimum Credits");
        checkGreaterThan(endTime, startTime, "End Time", "Start Time");

    } catch (const std::invalid_argument& e) {
        throw;
    }

    return Course(name, startTime, endTime, maxCredits, minCredits);
}
