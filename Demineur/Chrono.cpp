#include "Chrono.h"

using namespace std;

// Constructeur
Chrono::Chrono() : m_debut(0), m_fin(0), m_duree(0), m_etat(false)
{}

// lancement du timer
void Chrono::start()
{
	m_debut = clock();
	m_etat = true;
}

// arret du timer
void Chrono::stop()
{
	m_fin = clock();
	m_etat = false;
	m_duree += (m_fin - m_debut) / CLOCKS_PER_SEC;
}

// retourne la durée du timer
float Chrono::getDuree()
{
	return m_duree;
}

// afficher la durée
void Chrono::afficher()
{
	int sec = 0, min = 0, heu = 0;
	min = m_duree / 60;
	sec = m_duree % 60;
	if (min >= 60)
	{
		heu = min / 60;
		min = min % 60;
	}
	if (heu > 0)
		cout << heu << "h ";
	if (min > 0)
		cout << min << "min ";
	cout << sec << "sec";
}

// retourne vrai si le timer est en cours, faux sinon
bool Chrono::enCours()
{
	return m_etat;
}