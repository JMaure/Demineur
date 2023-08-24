#include "Chrono.h"

using namespace std;

Chrono::Chrono() : m_debut(0), m_fin(0), m_duree(0), m_etat(false)
{}

void Chrono::start()
{
	m_debut = clock();
	m_etat = true;
}

void Chrono::stop()
{
	m_fin = clock();
	m_etat = false;
	m_duree += (m_fin - m_debut) / CLOCKS_PER_SEC;
}

float Chrono::getDuree()
{
	return m_duree;
}

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

bool Chrono::enCours()
{
	return m_etat;
}