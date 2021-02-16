#ifndef BATON_H
#define BATON_H

#include "Sort.h"
#include <string>

class Baton
{
private:
	Sort* m_sortAttaque;
	Sort* m_sortDefense;
public:
	Baton(Sort* sortsAttaque, Sort* sortsDefense);
	std::string getNom();
	int attaquer();
	int defendre();
};

#endif
