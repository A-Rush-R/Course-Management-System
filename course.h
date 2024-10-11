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
    int getCredits() const { return appliedCredits; }
    int getStartTime() const { return startTime; }
    int getEndTime() const { return endTime; }
    Course(string n, int start, int end, int maxC, int minC) 
        : name(n), startTime(start), endTime(end), maxCredits(maxC), minCredits(minC) {
    }
    void setCredits(int _credits) { appliedCredits = _credits; }
    bool clashesWith(const Course& other) const;

private:
    string name;
	int startTime;
	int endTime;
    int maxCredits;
	int minCredits;
    int appliedCredits;

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
    string name = "";
	int startTime = 0;
	int endTime = 0;
    int maxCredits = 0;
	int minCredits = 0;
};

#endif
