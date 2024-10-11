#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "course_container.h"

class Catalogue : public CourseContainer {
private:
    void printAdditionalInfo() const override;
};

#endif