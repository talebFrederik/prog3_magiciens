#include "Sort.h"

#include <string>

Sort::Sort(std::string nom, int dmg) : m_nom{ nom }, m_dmg{ dmg }{}

int Sort::getDmg() { return m_dmg; }

std::string Sort::getNom() { return m_nom; }