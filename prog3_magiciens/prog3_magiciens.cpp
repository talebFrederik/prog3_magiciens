#include "utilitaires.h"
#include "Magicien.h"
#include <iostream>

int main()
{
    Sort sortsAttaque[2]
    {
        {"Incinerateur", 10},
        {"Foudre", -7}
    };
    Sort sortsDefense[2]
    {
        {"Guerison", 5},
        {"Protection", -7}
    };
    Magicien joueur{ sortsAttaque, sortsDefense };
    Magicien ennemi{ sortsAttaque, sortsDefense };

    bool jouer = true;

    while (jouer)
    {
        // Affichage
        std::system("CLS");
        std::cout << "Joueur \n";
        joueur.afficherEtat();

        std::cout << "\n" << "Ennemi \n";
        ennemi.afficherEtat();

        std::cout << "\n" << "Actions : \n";
        char action{'c'};
        if (joueur.peutLancerSort())
        {
            std::cout << "a \t attaquer\n";
            std::cout << "d \t defendre\n";
        }
        std::cout << "c \t changer de baton\n";
        std::cout << "q \t quitter\n";
        std::cin >> action;

        // Mise à jour
        switch (action)
        {
        case 'a':
            joueur.lancerSort(&ennemi, 0);
            break;
        case 'd':
            joueur.lancerSort(&ennemi, 1);
            break;
        case 'c':
            joueur.changerBaton(sortsAttaque, sortsDefense);
            break;
        case 'q':
            jouer = false;
            break;
        default:
            joueur.changerBaton(sortsAttaque, sortsDefense);
            break;
        }
        
        if (ennemi.peutLancerSort())
        {
            ennemi.lancerSort(&joueur, utilitaires::rng(0, 1));
        }
        else
        {
            ennemi.changerBaton(sortsAttaque, sortsDefense);
        }

        jouer ? !(joueur.isMort() || ennemi.isMort()): jouer;

        if (joueur.isMort())
        {
            std::system("CLS");
            std::cout << "Joueur \n";
            joueur.afficherEtat();

            std::cout << "\n" << "Ennemi \n";
            ennemi.afficherEtat();

            std::cout << "Vous avez perdu! LOSER!";
        }

        if (ennemi.isMort())
        {
            std::system("CLS");
            std::cout << "Joueur \n";
            joueur.afficherEtat();

            std::cout << "\n" << "Ennemi \n";
            ennemi.afficherEtat();

            std::cout << "Vous avez gangné! VICTOIRE!";
        }
    }
}

