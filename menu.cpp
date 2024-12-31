#include <iostream>
#include <string>
#include <vector>
#include "main.h"

using namespace std;

int main()
{
    vector<Etudiant> etudiants;
    vector<Cours> courses;
    Inscription inscription;
    vector<Personnel> personnels;
    Abscence abscence;

    while (true)
    {
        int choice;
        cout << "Veuillez choisir une option:" << endl;
        cout << "1. Administrateur" << endl;
        cout << "2. Etudiant" << endl;
        cout << "3. Enseignant" << endl;
        cout << "4. Quitter" << endl;
        cout << "Votre choix: ";
        cin >> choice;

        if (choice == 4)
        {
            break;
        }

        switch (choice)
        {

            case 1:
            {
                int choiceAdmin;
                cout << endl << "Vous avez choisi le role d'administrateur." << endl;
                cout << "Veuillez choisir une option: " << endl;
                cout << "1. Ajouter un cours" << endl;
                cout << "2. Ajouter un administrateur" << endl;
                cout << "3. Modifier infos etudiant" << endl;
                cout << "4. Controller les abscences" << endl;
                cout << "0. Retour au menu principal" << endl;
                cin >> choiceAdmin;

                if (choiceAdmin == 0)
                {
                    break;
                }

                switch (choiceAdmin)
                {              
                    case 1:
                    {
                        string coursName, niveauEtude, dep;
                        int coursNum;

                        cout << "Entrez le nom du cours: ";
                        cin.ignore();
                        getline(cin, coursName);

                        cout << "Entrez le numero du cours: ";
                        cin >> coursNum;

                        cout << "Entrez le niveau d'etude: ";
                        cin.ignore();
                        getline(cin, niveauEtude);

                        // dans cette partie on va essayer de trouver l'enseignant qu'on va attribuer a un cours , si il n'existe pas on va le creer
                        int NumoeroE;
                        cout << endl << "Entrez le numero de l'enseignant: ";
                        cin >> NumoeroE;

                        // la partie qu'on va parcourir le vecteur des personnels pour trouver l'enseignant
                        Personnel *teacher = nullptr;
                        for (auto &p : personnels)
                        {
                            if (p.getNum() == NumoeroE && p.getType() == 'e')
                            {
                                teacher = &p;
                                break;
                            }
                        }

                        // si le pointeur "teahcer" est null on va creer un enseignant
                        if (!teacher)
                        {
                            cout << "Enseignant non trouve. Veuillez entrer les informations de l'enseignant: " << endl;
                            int numEnseignant;
                            string name, dep;
                            char typeEnseignant = 'e';

                            cout << endl
                                << "Entrez le numero de l'enseignant: ";
                            cin >> numEnseignant;
                            cout << endl
                                << "Entrez le nom de l'enseignant: ";
                            cin.ignore();
                            getline(cin, name);
                            cout << "Entrez le departement de l'enseignant: ";
                            cin.ignore();
                            getline(cin, dep);

                            Personnel newEnseignant(numEnseignant, name, typeEnseignant, dep);
                            personnels.push_back(newEnseignant);
                            teacher = &newEnseignant;
                        }

                        // on va mettre le deparetement du cours le meme que le professeur
                        dep = teacher->getDep();

                        Cours newCours(coursName, coursNum, teacher, niveauEtude);
                        courses.push_back(newCours);
                        cout << "Cours ajoute avec succes!" << endl;
                        newCours.afficher();
                        break;
                    }
                    case 2:
                    {
                        cout << "Ajouter un administrateur: " << endl;

                        string name, dep;
                        int num;
                        char type = 'a';

                        cout << "Entrez le nom de l'administrateur: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Entrez le numero de l'administrateur: ";
                        cin >> num;
                        cout << "Entrez le departement de l'administrateur: ";
                        cin.ignore();
                        getline(cin, dep);
                        Personnel newAdmin(num, name, type, dep);
                        cout << "Administrateur ajoute avec succes!" << endl;
                        break;
                    }
                    case 3:
                    {
                        int c;
                        for (int i = 0; i < etudiants.size(); i++)
                        {
                            etudiants[i].afficher();
                        }

                        cout << endl
                            << "veuillez entrer le numero de l'etudiant que vous voulez mofifier : ";
                        cin >> c;

                        for (int i = 0; i < etudiants.size(); i++)
                        {
                            if (etudiants[i].getMatricule() == c)
                            {
                                etudiants[i].modifyStudent();
                                break;
                            }
                        }
                    }
                    case 4:
                    {
                        int choiceAbscence;
                        cout << "Veuillez choisir une option: " << endl;
                        cout << "1. Ajouter une abscence a un etudiant" << endl;
                        cout << "2. Afficher les abscences d'un cours" << endl;
                        cout << "3. Afficher les abscences d'un etudiant" << endl;
                        cout << "4. Afficher les abscences d'un etudiant dans un cours" << endl;
                        cout << "0. Retour au menu principal" << endl;
                        cin >> choiceAbscence;

                        if (choiceAbscence == 0) {
                            break;
                        }

                        switch (choiceAbscence) {
                        case 1: {
                            int codestd, codeCours;
                            string date;
                            cout << "Entrez le numero de l'etudiant: ";
                            cin >> codestd;
                            cout << "Entrez le numero du cours: ";
                            cin >> codeCours;
                            cout << "Entrez la date de l'absence (format: YYYY-MM-DD): ";
                            cin.ignore();
                            getline(cin, date);

                            abscence.addAbscence(codestd, codeCours, date);
                            break;
                        }
                        case 2: {
                            int codeCours;
                            cout << "Entrez le numero du cours: ";
                            cin >> codeCours;

                            abscence.displayAbscencesForCourse(codeCours);
                            break;
                        }
                        case 3: {
                            int codestd;
                            cout << "Entrez le numero de l'etudiant: ";
                            cin >> codestd;

                            abscence.displayAbscences(codestd);
                            break;
                        }
                        case 4: {
                            int codestd, codeCours;
                            cout << "Entrez le numero de l'etudiant: ";
                            cin >> codestd;
                            cout << "Entrez le numero du cours: ";
                            cin >> codeCours;

                            abscence.SCAbscences(codestd, codeCours);
                            break;
                }
                default:
                    cout << "Choix invalide. Veuillez reessayer." << endl;
                    break;
                }
                break;
                    }

                    default:
                        cout << "Choix invalide. Veuillez reessayer." << endl;
                        break;
                }
                break;
            }
            case 2:
            {

                cout << endl << "Vous avez choisi le role d'etudiant." << endl;
                int choiceEtudiant;
                cout << "1. Ajouter un etudiant" << endl;
                cout << "2. S'inscrire a un cours" << endl;
                cout << "0. Retour au menu principal" << endl;
                cin >> choiceEtudiant;

                if (choiceEtudiant == 0)
                {
                    break;
                }

                switch (choiceEtudiant)
                {
                    case 1:
                    {
                        string nom, prenom, major, majorB;
                        double noteBac;
                        int matricule;

                        cout << "Entrez le matricule de l'etudiant: ";
                        cin >> matricule;
                        cin.ignore();

                        cout << "Entrez le nom de l'etudiant: ";
                        getline(cin, nom);

                        cout << "Entrez le prenom de l'etudiant: ";
                        getline(cin, prenom);

                        cout << "Entrez la filiere de l'etudiant: ";
                        getline(cin, major);

                        cout << "Entrez la branche du bac de l'etudiant: ";
                        getline(cin, majorB);

                        cout << "Entrez la note du bac de l'etudiant: ";
                        cin >> noteBac;

                        Etudiant newEtudiant(matricule, nom, prenom, major, majorB, noteBac);
                        etudiants.push_back(newEtudiant);
                        cout << "Etudiant ajoute avec succes!" << endl;
                        break;
                    }
                    case 2:
                    {

                        // affichage des cours disponibles
                        cout << "Liste des cours disponibles:" << endl;
                        for (size_t i = 0; i < courses.size(); ++i)
                        {
                            courses[i].afficher();
                        }

                        int matricule;
                        int coursNum;
                        cout << "Entrez le matricule de l'etudiant: ";
                        cin >> matricule;
                        cout << "Entrez le numero du cours: ";
                        cin >> coursNum;

                        inscription.inscrireEtudiant(matricule, coursNum);
                        cout << "Etudiant inscrit au cours avec succes!" << endl;
                    }
                    break;
                }
                default:
                    cout << "Choix invalide. Veuillez reessayer." << endl;
                    break;
            }
            case 3:
            {
                cout << endl << "Vous avez choisi le role d'enseignant." << endl;
                int choixEseignant;
                cout << "1. Ajouter un enseignant: " << endl;
                cout << "2. controller les inscriptions: " << endl;
                cout << "3. Ajouter les notes des etudiants: " << endl;
                cout << "0. Retour au menu principal" << endl;
                cin >> choixEseignant;

                if (choixEseignant == 0)
                {
                    break;
                }
                switch (choixEseignant)
                {
                    case 1:
                    {
                        string nom, dep;
                        int num;
                        char type = 'e';

                        cout << "Entrez le numero de l'enseignant: ";
                        cin >> num;
                        cout << "Entrez le nom de l'enseignant: ";
                        cin.ignore();
                        getline(cin, nom);
                        cout << "Entrez le departement de l'enseignant: ";
                        cin.ignore();
                        getline(cin, dep);

                        Personnel newEnseignant(num, nom, type, dep);
                        personnels.push_back(newEnseignant);
                        cout << "Enseignant ajoute avec succes!" << endl;

                        break;
                    }

                    case 2:
                    {
                        inscription.afficherInscriptions();
                        int supprimer;
                        cout << "Voulez-vous supprimer une inscription? (1: oui, 0: non): ";
                        cin >> supprimer;
                        if (supprimer == 1)
                        {
                            int codeE, codeC;
                            cout << "Entrez le matricule de l'etudiant: ";
                            cin >> codeE;
                            cout << "Entrez le numero du cours: ";
                            cin >> codeC;
                            inscription.declinerInscription(codeE, codeC);
                        }
                        break;
                    }

                    case 3:
                    {
                        
                    }

                    default:
                        break;
                }
            }
        }
    }
}