#include "main.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;

Abscence::Abscence(){}

Abscence::~Abscence(){}

void Abscence::addAbscence(Etudiant *student, Cours *course, string date) {
    this->student = student;
    this->course = course;
    this->date = date;
}

void Abscence::displayAbscence(int CodeStd) {
    if (student->getMatricule() != CodeStd) {
        cout << "Aucune absence trouvee pour l'etudiant avec le matricule: " << CodeStd << endl;
        return;
    }
    else {
        cout << "L'etudiant: " << student->getNom() << " " << student->getPrenom() << endl
             << "Cours: " << course->getCoursName() << endl
             << "Date: " << date << endl;
    }
}