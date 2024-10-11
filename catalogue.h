#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "course_container.h"

class Catalogue : public CourseContainer {
public : 
    Catalogue() {
        columns.push_back(CourseColumn::NAME);
        columns.push_back(CourseColumn::CREDITS);
        columns.push_back(CourseColumn::TIME);
    }

private:
    void printAdditionalInfo() const override;
};

#endif