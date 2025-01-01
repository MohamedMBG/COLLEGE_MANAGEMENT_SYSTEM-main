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

Cours::Cours(string CName, int Cnum, int t, string levelEtude, vector<Personnel> teachers)
{
    bool exists;
    Personnel *p;
    for (int i = 0; i < teachers.size(); i++)
    {
        if (teachers[i].getNum() == t)
        {
            p = &teachers[i];
            setTeacher(p);
            setDep(teachers[i].getDep());
            exists = true;
            break;
        }
    }

        setCName(CName);
        setCNum(Cnum);
        setNiveau(levelEtude);
        students = vector<Etudiant *>();
    
}

void Cours::afficher()
{
            cout << "Le cours de " << getCoursName() << " est donne par " << getTeacher()->getName() << " dans le departement de " << getDep() << " pour les etudiants de " << getNiveau() << endl;

}

Cours::~Cours()
{
    cout << "l'objet a ete detruit avec succes!";
}