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

	// retourne la durée du timer
	float getDuree();

	// afficher la durée
	void afficher();

	// retourne vrai si le timer est en cours, faux sinon
	bool enCours();

private:
	// heure de lancement du timer
	clock_t m_debut;

	// heure d'arret du timer
	clock_t m_fin;

	// durée
	int m_duree;

	// etat du timer : en cours ou arreté
	bool m_etat;
};

#endif
