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

Cours::Cours(string CName, int Cnum, Personnel *t, string levelEtude)
{
    if (givingTeacher(t) == true)
    {
        setCName(CName);
        setCNum(Cnum);
        setNiveau(levelEtude);
        students = vector<Etudiant *>();
    }
}

Cours::~Cours()
{
    cout << "l'objet a ete detruit avec succes!";
}

bool Cours::givingTeacher(Personnel *p)
{
    bool exists;
    vector<Personnel> teachers;
    for (int i = 0; i < teachers.size(); i++)
    {
        if (p->getNum() == teachers[i].getNum() && tolower(p->getType()) == 'e')
        {
            setTeacher(&teachers[i]);
            dep = teachers[i].getDep();
            return true;
        }
    }
    return false;
}

void Cours::afficher()
{
    cout << "Nom du cours: " << coursName << endl
         << "Numero du cours: " << coursNum << endl
         << "Departement: " << dep << endl
         << "Niveau d'etude: " << NEtude << endl;
}