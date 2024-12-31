#include <iostream>
#include <string>
#include <vector>
#include <cctype>

#include "main.h"

using namespace std;

Cours::Cours()
{
    coursName = "Intermidiate English";
    coursNum = 001;
    teachers = new Personnel();
    dep = teachers->getDep();
    NEtude = "3IIR";
    students = vector<Etudiant *>();
}

Cours::Cours(string CName, int Cnum, int t, string levelEtude)
{
    if (givingTeacher(t) == true)
    {
        setCName(CName);
        setCNum(Cnum);
        setNiveau(levelEtude);
        students = vector<Etudiant *>();
    }
}


bool Cours::givingTeacher(int p)
{
    bool exists;
    Personnel* t;
    vector<Personnel> teachers;
    for (int i = 0; i < teachers.size(); i++)
    {
        if (teachers[i].getNum() == p && tolower(teachers[i].getType()) == 'e')
        {
            t = &teachers[i];
            setTeacher(t);
            dep = teachers[i].getDep();
            return true;
        }
        
    }
    return false;
}

void Cours::afficher()
{
    cout << "Nom du cours: " << getCoursName() << endl
         << "Numero du cours: " << getCoursNum() << endl
         << "Departement: " << dep << endl
         << "Niveau d'etude: " << getNiveau() << endl;
}


Cours::~Cours()
{
    cout << "l'objet a ete detruit avec succes!";
}