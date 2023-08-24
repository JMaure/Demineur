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

	// Retourne un booleen pour savoir si la case a été révélée
	bool isDecouverte();

	// Modifie la valeur de m_etat à 1 (case révélée)
	void decouverte();

	// Retourne un booleen pour savoir si la case est marquée comme mine
	bool isMarquee();

	// Modifie la valeur de m_etat à 2 (case marquée comme mine)
	void marquee();

private:
	// abscisse de la case
	int m_x;

	// ordonnée de la case
	int m_y;

	// valeur de la case : 9 est une mine, 0 à 8 nombre de mines autour
	int m_valeur;

	// 0 case cachée, 1 case révélée, 2 case marquée comme mine
	int m_etat;
};

#endif