#include <iostream>
#include <string>

using namespace std;

/* ------------------------------------- COURS ------------------------------------------------------- */
class Cours
{
private:
    string coursName;
    int coursNum;
    Personnel* teachers;
    string NEtude;
    string dep;

public:
    Cours();
    Cours(string CName, int CNum, Personnel* t, string niveau);
    ~Cours();
    // affichage
    void afficher();
    // attribution d'un enseignant
    bool givingTeacher(Personnel* teachers);
};

/* ------------------------------------- ETUDIANT ------------------------------------------------------- */
class Etudiant
{
private:
    int matricule;
    string nom;
    string prenom;
    string filiere;

public:
    Etudiant(/* args */);
    Etudiant(int m, string n, string pn, string major);
    ~Etudiant();
    void afficher();
    bool rechercher(vector<Etudiant> &etudiants, int matricule);
    // definition des getters
    void setMatricule(int id) { matricule = id; }
    void setNom(string n) { nom = n; }
    void setPrenom(string pn) { prenom = pn; }
    void setMajor(string major) { filiere = major; }
    // definition des setters
    int getMatricule() { return matricule; }
    string getNom() { return nom; }
    string getPrenom() { return prenom; }
    string getMajor() { return filiere; }
};

/* ------------------------------------- NOTE ------------------------------------------------------- */
class Note
{
private:
    double note;
    int courseId;
    int studentid;

public:
    Note();
    Note(int Cours, int Student, double grade);
    ~Note();
    // declaration des setters
    void setNote(double n) { note = n; }
    void setCourseID(int idC) { courseId = idC; }
    void setStudentID(int idS) { studentid = idS; }
    // declaration des getters
    double getGrade() { return note; }
    int getStudentID() { return studentid; }
    int getcourseID() { return courseId; }
};

/* ------------------------------------- PERSONNEL ------------------------------------------------------- */
class Personnel
{
private:
    int num_employe;
    string name;
    char type;
    string departement;

public:
    Personnel();
    Personnel(int id, string nom, char type, string dep);
    ~Personnel();
    void lister();
    void search(vector<Personnel> &persons, int id);
    // declaration des setters
    void setNum(int n) { num_employe = n; }
    void setName(string nom) { name = nom; }
    void setType(char t) { type = t; }
    void setDep(string dep) { departement = dep; }
    // declaratoin des getters
    int getNum() { return num_employe; }
    string getName() { return name; }
    char getType() { return type; }
    string getDep() { return departement; }
};

/* ------------------------------------- INSCRIPTION ------------------------------------------------------- */
class Inscription
{
private:
    Etudiant* student;
    Personnel* teacher;
    Cours* cours;
    bool validation;

public:
    Inscription();
    Inscription(Etudiant* e, Personnel* p, Cours* c, bool v);
    ~Inscription();
    // Methods
    void validerInscription();
    void afficherDetails() const;
};
