#include<iostream>
#include<string>
#include<vector>

#include "main.h"

using namespace std;

Notes::Notes(){
}

Notes::~Notes(){
}

void Notes::addGrade(int codee , int codec , double grade , vector<Etudiant> students, vector<Cours> courses) {
    Etudiant* student = nullptr;
    Cours* course = nullptr;
    int j = -2;
    int mm = -2;

    // on doit verifier si l'etudiant et le cours existent
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getMatricule() == codee)
        {
            j = i;
            break;
        }
    }
    

    for (int i = 0; i < courses.size(); i++)
    {
        if (courses[i].getCoursNum() == codec)
        {
            mm = i;
            break;
        }
    }
    if(j != -2 && mm != -2){
        eleveIng.push_back(students[j]);
        Modules.push_back(courses[mm]);
        grades.push_back(grade);
        cout << "Note ajoutee pour " << students[j].getNom() << " dans le cours " << courses[mm].getCoursName() << " : " << grade << endl;
    }else {
        cout << "Etudiant ou cours inexistant" << endl;
    }
}

double Notes::fetchGrade(int ce) {
    for (int i = 0; i < eleveIng.size(); i++)
    {
        if (eleveIng[i].getMatricule() == ce)
        {
            cout << "La note de l'etudiant " << eleveIng[i].getNom() << " est: " << grades[i] << "dan le cours " << Modules[i].getCoursName() << endl;
        }
    }
    return -1;
}