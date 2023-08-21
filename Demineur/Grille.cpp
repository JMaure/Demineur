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
	for (int j = 0; j < hauteur; j++)
	{
		for (int i = 0; i < longueur; i++)
		{
			m_grille.push_back(Case(i, j, 0));
		}
	}
}

// Destructeur
Grille::~Grille()
{
}

// retourne la Case aux coordonnées x,y
Case& Grille::getCase(int x, int y)
{
	return m_grille.at(x + (y * m_longueur));
}

void Grille::afficherGrille()
{
	int cpt = 0;
	cout << "  ";
	for (int i = 0; i < m_longueur; i++)
		cout << "  " << i+1 << " ";
	cout << endl;
	for (int j = 0; j < m_hauteur; j++)
	{
		cout << "  ";
		for (int i = 0; i < m_longueur; i++)
			cout << " ---";
		cout << endl;
		cout << j + 1 << " ";
		for (int i = 0; i < m_longueur; i++)
		{
			if (m_grille.at(i + (j * m_longueur)).isDecouverte())
			{
				if(m_grille.at(i + (j * m_longueur)).getVal() == 9)
					cout << "| X ";
				else
					cout << "| " << m_grille.at(i + (j * m_longueur)).getVal() << " ";
			}
			else if (m_grille.at(i + (j * m_longueur)).isMarquee())
				cout << "| M ";
			else
				cout << "|   ";
			cpt++;
		}
		cout << "|" << endl;
	}
	cout << "  ";
	for (int i = 0; i < m_longueur; i++)
		cout << " ---";
	cout << endl;
}

void Grille::affecterMines(int nbMines)
{
	if (nbMines <= 0)
	{
		for (int i = 0; i < m_nbCases - 1; i++)
		{
			m_grille.at(i).setVal(0);
		}
	}
	else if (nbMines >= m_nbCases)
	{
		for (int i = 0; i < m_nbCases - 1; i++)
		{
			m_grille.at(i).setVal(9);
		}
	}
	else
	{
		vector<int> choixMines;
		vector<int>::iterator it;
		for (int i = 0; i < m_nbCases - 1; i++)
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
}

void Grille::affecterValeursCases()
{
	int cpt = 0;
	int  abs, coor;
	for (int parcourCase = 0; parcourCase < m_nbCases; parcourCase++)
	{
		if (m_grille.at(parcourCase).getVal() != 9)
		{
			abs = m_grille.at(parcourCase).getX();
			coor = m_grille.at(parcourCase).getY();
			for (int j = coor - 1; j <= coor + 1; j++)
			{
				if (j >= 0 && j < m_hauteur)
				{
					for (int i = abs - 1; i <= abs + 1; i++)
					{
						if (i >= 0 && i < m_longueur)
						{
							if (m_grille.at(i + (j * m_longueur)).getVal() == 9)
							{
								cpt++;
							}
						}
					}
				}
			}
			m_grille.at(parcourCase).setVal(cpt);
			cpt = 0;
		}
	}
}

bool Grille::estTerminee()
{
	bool fini = true;
	Case* caseParcourue = new Case;
	int cpt = 0;
	while (cpt < m_grille.size() && fini == true)
	{
		caseParcourue = &m_grille.at(cpt);
		if ((!caseParcourue->isDecouverte() && caseParcourue->getVal() != 9) || (caseParcourue->isMarquee() && caseParcourue->getVal() != 9))
		{
			fini = false;
		}
		cpt++;
	}
	caseParcourue = 0;
	delete caseParcourue;
	return fini;
}