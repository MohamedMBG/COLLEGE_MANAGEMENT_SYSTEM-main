#include<iostream>
#include<string>
#include<vector>

#include "main.h"

using namespace std;

Etudiant::Etudiant(){
    setMatricule(01);
    setNom("xxxx");
    setPrenom("yyyy");
    setMajor("HHHH");
    setMajorB("SVT");
    setNoteb(15.7);
}

Etudiant::Etudiant(int m, string n, string pn, string major, string majorB, double noteB){
    setMatricule(m);
    setNom(n);
    setPrenom(pn);
    setMajor(major);
    setMajorB(majorB);
    setNoteb(noteB);
}

void Etudiant::afficher(){
    cout << "l'etudiant de matricule: " << matricule <<
    " sont nom complet est : " << nom << prenom <<
    " sa filiere est: " << filiere <<
    " son bac est: " << fBac << 
    " avec une note de: " << noteBac << endl;
}

bool Etudiant::rechercher(vector<Etudiant>& students,int id){

    for (size_t i = 0; i < students.size(); i++)
    {
        if (id == students[i].getMatricule())
        {
            return true;
        }
    }
    return false;
}