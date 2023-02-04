
#include "partie.h"
#include "joueur.h"
#include <iostream>
using namespace std;

// ------------------------------------------------------------
// constructeur
Partie::Partie(Joueur * j1, Joueur * j2, size_t taille) 
  : jcurr(j1),
    j1(j1),
    j2(j2),
    jeu(ANSI_COLOR_RESET,taille)    // appelle constructeur par défaut (paramètres par défaut)
                                    // ou spécifier des valeurs spécifiques
    {}

// ------------------------------------------------------------
void Partie::lancer() {
  Couleur vainqueur;
  do {
    jcurr->jouer(jeu);
    if (jcurr == j1)  // alternance des coups
      jcurr = j2;
    else 
      jcurr = j1;  
  } while (not jeu.fini(vainqueur)); // couleur vainqueur mise à jour

  // affichage final du jeu après fin
  cout << "La partie est finie." << endl;
  cout << jeu << endl;
  if (vainqueur == j1->get_couleur()) {
    cout << "Le vainqueur est " << j1->get_nom() << endl;
  } else 
    if (vainqueur == j2->get_couleur()) {
    cout << "Le vainqueur est " << j2->get_nom() << endl;
  } else {
    cout << "Match nul." << endl;
  }
}
