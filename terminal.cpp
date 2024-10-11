#include "terminal.h"
#include "utils.h"
#include <iostream>
#include <limits>
using namespace std;

Terminal::Terminal() : currentUser(UserType::STUDENT) {}

void Terminal::run() {
    printDelimter();
    cout << "Welcome to the Course Registration System" << endl;
    cout << "Enter -1 at any time to exit" << endl;
    printDelimter();
    while (true) {
        displayMenu();
        MenuOption choice = getMenuChoice();
        printDelimter();
        if (choice == MenuOption::EXIT) {
            cout << "Exiting..." << endl;
            break;
        }
        processMenuChoice(choice);
        printDelimter();
    }
}

void Terminal::displayMenu()  {
    cout << "\n--- " << (currentUser == UserType::STUDENT ? "Student" : "Admin") << " Menu ---" << endl;
    cout << "1. Add Course" << endl;
    cout << "2. Remove Course" << endl;
    cout << "3. List Courses" << endl;
    cout << "4. Switch User" << endl;
    if ( currentUser == UserType::STUDENT) {
        cout << "5. View Schedule" << endl;
    }
    cout << "Enter your choice: ";
}

MenuOption Terminal::getMenuChoice()  {
    int choice = getIntInput("");
    if (choice == -1) return MenuOption::EXIT;
    if (choice >= 1 && choice <= 5) return static_cast<MenuOption>(choice);
    return MenuOption::INVALID;
}

void Terminal::processMenuChoice(MenuOption choice) {
    switch (choice) {
        case MenuOption::ADD_COURSE:
            addCourse();
            break;
        case MenuOption::REMOVE_COURSE:
            removeCourse();
            break;
        case MenuOption::LIST_COURSES:
            listCourses();
            break;
        case MenuOption::SWITCH_USER:
            switchUser();
            break;
        case MenuOption::VIEW_SCHEDULE:
            if (currentUser != UserType::STUDENT) {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
            viewSchedule();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

void Terminal::addCourse() {
    if (currentUser == UserType::STUDENT) {
        string courseName = getStringInput("Enter course name to add: ");
        if (courseName == "-1") return;
        Course* course = courseCatalogue.findCourse(courseName);
        if (course) {
            int credits = getIntInput("Enter credits: ");
            if (credits == -1) return;
            course->setCredits(credits);

            studentSchedule.addCourse(*course);
        } else {
            cout << "Course not found in catalogue" << endl;
        }
    } else {
        string name = getStringInput("Enter course name: ");
        if (name == "-1") return;
        int startTime = getIntInput("Enter start time: ");
        if (startTime == -1) return;
        int endTime = getIntInput("Enter end time: ");
        if (endTime == -1) return;
        int minCredits = getIntInput("Enter minimum credits: ");
        if (minCredits == -1) return;
        int maxCredits = getIntInput("Enter maximum credits: ");
        if (maxCredits == -1) return;

        try {
            Course course = Course::CourseBuilder()
                                .WithName(name)
                                .WithStartTime(startTime)
                                .WithEndTime(endTime)
                                .WithMinCredits(minCredits)
                                .WithMaxCredits(maxCredits)
                                .build();
            courseCatalogue.addCourse(course);
        } catch ( invalid_argument& e) {
            cerr << "Error creating course: " << e.what() << endl;
        }
    }
}

void Terminal::removeCourse() {
    string courseName = getStringInput("Enter course name to remove: ");
    if (courseName == "-1") return;
    if (currentUser == UserType::STUDENT) {
        studentSchedule.removeCourse(courseName);
    } else {
        courseCatalogue.removeCourse(courseName);
    }
}

void Terminal::listCourses()  {
    courseCatalogue.listCourses();
}

void Terminal::viewSchedule()  {
    studentSchedule.listCourses();
}

void Terminal::switchUser() {
    currentUser = (currentUser == UserType::STUDENT) ? UserType::ADMIN : UserType::STUDENT;
    cout << "Switched to " << (currentUser == UserType::STUDENT ? "Student" : "Admin") << " mode." << endl;
}

int Terminal::getIntInput( string prompt)  {
    while (true) {
        cout << prompt;
        int input;
        if (cin >> input) {
            // Clear the rest of the line
            cin.ignore(10000, '\n');
            return input;
        } else {
            cout << "Invalid input. Please enter a number" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

string Terminal::getStringInput( string prompt)  {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}