#pragma once

#ifndef DEF_GRILLE
#define DEF_GRILLE

#include <vector>
#include "Case.h"

class Grille
{
public:
	// Constructeur par d�faut
	Grille();
	// Constructeur d'une grille avec une longueur et hauteur donn�e de Cases de valeurs 0 
	Grille(int longueur, int hauteur);
	// D�structeur
	~Grille();

	// retourne la Case auxcoordonn�es x, y
	Case &getCase(int x, int y);
	// affiche la grille avec les valeurs de chaque case
	void afficherGrille();
	// affecte le nombre nbMines de mines al�toirement � des cases de la grille
	void affecterMines(int nbMines);
	// affecte la valeur de chaque case par rapport au nombres de mines autour
	void affecterValeursCases();

private:
	// longueur de la grille
	int m_longueur;
	// auteur de la grille
	int m_hauteur;
	// nombre de cases de la grille
	int m_nbCases;
	// vector contenant les cases de la grille
	std::vector<Case> m_grille;
};

#endif
