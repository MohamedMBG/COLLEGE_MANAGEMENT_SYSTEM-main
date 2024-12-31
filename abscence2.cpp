#include "main.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Abscence::Abscence() {}

Abscence::~Abscence() {}

void Abscence::addAbscence(int codestd, int codeCours, string date)
{
    Etudiant *student = nullptr;
    Cours *course = nullptr;

    // on doit verifier si l'etudiant et le cours existent
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i]->getMatricule() == codestd)
        {
            student = students[i];
            break;
        }
    }
    

    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i]->getCoursNum() == codeCours)
        {
            course = courses[i];
            break;
        }
    }

    // si l'etudiant et le cours existent on va ajouter l'absence
    if (student != nullptr && course != nullptr)
    {
        students.push_back(student);
        courses.push_back(course);
        dates.push_back(date);
        cout << "abscence ajoutee pour " << student->getNom() << " dans le cours " << course->getCoursName() << " le " << date << endl;
    }else{
        cout << "L'etudiant ou le cours n'existe pas!" << endl;
    }
}

void Abscence::displayAbscences(int studentId)
{
    bool found = false;
    cout << "Les abscences de l'etudiant de matricule: " << studentId << ":" << endl;
    for (size_t i = 0; i < students.size(); ++i)
    {
        if (students[i]->getMatricule() == studentId)
        {
            cout << "Cours: " << courses[i]->getCoursName() << " - Date: " << dates[i] << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "Aucune resultat !" << studentId << endl;
    }
}

void Abscence::displayAbscencesForCourse(int courseId)
{
    bool found = false;
    cout << "les abscences du cours numero:" << courseId << ":" << endl;
    for (size_t i = 0; i < courses.size(); ++i)
    {
        if (courses[i]->getCoursNum() == courseId)
        {
            cout << "L'etudiant: " << students[i]->getNom() << " " << students[i]->getPrenom() << " - Date: " << dates[i] << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "No absences found for course ID " << courseId << endl;
    }
}

void Abscence::SCAbscences(int studentId, int courseId)
{
    bool found = false;
    cout << "Abscences de l'etudiant de matricule: " << studentId << " dans le cours de " << courseId << ":" << endl;
    for (size_t i = 0; i < students.size(); ++i)
    {
        if (students[i]->getMatricule() == studentId && courses[i]->getCoursNum() == courseId)
        {
            cout << "Date: " << dates[i] << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "Aucune abscence de l'etudiant de matricule: " << studentId << "Dans le cours numero: " << courseId << endl;
    }
}