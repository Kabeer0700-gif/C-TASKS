#include "LectureCourse.h"

LectureCourse::LectureCourse(string code, int cr) : Course(code, cr) {}

double LectureCourse::calculateGrade() {
    return 88.5;
}

void LectureCourse::displayInfo() {
    cout << "Lecture Course: " << courseCode << ", Credits: " << credits << endl;
}
