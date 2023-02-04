#include "couleur.h"
#include "controller.h"
#include "view.h"
#include "model.h"
/// \cond
#include <cstdlib>  // pour rand()
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
/// \endcond

/**
 * constructor 
 **/
JeuController::JeuController(Joueur & j1, Joueur & j2, JeuModel & model, JeuView & view) 
  : j1(j1), j2(j2),jcurr(&j1),model(model),view(view)
{
   srand((unsigned)time(0)); // initialise la graine aleatoire
}

JeuController::~JeuController() {}


void JeuController::lancer() {
  Couleur vainqueur;
  size_t col;
  do {
    do {
      col = jcurr->jouer();
    }

    while (!model.jouer(col, jcurr->get_couleur()));

    cout << view << endl;

    if (jcurr == &j1)  // alternance des coups
      jcurr = &j2;
    else 
      jcurr = &j1;  
  } while (not model.fini(vainqueur)); // couleur vainqueur mise à jour

  // affichage final du jeu après fin
  cout << "La partie est finie." << endl;
  if (vainqueur == j1.get_couleur()) {
    cout << "Le vainqueur est " << j1.get_nom() << endl;
  } else 
    if (vainqueur == j2.get_couleur()) {
    cout << "Le vainqueur est " << j2.get_nom() << endl;
  } else {
    cout << "Match nul." << endl;
  }
}


