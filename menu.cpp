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
            cout << endl
                 << "Vous avez choisi le role d'administrateur." << endl;
            cout << "Veuillez choisir une option: " << endl;
            cout << "1. Ajouter un cours" << endl;
            cout << "2. Ajouter un administrateur" << endl;
            cout << "3. Modifier infos etudiant" << endl;
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
                Personnel *teacher = new Personnel();

                cout << "Entrez le nom du cours: ";
                cin.ignore();
                getline(cin, coursName);

                cout << "Entrez le numero du cours: ";
                cin >> coursNum;

                cout << "Entrez le niveau d'etude: ";
                cin.ignore();
                getline(cin, niveauEtude);

                cout << "Entrez le departement: ";
                getline(cin, dep);
                teacher->setDep(dep);

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

            default:
                cout << "Choix invalide. Veuillez reessayer." << endl;
                break;
            }
            break;
        }
        case 2:
        {
            cout << endl
                 << "Vous avez choisi le role d'etudiant." << endl;
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

                // chercher le cours et l'etudiant
                Etudiant *etudiant = nullptr;
                Cours *cours = nullptr;

                for (auto &e : etudiants)
                {
                    if (e.getMatricule() == matricule)
                    {
                        etudiant = &e;
                        break;
                    }
                }

                for (auto &c : courses)
                {
                    if (c.getCoursNum() == coursNum)
                    {
                        cours = &c;
                        break;
                    }
                }

                if (etudiant && cours)
                {
                    inscription.inscrireEtudiant(etudiant, cours);
                    cout << "Etudiant inscrit au cours avec succes!" << endl;
                }
                else
                {
                    cout << "Etudiant ou cours non trouve." << endl;
                }
                break;
            }
            default:
                cout << "Choix invalide. Veuillez reessayer." << endl;
                break;
            }
            break;
        }
        case 3:
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

            default:
                break;
            }

            break;
        default:
            cout << endl << "Choix invalide. Veuillez reessayer." << endl;
            break;
        }
    }
}