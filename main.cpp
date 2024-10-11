#include<bits/stdc++.h>
#include "course.h"
#include "utils.h"

using namespace std;

// class Catalogue {
	// private :
		// vector<Course> allcourses;
	// public :
		// void addCourse(Course c){
			// allcourses.push_back(c);
		// }
// 
		// vector<Course> getAllCourses(){
			// return allcourses;
		// }
		// 
		// void show(){
			// cout << left << setw(10) << "Name"  
				// << setw(10) << "Minimum Credits"
				// << setw(10) << "Maximum Credits"
				// << setw(10) << "Timing"
				// << endl;
			// for (Course c : allcourses) {
				// cout << left << setw(10) << c.getName()  
					// << setw(10) << c.getMinCredits()
					// << setw(10) << c.getMaxCredits()
					// << setw(10) << c.getTiming()
					// << endl;
			// }
		// }
// };
// 
// class CatalogueBuilder {
	// private :
		// Catalogue currCatalogue;
		// Course currCourse;
	// public :
// 
		// CatalogueBuilder withCredits(int _creds){
			// currCourse.setCredits(_creds);
			// return *this;
		// }
// 
		// CatalogueBuilder withTiming(string _timing){
			// currCourse.setTiming(_timing);
			// return *this;
		// }
// 
		// CatalogueBuilder withName (string _name){
			// currCourse.setName(_name);
			// return *this;
		// }
// 
		// CatalogueBuilder finish() {
			// currCatalogue.addCourse(currCourse);
			// return *this;
		// }
// 
		// Catalogue build(){
			// return currCatalogue;
		// }
// };
// 
// class Schedule {
	// private :
		// vector<Course> courses;
	// public :
		// void addCourse(Course c){
			// courses.push_back(c);
		// }
// 
		// vector<Course> getCourses(){
			// return courses;
		// }
// };
// 
// class ScheduleBuilder {
	// private :
		// Schedule currSchedule;
		// Course currCourse;
	// public :
// 
// };
// 
int main(){
	try {
		Course course = Course::CourseBuilder().WithName("CS101").WithMinCredits(0).WithMaxCredits(11).WithStartTime(8).WithEndTime(9).build();
	}
	catch (const invalid_argument& e){
		cerr << "Course creation failed " << e.what() << endl;
	}
	

	cout << "hey" << endl;
	// cout << course.getName() << ' ' << course.getStartTime() << endl;
	return 0;
}
