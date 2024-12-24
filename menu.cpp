#include <iostream>
#include <string>
#include "main.h"

using namespace std;

int main() {
    int choice;
    cout << "Veuillez choisir une option:" << endl;
    cout << "1. Administrateur" << endl;
    cout << "2. Etudiant" << endl;
    cout << "3. Enseignant" << endl;
    cout << "Votre choix: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << endl << "Vous avez choisi le rôle d'administrateur." << endl;
        int choiceAdmin;
        cout << "Veuillez choisir une option:" << endl;
        cout << "1. Ajouter un cours" << endl;
        cout << "2. Ajouter un etudiant" << endl;
        cout << "3. Ajouter un enseignant" << endl;
        cin >> choiceAdmin;

        switch (choiceAdmin) {
        case 1: {
            string coursName, niveauEtude, dep;
            int coursNum;
            Personnel* teacher = new Personnel();

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

            Cours* newCours = new Cours(coursName, coursNum, teacher, niveauEtude);
            cout << "Cours ajoute avec succes!" << endl;
            newCours->afficher();
            break;
        }
        case 2:
            // Code pour ajouter un etudiant
            cout << "Ajouter un etudiant" << endl;
            break;
        case 3:
            // Code pour ajouter un enseignant
            cout << "Ajouter un enseignant" << endl;
            break;
        default:
            cout << "Choix invalide. Veuillez reessayer." << endl;
            break;
        }
        break;
    case 2:
        cout << endl << "Vous avez choisi le rôle d'etudiant." << endl;
        // Add student functionality here
        break;
    case 3:
        cout << endl << "Vous avez choisi le rôle d'enseignant." << endl;
        // Add teacher functionality here
        break;
    default:
        cout << endl << "Choix invalide. Veuillez reessayer." << endl;
        break;
    }
    return 0;
}