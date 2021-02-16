#include "Baton.h"
#include "Sort.h"
#include "utilitaires.h"
#include <string>

Baton::Baton(Sort* sortsAttaque, Sort* sortsDefense)
{
	// choisir le nième sort de chaque type
	// à éviter normalement mais pour les besoins de simplicité on utilise des nombres magiques (hard coded)
	// à l'avenir il sera possible d'utiliser l'objet <vector> ou <list> qui nous permet d'avoir la taille de la liste ou du tableau
	int rngSortAttaque = utilitaires::rng(0, 1);
	int rngSortDefense = utilitaires::rng(0, 1);

	m_sortAttaque = &sortsAttaque[rngSortAttaque];
	m_sortDefense = &sortsDefense[rngSortDefense];
}

std::string Baton::getNom()
{
	return m_sortAttaque->getNom() + " de " + m_sortDefense->getNom();
}

int Baton::attaquer()
{
	return m_sortAttaque->getDmg();
}

int Baton::defendre()
{
	return m_sortDefense->getDmg();
}