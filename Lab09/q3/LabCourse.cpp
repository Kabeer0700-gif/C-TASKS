#include "LabCourse.h"

LabCourse::LabCourse(string code, int cr) : Course(code, cr) {}

double LabCourse::calculateGrade() {
    return 92.0;
}

void LabCourse::displayInfo() {
    cout << "Lab Course: " << courseCode << ", Credits: " << credits << endl;
}
