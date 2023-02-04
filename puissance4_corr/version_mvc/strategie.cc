#include "strategie.h"
#include "model.h"
#include "couleur.h"

/// \cond
#include <iostream>
using namespace std;
/// \endcond

/**
 * @brief constructeur d'un objet stratégie, disposant d'une méthode par stratégie.
 * Toute stratégie a besoin de connaitre l'état de la grille (model).
 */  
Strategie::Strategie(JeuModel & model, bool debug) : model(model),debug(debug) {};

/**
 * Une stratégie stupide de jeu au pif
 * @param c la couleur du joueur qui joue
 * @return un entier positif désignant la colonne dans laquelle la strategie a joué
 **/
size_t Strategie::strat_alea(Couleur const c) {
  return rand()% model.get_taille(); // un coup au hasard
}

/**
 * Une stratégie défensive 
 **/
size_t Strategie::strat_defense(Couleur const c) {
  // créons une copie du jeu pour tester des coups
  Couleur advers = model.couleur_opposee(c);
  // On examine chaque coup possible de l'adversaire  et si on 
  // trouve un coup gagnant pour l'adversaire on y place le pion. 
  for (size_t i(0);i< model.get_taille();i++) {
    // on travaille sur une copie du jeu
    JeuModel modelcopie(model);
    if  (model.jouer(i,advers))  { 
      Couleur cgagnant = model.gagnant(); // on teste la grille après le coup
      if (cgagnant == advers) { // jouer cette colonne pour ne pas etre battu 
        if (debug)
            std::cout << "** [strat_def]: avoid loss : col=" << i+1 << endl;
        return i;
      }
    }
  }
  // Pas trouvé de faille, joue un coup au hasard
  size_t col = rand()% model.get_taille();
  if (debug)
    std::cout << "** [strat_def]: random : col=" << col+1 << endl;
  return col;   
}


/**
 * strategie qui cherche 
 * - à gagner,
 * - si pas de coup gagnant, tente d'éviter la perte
 * - sinon joue au hasard
 **/ 
size_t Strategie::strat_master(Couleur const c) {

  // étape - 1 
  // on cherche à jouer un coup gagnant immédiatement
  for (size_t i(0);i< model.get_taille();i++) {
    JeuModel modelcopie(model);
    if  (modelcopie.jouer(i,c))  { 
      Couleur cgagnant = modelcopie.gagnant(); // on teste la grille
      if (cgagnant == c) { // je gagne ! 
        if (debug) 
            std::cout << "** [strat_master]: gain : col=" << i+1 << endl;
        return i;
      }
    }
  }
  // étape - 2
  // On examine chaque coup possible de l'adversaire
  // et si on trouve un coup gagnant pour l'adversaire
  // on y place le pion. 
  Couleur advers = model.couleur_opposee(c);
  for (size_t i(0);i< model.get_taille();i++) {
    JeuModel modelcopie(model);
    if  (modelcopie.jouer(i,advers))  { 
      Couleur cgagnant = modelcopie.gagnant(); // on teste la grille
      if (cgagnant == advers) { // jouer cette colonne pour ne pas etre battu 
        if (debug) {
            std::cout << "** [strat_master]: avoid loss : col=" << i+1 << endl;
        }
        return i;
      }
    }
  }
  // rien de décisif, je joue au hasard
  size_t col = rand() % model.get_taille();
  if (debug)
    std::cout << "** [strat_master]: random : col=" << col+1 << endl;
  return col;   
}
