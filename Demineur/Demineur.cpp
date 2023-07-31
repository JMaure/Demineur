// Demineur.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#include "Case.h"
#include "Grille.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";

    const int longueur = 3, hauteur = 3, nbMines = 2;

    // Création de la grille de cases
    Grille dem(longueur, hauteur);

    //affecter les mines dans la grille
    dem.affecterMines(nbMines);

    // affichage de la grille
    dem.afficherGrille();
    /*for (i = 0; i < tailleGrille; i++)
        cout << "La case[" << grille[i].getX() << "][" << grille[i].getY() << "] : " << grille[i].getVal() << endl;

    cout << " --- --- --- " << endl;
    cout << "| 0 | 0 | 0 |" << endl;
    cout << " --- --- --- " << endl;
    cout << "| 0 | 0 | 0 |" << endl;
    cout << " --- --- --- " << endl;
    cout << "| 0 | 0 | 0 |" << endl;
    cout << " --- --- --- " << endl;*/
    return 0;
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