// Demineur.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Case.h"
#include "Grille.h"
#include "Chrono.h"

using namespace std;

int main()
{
    // règles du jeu
    cout << "JEU DU DEMINEUR" << endl << endl;
    cout << "Pour jouer il faut donner les coordonnees de la case a decouvrir. (ex : 12)" << endl;
    cout << "Pour marquer l'emplacement d'une mine rajouter 'M' a la suite des coordonnees (ex : 12M)" << endl << endl;

    //définition des constantes de grille
    const int longueur = 5, hauteur = 5, nbMines = 3;

    const int revelee = 1, marquee = 2;

    // Création de la grille de cases
    Grille dem(longueur, hauteur, nbMines);

    // création du timer
    Chrono timer;

    //affecter les mines dans la grille
    dem.affecterMines();

    // affecter les autres valeurs
    dem.affecterValeursCases();

    // affichage de la grille
    dem.afficherGrille();

    int x, y;
    string coordonnees = "000";
    bool finPartie = false;
    

    do
    {
        cout << endl;
        cout << "Choisir case : ";
        cin >> coordonnees;

        // lancement du timer
        if (!timer.enCours())
            timer.start();

        x = coordonnees[0] - '0' - 1;
        y = coordonnees[1] - '0' - 1;
        if (coordonnees[2] == 'M')
            dem.setCase(x, y, marquee);
        else
            dem.setCase(x, y, revelee);

        system("cls");
        // règles du jeu
        cout << "JEU DU DEMINEUR" << endl << endl;
        cout << "Pour jouer il faut donner les coordonnees de la case a decouvrir. (ex : 12)" << endl;
        cout << "Pour marquer l'emplacement d'une mine rajouter 'M' a la suite des coordonnees (ex : 12M)" << endl << endl;

        dem.afficherGrille();

        Case choixCase = dem.getCase(x, y);
        if (choixCase.isDecouverte() && choixCase.getVal() == 9)
        {
            finPartie = true;
            cout << "Partie perdue ! " << endl;
            timer.stop();
        }
        if (dem.estTerminee())
        {
            finPartie = true;
            cout << "Partie gagnee ! " << endl;
            timer.stop();
        }
    } while (!finPartie);
    cout << "Duree de la partie : ";
    timer.afficher();
    cout << endl;
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
