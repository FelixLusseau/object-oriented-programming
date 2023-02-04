#ifndef PARTIE_H
#define PARTIE_H

#include <iostream>
#include <string>
#include <vector>

#include "couleur.h"
#include "jeu.h"
#include "joueur.h"

using namespace std;

class Partie {
  private:
    Joueur *joueurcurr;
    Joueur *joueur1;
    Joueur *joueur2;
    Jeu jeu;

  public:
    Partie(Joueur *joueur1, Joueur *joueur2, size_t taille = 8)
        : joueurcurr(joueur1), joueur1(joueur1), joueur2(joueur2),
          jeu(ANSI_COLOR_RESET, taille) {}

    void lancer() {
        Couleur vainqueur;
        do {
            joueurcurr->jouer(jeu);
            if (joueurcurr == joueur1) {
                joueurcurr = joueur2;
                jeu.affiche(cout);
            } else
                joueurcurr = joueur1;
        } while (not jeu.fini(vainqueur));
        cout << endl << "La partie est finie." << endl;
        cout << jeu << endl;
        if (vainqueur == joueur1->get_couleur()) {
            cout << "Le vainqueur est " << joueur1->get_nom() << endl;
        } else if (vainqueur == joueur2->get_couleur()) {
            cout << "Le vainqueur est " << ANSI_COLOR_GREEN
                 << joueur2->get_nom() << ANSI_COLOR_RESET << endl;
        } else {
            cout << "Match nul." << endl;
        }
    }
};

#endif