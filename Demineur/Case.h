#pragma once

#ifndef DEF_CASE
#define DEF_CASE

class Case
{
public:
	Case();
	Case(int x, int y, int val);
	~Case();

	int getVal() const;
	int getX() const;
	int getY() const;

	void setVal(int val);

private:
	int m_x;
	int m_y;
	int m_valeur;
};

#endif