#pragma once

#ifndef DEF_CASE
#define DEF_CASE

class Case
{
public:
	// Constructeur par d�faut
	Case();

	// Constructeur qui initialise les coordon�es de la case (m_x et m_y) et la valeur de la case m_valeur
	Case(int x, int y, int val);

	// Destructeur
	~Case();

	// retourne la valeur de la Case
	int getVal() const;

	// retourne l'abscisse de la Case
	int getX() const;

	// retourne l'ordonn�e de la case
	int getY() const;

	// Modifie la valeur de la case m_valeur
	void setVal(int val);

	// Retourne un booleen pour savoir si la case a �t� r�v�l�e
	bool isDecouverte();

	// Modifie la valeur de m_etat � 1 (case r�v�l�e)
	void decouverte();

	// Retourne un booleen pour savoir si la case est marqu�e comme mine
	bool isMarquee();

	// Modifie la valeur de m_etat � 2 (case marqu�e comme mine)
	void marquee();

private:
	// abscisse de la case
	int m_x;

	// ordonn�e de la case
	int m_y;

	// valeur de la case : 9 est une mine, 0 � 8 nombre de mines autour
	int m_valeur;

	// 0 case cach�e, 1 case r�v�l�e, 2 case marqu�e comme mine
	int m_etat;
};

#endif