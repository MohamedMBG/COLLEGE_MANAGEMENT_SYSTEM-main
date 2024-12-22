#include<iostream>
#include<string>
#include<vector>

#include "main.h"

using namespace std;

Notes::Notes(/* args */){
}

Notes::~Notes(){
}

void Notes::addGrade(Etudiant* student, Cours* course, double grade){
    //on va ajouter ces informations a la listes qu'on a deja declare
    Listnotes.push_back({student, course, grade});
}

double Notes::getGrade(Etudiant* student, Cours* course){
    for (int i = 0; i < Listnotes.size(); i++)
    {
        if (Listnotes[i].student == student && Listnotes[i].course == course)
        {
            cout << "l'etudiant: " << student->getNom() << " a eu " << Listnotes[i].grade << " au cours de: " << course->getCoursName() << endl;
            return Listnotes[i].grade;
        }
    }
    cout << "l'etudiant n'a pas de note pour ce cours!" << endl;
    return -1;
}