#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H

#include "Course.h"
#include <iostream>
using namespace std;

class LectureCourse : public Course {
public:
    LectureCourse(string code, int cr);
    double calculateGrade() override;
    void displayInfo() override;
};

#endif
