#include "main.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Abscence::Abscence() {}

Abscence::~Abscence() {}

void Abscence::addAbscence(int codestd, int codeCours, string date , vector<Etudiant> students , vector<Cours> courses)
{
    Etudiant *student = nullptr;
    Cours *course = nullptr;
    int j = -2;
    int mm = -2;

    // on doit verifier si l'etudiant et le cours existent
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getMatricule() == codestd)
        {
            j = i;
            break;
        }
    }
    

    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i].getCoursNum() == codeCours)
        {
            mm = i;
            break;
        }
    }
    if(j != -2 && mm != -2){
        talamid.push_back(students[j]);
        doross.push_back(courses[mm]);
        dates.push_back(date);
        cout << "abscence ajoutee pour " << students[j].getNom() << " dans le cours " << courses[mm].getCoursName() << " le " << date << endl;
    }else {
        cout << "Etudiant ou cours inexistant" << endl;
    }
}

void Abscence::displayAbscences(int studentId)
{
    bool found = false;
    cout << "Les abscences de l'etudiant de matricule: " << studentId << ":" << endl;
    for (int i = 0; i < talamid.size(); ++i)
    {
        if (talamid[i].getMatricule() == studentId)
        {
                    cout << "L'etudiant: " << talamid[i].getNom() << " " << talamid[i].getPrenom() << " - Cours: " << doross[i].getCoursName() << " - Date: " << dates[i] << endl;
                    found = true;
                     
        }
    }
    if (!found)
    {
        cout << "Aucune resultat !" << studentId << endl;
    }
}