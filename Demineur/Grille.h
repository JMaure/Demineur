#pragma once

#ifndef DEF_GRILLE
#define DEF_GRILLE

#include <vector>
#include "Case.h"

class Grille
{
public:
	// Constructeur par défaut
	Grille();

	// Constructeur d'une grille avec une longueur et hauteur donnée de Cases de valeurs 0 
	Grille(int longueur, int hauteur, int mines);

	// Déstructeur
	~Grille();

	// retourne la Case auxcoordonnées x, y
	Case getCase(int x, int y);

	// modifie l'etat de la case (1 révélée, 2 marquée)
	void setCase(int x, int y, int etat);

	// révèle les cases adjacente
	void reveleCasesAdj(int x, int y);

	// affiche la grille avec les valeurs de chaque case
	void afficherGrille();

	// affecte le nombre nbMines de mines alétoirement à des cases de la grille
	void affecterMines();

	// affecte la valeur de chaque case par rapport au nombres de mines autour
	void affecterValeursCases();

	// retourne vrai si la grille est entièrement découverte
	bool estTerminee();

	// retourne le nombre de mines restantes à découvrir
	int getMineRest();

private:
	// longueur de la grille
	int m_longueur;

	// auteur de la grille
	int m_hauteur;

	// nombre de cases de la grille
	int m_nbCases;

	// nombre de mines
	int m_mines;

	// nombre de mines à découvrir
	int m_mines_restantes;

	// vector contenant les cases de la grille
	std::vector<Case> m_grille;
};

#endif
