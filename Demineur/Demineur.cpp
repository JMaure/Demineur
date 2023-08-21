// Demineur.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Case.h"
#include "Grille.h"

using namespace std;

int main()
{
    cout << "JEU DU DEMINEUR" << endl << endl;
    cout << "Pour jouer il faut donner les coordonnees de la case a decouvrir. (ex : 12)" << endl;
    cout << "Pour marquer l'emplacement d'une mine rajouter 'M' a la suite des coordonnees (ex : 12M)" << endl << endl;

    const int longueur = 5, hauteur = 5, nbMines = 3;

    // Création de la grille de cases
    Grille dem(longueur, hauteur);

    //affecter les mines dans la grille
    dem.affecterMines(nbMines);

    // affecter les autres valeurs
    dem.affecterValeursCases();

    // affichage de la grille
    dem.afficherGrille();

    int x, y;
    string coordonnees = "000";
    bool finPartie = false;
    do
    {
        cout << "Choisir case : ";
        cin >> coordonnees;
        x = coordonnees[0] - '0' - 1;
        y = coordonnees[1] - '0' - 1;
        if (coordonnees[2] == 'M')
            dem.getCase(x, y).estMarquee();
        else
            dem.getCase(x, y).estDecouverte();

        dem.afficherGrille();
        if (dem.getCase(x, y).isDecouverte() && dem.getCase(x, y).getVal() == 9)
        {
            finPartie = true;
            cout << "Partie perdue ! " << endl;
        }
        if (dem.estTerminee())
        {
            finPartie = true;
            cout << "Partie gagnee ! " << endl;
        }
    } while (!finPartie);
}



// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
