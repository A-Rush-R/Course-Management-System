#include<bits/stdc++.h>
using namespace std;

class Course {
	private : 
		int minCredits;
		int maxCredits;
		string timing;
		string name;
	public :
		int getMinCredits() {
			return minCredits;
		}
		int getMaxCredits() {
			return maxCredits;
		}
		string getTiming(){
			return timing;
		}
		string getName(){
			return name;
		}

		void setName(string _name){
			name = _name;
		}
		void setTiming(string _timing){
			timing = _timing;
		}
		void setCredits(int _creds){
			minCredits = _creds;
		}
};

class Catalogue {
	private :
		vector<Course> allcourses;
	public :
		void addCourse(Course c){
			allcourses.push_back(c);
		}

		vector<Course> getAllCourses(){
			return allcourses;
		}
		
		void show(){
			cout << left << setw(10) << "Name"  
				<< setw(10) << "Minimum Credits"
				<< setw(10) << "Maximum Credits"
				<< setw(10) << "Timing"
				<< endl;
			for (Course c : allcourses) {
				cout << left << setw(10) << c.getName()  
					<< setw(10) << c.getMinCredits()
					<< setw(10) << c.getMaxCredits()
					<< setw(10) << c.getTiming()
					<< endl;
			}
		}
};

class CatalogueBuilder {
	private :
		Catalogue currCatalogue;
		Course currCourse;
	public :

		CatalogueBuilder withCredits(int _creds){
			currCourse.setCredits(_creds);
			return *this;
		}

		CatalogueBuilder withTiming(string _timing){
			currCourse.setTiming(_timing);
			return *this;
		}

		CatalogueBuilder withName (string _name){
			currCourse.setName(_name);
			return *this;
		}

		CatalogueBuilder finish() {
			currCatalogue.addCourse(currCourse);
			return *this;
		}

		Catalogue build(){
			return currCatalogue;
		}
};

class Schedule {
	private :
		vector<Course> courses;
	public :
		void addCourse(Course c){
			courses.push_back(c);
		}

		vector<Course> getCourses(){
			return courses;
		}
};

class ScheduleBuilder {
	private :
		Schedule currSchedule;
		Course currCourse;
	public :

};

int main(){

	Catalogue allcourses;
	allcourses = CatalogueBuilder().withCredits(9).withTiming("9 am to 10 am").withName("CS455").finish()
									.withCredits(12).withTiming("10 am to 11 am").withName("CS220").finish()
									.withCredits(9).withTiming("11 am to 12 pm").withName("ESO207").finish()
									.withCredits(9).withTiming("10 am to 11 am").withName("CS450").finish()
							.build();
	
	allcourses.show();

	cout << "Pick Courses" << endl;
	return 0;
}
