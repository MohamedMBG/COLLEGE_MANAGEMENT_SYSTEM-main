#include<iostream>
#include<string>
#include<vector>

#include "main.h"

using namespace std;

Notes::Notes(/* args */){
}

Notes::~Notes(){
}

void Notes::addGrade(Etudiant* student, Cours* course, double grade) {
    students.push_back(student);
    courses.push_back(course);
    grades.push_back(grade);
}

double Notes::getGrade(Etudiant* student, Cours* course) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i] == student && courses[i] == course) {
            cout << "L'etudiant: " << student->getNom() << " a eu " << grades[i] << " au cours de: " << course->getCoursName() << endl;
            return grades[i];
        }
    }
    cout << "L'etudiant n'a pas de note pour ce cours!" << endl;
    return -1;
}

/* --------------- still i didn't do the displaying part -------------------------- */