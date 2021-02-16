#include "utilitaires.h"
#include <random>

int utilitaires::rng(int min, int max)
{
	std::random_device rd;
	std::mt19937 rn(rd());
	std::uniform_int_distribution<> rng(min, max);

	int nombre = rng(rn);

	return nombre;

}