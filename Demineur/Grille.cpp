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
Grille::Grille(int longueur, int hauteur, int mines) : m_longueur(longueur), m_hauteur(hauteur), m_nbCases(longueur * hauteur), m_mines(mines)
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
Case Grille::getCase(int x, int y)
{
	return m_grille.at(x + (y * m_longueur));
}

// modifie l'etat de la case (1 révélée, 2 marquée)
void Grille::setCase(int x, int y, int etat)
{
	if (etat == 1)
	{
		m_grille.at(x + (y * m_longueur)).decouverte();
		// si la case vaut 0 alors on révèle les cartes autour
		if (m_grille.at(x + (y * m_longueur)).getVal() == 0)
			reveleCasesAdj(x, y);
	}
	else if (etat == 2)
	{
		m_grille.at(x + (y * m_longueur)).marquee();
	}
}

// révèle les cases adjacente
void Grille::reveleCasesAdj(int x, int y)
{
	for (int j = y - 1; j <= y + 1; j++)
	{
		if (j >= 0 && j < m_hauteur)
		{
			for (int i = x - 1; i <= x + 1; i++)
			{
				if (i >= 0 && i < m_longueur)
				{
					if (!m_grille.at(i + (j * m_longueur)).isDecouverte())
					{
						m_grille.at(i + (j * m_longueur)).decouverte();
						// si les cases autour valent aussi 0 alors on révèle de nouveau les cases autour de celle ci
						if (m_grille.at(i + (j * m_longueur)).getVal() == 0)
							reveleCasesAdj(i, j);
					}
						
				}
			}
		}
	}
}

// affiche la grille avec les valeurs de chaque case
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

// affecte le nombre nbMines de mines alétoirement à des cases de la grille
void Grille::affecterMines()
{
	if (m_mines <= 0)
	{
		for (int i = 0; i < m_nbCases - 1; i++)
		{
			m_grille.at(i).setVal(0);
		}
	}
	else if (m_mines >= m_nbCases)
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
		for (int i = 0; i < m_mines; i++)
		{
			int valRandom = (int)((float)rand() * choixMines.size() / (RAND_MAX - 1));
			m_grille.at(choixMines[valRandom]).setVal(9);
			it = choixMines.begin() + valRandom;
			choixMines.erase(it);
		}
	}
}

// affecte la valeur de chaque case par rapport au nombres de mines autour
void Grille::affecterValeursCases()
{
	int cpt = 0;
	int  x, y;
	for (int parcourCase = 0; parcourCase < m_nbCases; parcourCase++)
	{
		if (m_grille.at(parcourCase).getVal() != 9)
		{
			x = m_grille.at(parcourCase).getX();
			y = m_grille.at(parcourCase).getY();
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (j >= 0 && j < m_hauteur)
				{
					for (int i = x - 1; i <= x + 1; i++)
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

// retourne vrai si la grille est entièrement découverte
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