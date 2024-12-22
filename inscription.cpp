#include<iostream>
#include<string>
#include<vector>

#include "main.h"

using namespace std;

Inscription::Inscription(){
    student = new Etudiant();
    teacher = new Personnel();
    cours = new Cours();
    validation = true;
}

Inscription::Inscription(Etudiant* e, Personnel* p, Cours* c, bool v)
{
    student = e;
    teacher = p;
    cours = c;
    validation = v;
}

Inscription::~Inscription()
{
    cout << "l'objet d'inscription a ete detruit avec success !";
}

