#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
using namespace std;

class Course {
public:
    class CourseBuilder;

	string getName() const { return name; }
    int getMinCredits() const { return minCredits; }
    int getMaxCredits() const { return maxCredits; }
    int getStartTime() const { return startTime; }
    int getEndTime() const { return endTime; }

private:
    string name;
	int startTime;
	int endTime;
    int maxCredits;
	int minCredits;

    friend class CourseBuilder;
};

class Course::CourseBuilder {
public:
    CourseBuilder& WithName(const string& name);
    CourseBuilder& WithMinCredits(int credits);
    CourseBuilder& WithMaxCredits(int credits);
    CourseBuilder& WithStartTime(int time);
    CourseBuilder& WithEndTime(int time);
    Course build() const;

private:
	Course thisCourse;
};

#endif
