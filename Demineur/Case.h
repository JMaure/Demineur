#pragma once

#ifndef DEF_CASE
#define DEF_CASE

class Case
{
public:
	// Constructeur par défaut
	Case();
	// Constructeur qui initialise les coordonées de la case (m_x et m_y) et la valeur de la case m_valeur
	Case(int x, int y, int val);
	// Destructeur
	~Case();

	// retourne la valeur de la Case
	int getVal() const;
	// retourne l'abscisse de la Case
	int getX() const;
	// retourne l'ordonnée de la case
	int getY() const;

	// Modifie la valeur de la case m_valeur
	void setVal(int val);

private:
	// abscisse de la case
	int m_x;
	// ordonnée de la case
	int m_y;
	// valeur de la case : 9 est une mine, 0 à 8 nombre de mines autour
	int m_valeur;
};

#endif