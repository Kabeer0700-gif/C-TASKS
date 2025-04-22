#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "Course.h"
#include <iostream>
using namespace std;

class LabCourse : public Course {
public:
    LabCourse(string code, int cr);
    double calculateGrade() override;
    void displayInfo() override;
};

#endif
