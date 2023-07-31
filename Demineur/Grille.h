#pragma once

#ifndef DEF_GRILLE
#define DEF_GRILLE

#include "Case.h"

class Grille
{
public:
	Grille();
	Grille(int longueur, int hauteur);
	~Grille();

	Case getCase(int x, int y);
	void afficherGrille();
	void affecterMines(int nbMines);

private:
	int m_longueur;
	int m_hauteur;
	int m_nbCases;
	std::vector<Case> m_grille;
};

#endif
