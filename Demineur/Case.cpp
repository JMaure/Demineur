#include "Case.h"

Case::Case() : m_x(0), m_y(0), m_valeur(0)
{
}

Case::Case(int x, int y, int val) : m_x(x), m_y(y), m_valeur(val)
{
}

Case::~Case()
{
}

int Case::getX() const
{
	return m_x;
}

int Case::getY() const
{
	return m_y;
}

int Case::getVal() const
{
	return m_valeur;
}

void Case::setVal(int val)
{
	this->m_valeur = val;
}