#include <iostream>
#include <vector>
#include <random>
#include <time.h>

#include "Grille.h"
#include "Case.h"

using namespace std;

Grille::Grille() : m_longueur(1), m_hauteur(1), m_nbCases(1)
{
	m_grille.push_back(Case());
}

// Constructeur Grille de la grille de taille longueur * largeur avec valeur des cases à 0
Grille::Grille(int longueur, int hauteur) : m_longueur(longueur), m_hauteur(hauteur), m_nbCases(longueur * hauteur)
{
	//m_grille[m_nbCases-1];

	for (int j = 0; j < hauteur; j++)
	{
		for (int i = 0; i < longueur; i++)
		{
			m_grille.push_back(Case(i, j, 0)); // m_grille[i + (j * longueur)] = Case(i, j, 0);
		}
	}
}

// Destructeur
Grille::~Grille()
{
}

// retourne la Case aux coordonnées x,y
Case Grille::getCase(int x, int y)
{
	return m_grille.at(x + (y * m_longueur));  // m_grille[x + y * m_longueur];
}

void Grille::afficherGrille()
{
	for (int j = 0; j < m_hauteur; j++)
	{
		for (int i = 0; i < m_longueur; i++)
			cout << " ---";
		cout << endl;
		for (int i = 0; i < m_longueur; i++)
			cout << "| " << m_grille.at(i + (j * m_longueur)).getVal() << " ";
		cout << "|" << endl;
	}
	for (int i = 0; i < m_longueur; i++)
		cout << " ---";
}

void Grille::affecterMines(int nbMines)
{
	vector<int> choixMines;
	vector<int>::iterator it;
	for (int i = 0; i < m_nbCases-1; i++)
	{
		choixMines.push_back(i);
	}

	srand((unsigned int)time(0));
	for (int i = 0; i < nbMines; i++)
	{
		int valRandom = (int)((float)rand() * choixMines.size() / (RAND_MAX - 1));
		m_grille.at(choixMines[valRandom]).setVal(9);
		it = choixMines.begin() + valRandom;
		choixMines.erase(it);
	}
}