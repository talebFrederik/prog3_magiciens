#ifndef SORT_H
#define SORT_H

#include <string>

class Sort
{
private:
	std::string m_nom;
	int m_dmg;
public:
	Sort(std::string nom, int dmg);
	int getDmg();
	std::string getNom();
};

#endif