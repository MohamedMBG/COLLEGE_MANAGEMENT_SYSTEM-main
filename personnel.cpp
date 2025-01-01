#include<iostream>
#include<string>
#include<vector>

#include "main.h"

using namespace std;

Personnel::Personnel(){
    setNum(000);
    setName("prof 0X");
    setType('e');
    setDep("XXXXX");
}

Personnel::Personnel(int id, string nom, char type, string dep){
    setNum(id);
    setName(nom);
    setType(type);
    setDep(dep);
}

Personnel::~Personnel(){
    cout << "l'objet a ete detruit avec succes!";
}

void Personnel::modifyPersonnel(){
    cout << "Modifier les information du personnel " << endl;

    cout << "Entrez le nouveau nom du personnel: ";
    cin.ignore();
    getline(cin, name);

    cout << "Entrez le nouveau departement du personnel: ";
    getline(cin, departement);

    cout << "Informations du personnel modifiees avec succes!" << endl;
}

void Personnel::search(vector<Personnel>& persons, int id){
    bool exists = false;
    int position = -1;
    for (int i = 0; i < persons.size(); i++)
    {
        if (persons[i].num_employe == id)
        {
            exists = true;
            position = i;
            break;
        }
    }
    
    if (exists == true)
        cout << "le personnel exists sa position est : "<<position<<endl;
    else
        cout << "le personel n'existe pas!"<<endl;
    
}

void Personnel::lister(){
    cout <<endl << "le personnel est un " << type 
    <<" son numero d'employe est: "<<num_employe
    <<" son nom est: "<<name
    <<"est son departement: " <<departement<<endl;
}