#include "LectureCourse.h"
#include "LabCourse.h"
#include <iostream>
using namespace std;

int main() {
    Course* c1 = new LectureCourse("CS201", 3);
    Course* c2 = new LabCourse("CS201L", 1);

    c1->displayInfo();
    cout << "Grade: " << c1->calculateGrade() << endl;

    c2->displayInfo();
    cout << "Grade: " << c2->calculateGrade() << endl;

    delete c1;
    delete c2;

    return 0;
}
