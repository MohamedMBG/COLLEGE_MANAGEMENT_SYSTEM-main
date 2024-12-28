#include "main.h"
#include <iostream>
#include <vector>

using namespace std;

Inscription::Inscription() {}

Inscription::~Inscription() {
    cout << "Objet d'inscription detruit avec succes !" << endl;
}

void Inscription::inscrireEtudiant(Etudiant* e, Cours* c) {
    bool coursTrouve = false;
    for (size_t i = 0; i < courses.size(); ++i) {
        if (courses[i] == c) {
            studentsInCourses[i].push_back(e);
            coursTrouve = true;
            break;
        }
    }
    if (!coursTrouve) {
        courses.push_back(c);
        studentsInCourses.push_back(vector<Etudiant*>{e});
        validated.push_back(false); 
    }
    cout << "Etudiant inscrit au cours. En attente de validation." << endl;
}

void Inscription::validerInscription(Cours* c) {
    for (size_t i = 0; i < courses.size(); ++i) {
        if (courses[i] == c) {
            validated[i] = true;
            cout << "Inscription validee pour le cours : " << c->getCoursName() << endl;
            return;
        }
    }
    cout << "Cours non trouve." << endl;
}

void Inscription::declinerInscription(Cours* c) {
    for (size_t i = 0; i < courses.size(); ++i) {
        if (courses[i] == c) {
            validated[i] = false;
            cout << "Inscription declinee pour le cours : " << c->getCoursName() << endl;
            return;
        }
    }
    cout << "Cours non trouve." << endl;
}

void Inscription::afficherInscriptions() const {
    for (size_t i = 0; i < courses.size(); ++i) {
        cout << "Cours : " << endl;
        courses[i]->afficher();
        cout << "Statut de validation : " << (validated[i] ? "Valide" : "Non valide") << endl;
        cout << "etudiants : " << endl;
        for (size_t j = 0; j < studentsInCourses[i].size(); ++j) {
            studentsInCourses[i][j]->afficher();
        }
    }
}