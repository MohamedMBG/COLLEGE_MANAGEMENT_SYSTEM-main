#include <iostream>
#include <string>

using namespace std;

/* ------------------------------------- COURS ------------------------------------------------------- */
class Cours
{
private:
    string coursName;
    int coursNum;
    Personnel *teachers;
    string NEtude;
    string dep;

public:
    Cours();
    Cours(string CName, int CNum, Personnel *t, string niveau);
    ~Cours();
    // getters and setters
    void setCName(string name) { coursName = name; }
    void setCNum(int num) { coursNum = num; }
    void setTeacher(Personnel *t) { teachers = t; }
    void setNiveau(string niveau) { NEtude = niveau; }
    string getCoursName() { return coursName; }
    int getCoursNum() { return coursNum; }
    Personnel *getTeacher() { return teachers; }
    string getNiveau() { return NEtude; }
    // affichage
    void afficher();
    // attribution d'un enseignant
    bool givingTeacher(Personnel *teachers);
};

/* ------------------------------------- ETUDIANT ------------------------------------------------------- */
class Etudiant
{
private:
    int matricule;
    string nom;
    string prenom;
    string filiere;
    string fBac;
    double noteBac;

public:
    Etudiant(/* args */);
    Etudiant(int m, string n, string pn, string major , string bacM , double noteB);
    ~Etudiant();
    void afficher();
    bool rechercher(vector<Etudiant> &etudiants, int matricule);
    // definition des getters
    void setMatricule(int id) { matricule = id; }
    void setNom(string n) { nom = n; }
    void setPrenom(string pn) { prenom = pn; }
    void setMajor(string major) { filiere = major; }
    void setMajorB(string bac) { fBac = bac; }
    void setMajor(double noteB) { noteBac = noteB; }
    // definition des setters
    int getMatricule() { return matricule; }
    string getNom() { return nom; }
    string getPrenom() { return prenom; }
    string getMajor() { return filiere; }
    string getBacM() { return fBac; }
    double getNoteBac() { return noteBac; }
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
/* ------------------------------------- INSCRIPTIONS ------------------------------------------------------- */

class Inscription
{
private:
    vector<Cours *> courses;
    vector<vector<Etudiant *>> studentsInCourses;
    vector<bool> validated;

public:
    Inscription();
    ~Inscription();
    // Methods
    void inscrireEtudiant(Etudiant *e, Cours *c);
    void validerInscription(Cours *c);
    void declinerInscription(Cours *c);
    void afficherInscriptions() const;
};

/* ------------------------------------- NOTES ------------------------------------------------------- */

class Notes
{
private:
    struct grade
    {
        Etudiant *student;
        Cours *course;
        double grade;
    };

    vector<grade> Listnotes;

public:
    Notes(/* args */);
    ~Notes();
    void addGrade(Etudiant *student, Cours *course, double grade);
    double getGrade(Etudiant *student, Cours *course);
    void StudentNotes(Etudiant *student);
};

/* ------------------------------------- ABSCENCES ------------------------------------------------------- */

class Abscence
{
    struct abscent
    {
        Etudiant *student;
        Cours *course;
        string date;
    };

private:
    vector<abscent> ListAbscence;

public:
    Abscence(/* args */);
    ~Abscence();
    void addAbscence(Etudiant *student, Cours *course, string date);
    void displayAbscence(int CodeStd);
};