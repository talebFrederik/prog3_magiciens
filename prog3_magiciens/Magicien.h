#ifndef MAGICIEN_H
#define MAGICIEN_H

#include "Baton.h"
#include <string>


class Magicien
{
private:
	int m_vie;
	int m_mana;
	int m_bouclier;
	Baton* m_baton;
public:
	Magicien(Sort* sortsAttaque, Sort* sortsDefense);
	~Magicien();
	bool peutLancerSort();
	void lancerSort(Magicien* magicien, int attaqueDefense);
	void changerBaton(Sort* sortsAttaque, Sort* sortsDefense);
	void recevoirDmg(int dmg);
	void afficherEtat();
	bool isMort();
};

#endif