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
	Grille(int longueur, int hauteur, int mines);

	// D�structeur
	~Grille();

	// retourne la Case auxcoordonn�es x, y
	Case getCase(int x, int y);

	// modifie l'etat de la case (1 r�v�l�e, 2 marqu�e)
	void setCase(int x, int y, int etat);

	// r�v�le les cases adjacente
	void reveleCasesAdj(int x, int y);

	// affiche la grille avec les valeurs de chaque case
	void afficherGrille();

	// affecte le nombre nbMines de mines al�toirement � des cases de la grille
	void affecterMines();

	// affecte la valeur de chaque case par rapport au nombres de mines autour
	void affecterValeursCases();

	// retourne vrai si la grille est enti�rement d�couverte
	bool estTerminee();

	// retourne le nombre de mines restantes � d�couvrir
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

	// nombre de mines � d�couvrir
	int m_mines_restantes;

	// vector contenant les cases de la grille
	std::vector<Case> m_grille;
};

#endif
