#include "etudiant.cpp"
#include "cours.cpp"

#include<iostream>
#include<vector>
#include<string>

using namespace std;

Abscence::Abscence(){}

Abscence::~Abscence(){}

void Abscence::addAbscence(Etudiant *student, Cours *course, string date){
    abscent abs;
    abs.student = student;
    abs.course = course;
    abs.date = date;
    ListAbscence.push_back(abs);
}

void Abscence::displayAbscence(int CodeStd) {
    bool found = false;
    for (int i = 0; i < ListAbscence.size(); i++) {
        if (ListAbscence[i].student->getMatricule() == CodeStd) {
            if (!found) {
                // on a ajouter ce ligne de code pour eviter la repition du nom d'etudiant à l'affichage
                cout << "L'étudiant: " << ListAbscence[i].student->getNom() << " " << ListAbscence[i].student->getPrenom() << endl;
                found = true;
            }
            cout << "Cours: " << ListAbscence[i].course->getCoursName() << endl;
            cout << "Date: " << ListAbscence[i].date << endl;
        }
    }
    if (found == false) {
        cout << "Aucune absence trouvée pour l'étudiant avec le matricule: " << CodeStd << endl;
    }
}
