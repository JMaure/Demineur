#pragma once

#ifndef DEF_CHRONO
#define DEF_CHRONO

#include <iostream>

class Chrono
{
public:
	// Constructeur
	Chrono();

	// lancement du timer
	void start();

	// arret du timer 
	void stop();

	// retourne la dur�e du timer
	float getDuree();

	// afficher la dur�e
	void afficher();

	// retourne vrai si le timer est en cours, faux sinon
	bool enCours();

private:
	// heure de lancement du timer
	clock_t m_debut;

	// heure d'arret du timer
	clock_t m_fin;

	// dur�e
	int m_duree;

	// etat du timer : en cours ou arret�
	bool m_etat;
};

#endif
