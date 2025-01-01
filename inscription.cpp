#include "main.h"
#include <iostream>
#include <vector>

using namespace std;

Inscription::Inscription() {}
Inscription::~Inscription()
{
    cout << "Objet d'inscription detruit avec succes !" << endl;
}

void Inscription::inscrireEtudiant(int codeE, int codeC)
{
    Etudiant *student = nullptr;
    Cours *course = nullptr;

    for (auto &etudiant : students)
    {
        if (etudiant->getMatricule() == codeE)
        {
            student = etudiant;
            break;
        }
    }

    for (auto &cours : courses)
    {
        if (cours->getCoursNum() == codeC)
        {
            course = cours;
            break;
        }
    }

    if (student && course)
    {
        course->getStudents().push_back(student);
        cout << "Etudiant inscrit au cours avec succes!" << endl;
    }
    else
    {
        cout << "Etudiant ou cours non trouve!" << endl;
    }
}

void Inscription::declinerInscription(int codeE, int codeC)
{
    Cours *course = nullptr;
    Etudiant *student = nullptr;

    for (auto &cours : courses)
    {
        if (cours->getCoursNum() == codeC)
        {
            course = cours;
            break;
        }
    }

    for (auto &etudiant : students)
    {
        if (etudiant->getMatricule() == codeE)
        {
            student = etudiant;
            break;
        }
    }

    if (student && course)
    {
        for (int i = 0; i < course->getStudents().size(); i++)
        {
            if (course->getStudents()[i]->getMatricule() == codeE)
            {
                course->getStudents().erase(course->getStudents().begin() + i);
                cout << "Etudiant desinscrit du cours avec succes!" << endl;
                return;
            }
        }
    }
}

void Inscription::afficherInscriptions()
{
    cout << "Liste des inscriptions: " << endl;
    for (auto &cours : courses)
    {
        cout << "Cours: " << cours->getCoursName() << endl;
        cout << "Etudiants: " << endl;
        for (auto &etudiant : cours->getStudents())
        {
            cout << etudiant->getNom() << " " << etudiant->getPrenom() << endl;
        }
    }
}