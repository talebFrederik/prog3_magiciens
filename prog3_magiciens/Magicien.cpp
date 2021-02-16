#include "Magicien.h"
#include <iostream>

Magicien::Magicien(Sort* sortsAttaque, Sort* sortsDefense) : m_vie{ 50 }, m_mana{ 50 }, m_bouclier{0}
{
	m_baton = new Baton{ sortsAttaque, sortsDefense };
}

Magicien::~Magicien()
{
	delete m_baton;
}

bool Magicien::peutLancerSort() { return m_mana >= 10; }

void Magicien::lancerSort(Magicien* magicien, int attaqueDefense)
{
	if (m_mana < 10) return;

	m_mana -= 10;

	if (attaqueDefense == 0)
	{
		magicien->recevoirDmg(m_baton->attaquer());
	}

	if (attaqueDefense == 1)
	{
		int dmg{ m_baton->defendre() };

		dmg < 0 ? m_bouclier -= dmg : m_vie += dmg;
	}
}

void Magicien::changerBaton(Sort* sortsAttaque, Sort* sortsDefense)
{
	delete m_baton;
	m_baton = new Baton{ sortsAttaque, sortsDefense };
	m_mana += 50;
}

void Magicien::recevoirDmg(int dmg)
{
	if (dmg < 0) { m_vie += dmg; }
	if (dmg > 0)
	{
		m_bouclier -= dmg;
		if (m_bouclier < 0)
		{
			m_vie += m_bouclier;
			m_bouclier = 0;
		}
	}
}

void Magicien::afficherEtat()
{
	std::cout << "Vie : \t\t" << m_vie << "\n";
	std::cout << "Mana : \t\t" << m_mana << "\n";
	std::cout << "Bouclier : \t" << m_bouclier << "\n";
	std::cout << "Baton : \t" << m_baton->getNom() << "\n";
}

bool Magicien::isMort()
{
	return m_vie <= 0;
}
