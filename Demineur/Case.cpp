#include <iostream>
#include "Case.h"

using namespace std;

// Constructeur par d�faut
Case::Case() : m_x(0), m_y(0), m_valeur(0), m_etat(0)
{
}

// Constructeur qui initialise les coordon�es de la case (m_x et m_y) et la valeur de la case m_valeur
Case::Case(int x, int y, int val) : m_x(x), m_y(y), m_valeur(val), m_etat(0)
{
}

// Destructeur
Case::~Case()
{
}

// retourne l'abscisse de la Case
int Case::getX() const
{
	return m_x;
}

// retourne l'ordonn�e de la case
int Case::getY() const
{
	return m_y;
}

// retourne la valeur de la Case
int Case::getVal() const
{
	return m_valeur;
}

// Modifie la valeur de la case m_valeur
void Case::setVal(int val)
{
	this->m_valeur = val;
}

// Retourne un booleen pour savoir si la case a �t� r�v�l�e
bool Case::isDecouverte()
{
	return (m_etat == 1);
}

// Modifie la valeur de m_etat � 1 (case r�v�l�e)
void Case::decouverte()
{
	this->m_etat = 1;
}

// Retourne un booleen pour savoir si la case est marqu�e comme mine
bool Case::isMarquee()
{
	return (m_etat == 2);
}

// Modifie la valeur de m_etat � 2 (case marqu�e comme mine)
void Case::marquee()
{
	this->m_etat = 2;
}