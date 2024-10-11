#ifndef TERMINAL_H
#define TERMINAL_H

#include "schedule.h"
#include "catalogue.h"
using namespace std;

enum class UserType {
    STUDENT,
    ADMIN
};

enum class MenuOption {
    EXIT = -1,
    ADD_COURSE = 1,
    REMOVE_COURSE,
    LIST_COURSES,
    SWITCH_USER,
    VIEW_SCHEDULE,
    INVALID
};

class Terminal {
public:
    Terminal();
    void run();

private:
    Schedule studentSchedule;
    Catalogue courseCatalogue;
    UserType currentUser;

    void displayMenu() ;
    MenuOption getMenuChoice() ;
    void processMenuChoice(MenuOption choice);
    void addCourse();
    void removeCourse();
    void listCourses() ;
    void viewSchedule() ;
    void switchUser();
    int getIntInput( string prompt) ;
    string getStringInput( string prompt) ;
};

#endif