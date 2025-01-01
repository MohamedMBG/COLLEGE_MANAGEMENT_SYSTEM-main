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
    Notes notes;

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
                string name, niveau;
                int num, code;

                cout << "Entrez le nom du cours: ";
                cin.ignore();
                getline(cin, name);
                cout << "Entrez le numero du cours: ";
                cin >> num;
                cout << "Entrez le numero du prof: ";
                cin >> code;
                cout << "Entrez le niveau d'etude: ";
                cin.ignore();
                getline(cin, niveau);

                Cours newCours(name, num, code, niveau, personnels);
                courses.push_back(newCours);
                newCours.afficher();
                break;
            }
            case 2:
            {
                string name, dep;
                int num;

                cout << "Entrez le nom de l'administrateur: ";
                cin.ignore();
                getline(cin, name);
                cout << "Entrez le numero de l'administrateur: ";
                cin >> num;
                cout << "Entrez le departement de l'administrateur: ";
                cin.ignore();
                getline(cin, dep);

                Personnel newAdmin(num, name, 'a', dep);
                cout << "Administrateur ajoute avec succes!" << endl;
                break;
            }
            case 3:
            {
                int c;
                for (size_t i = 0; i < etudiants.size(); i++)
                {
                    etudiants[i].afficher();
                }

                cout << "Entrez le numero de l'etudiant que vous voulez modifier: ";
                cin >> c;

                for (size_t i = 0; i < etudiants.size(); i++)
                {
                    if (etudiants[i].getMatricule() == c)
                    {
                        etudiants[i].modifyStudent();
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                int choiceAbscence;
                cout << "1. Ajouter une absence a un etudiant" << endl;
                cout << "2. Afficher les absences d'un etudiant" << endl;
                cout << "0. Retour au menu principal" << endl;
                cin >> choiceAbscence;

                if (choiceAbscence == 0)
                {
                    break;
                }

                switch (choiceAbscence)
                {
                case 1:
                {
                    int codestd, codeCours;
                    string date;
                    cout << "Entrez le numero de l'etudiant: ";
                    cin >> codestd;
                    cout << "Entrez le numero du cours: ";
                    cin >> codeCours;
                    cout << "Entrez la date de l'absence (format: YYYY-MM-DD): ";
                    cin.ignore();
                    getline(cin, date);

                    abscence.addAbscence(codestd, codeCours, date, etudiants, courses);
                    break;
                }
                case 2:
                {
                    int codestd;
                    cout << "Entrez le numero de l'etudiant: ";
                    cin >> codestd;

                    abscence.displayAbscences(codestd);
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
            int choiceEtudiant;
            cout << endl << "Vous avez choisi le role d'etudiant." << endl;
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
                break;
            }
            default:
                cout << "Choix invalide. Veuillez reessayer." << endl;
                break;
            }
            break;
        }
        case 3:
        {
            int choixEnseignant;
            cout << endl << "Vous avez choisi le role d'enseignant." << endl;
            cout << "1. Ajouter un enseignant" << endl;
            cout << "2. Controler les inscriptions" << endl;
            cout << "3. Ajouter les notes des etudiants" << endl;
            cout << "4. Afficher les notes d'un etudiant" << endl;
            cout << "0. Retour au menu principal" << endl;
            cin >> choixEnseignant;

            if (choixEnseignant == 0)
            {
                break;
            }

            switch (choixEnseignant)
            {
            case 1:
            {
                string nom, dep;
                int num;

                cout << "Entrez le numero de l'enseignant: ";
                cin >> num;
                cout << "Entrez le nom de l'enseignant: ";
                cin.ignore();
                getline(cin, nom);
                cout << "Entrez le departement de l'enseignant: ";
                getline(cin, dep);

                Personnel newEnseignant(num, nom, 'e', dep);
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
                int codeE, codeC;
                double note;
                cout << "Entrez le matricule de l'etudiant: ";
                cin >> codeE;
                cout << "Entrez le numero du cours: ";
                cin >> codeC;
                cout << "Entrez la note de l'etudiant: ";
                cin >> note;

                notes.addGrade(codeE, codeC, note, etudiants, courses);

                break;
            }
            case 4:
            {
                int codeE;
                cout << "Entrez le matricule de l'etudiant: ";
                cin >> codeE;

                notes.fetchGrade(codeE);
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
    }

    return 0;
}
