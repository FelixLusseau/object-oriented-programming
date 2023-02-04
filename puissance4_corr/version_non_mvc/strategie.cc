#include "strategie.h"
#include "jeu.h"
#include "couleur.h"
#include <iostream>
using namespace std;



Strategie::Strategie(bool debug) : debug(debug) {};

/**
 * Une stratégie stupide de jeu au pif
 * @param jeu la grille
 * @param c la couleur du joueur qui joue
 * @return un entier positif désignant la colonne dans laquelle la strategie a joué
 **/
size_t Strategie::strat_alea(Jeu const & jeu, Couleur const c) {
  return rand()% jeu.get_taille(); // un coup au hasard
}

/**
 * Une stratégie défensive : tente d'abord de déterminer si un coup
 * de l'adversaire peut faire perdre, et joue pour contrer ce coup.
 * Si aucun coup adverse ne peut faire perdre, joue dans une colonne
 * au hasard.
 * @param jeu la grille
 * @param c la couleur du joueur qui joue
 * @return un entier positif désignant la colonne dans laquelle la strategie a joué
 **/
size_t Strategie::strat_defense(Jeu const & j, Couleur const c) {
  // créons une copie du jeu pour tester des coups
  Couleur advers = j.couleur_opposee(c);
  // On examine chaque coup possible de l'adversaire  et si on 
  // trouve un coup gagnant pour l'adversaire on y place le pion. 
  for (size_t i(0);i< j.get_taille();i++) {
    // on travaille sur une copie du jeu
    Jeu jcopie(j);
    if  (jcopie.jouer(i,advers))  { 
      Couleur cgagnant = jcopie.gagnant(); // on teste la grille après le coup
      if (cgagnant == advers) { // jouer cette colonne pour ne pas etre battu 
        if (debug)
            std::cout << "** [strat_def]: avoid loss : col=" << i+1 << endl;
        return i;
      }
    }
  }
  // Pas trouvé de faille, joue un coup au hasard
  size_t col = rand()% j.get_taille();
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
size_t Strategie::strat_master(Jeu const & j, Couleur const c) {

  // étape - 1 
  // on cherche à jouer un coup gagnant immédiatement
  for (size_t i(0);i< j.get_taille();i++) {
    Jeu jcopie(j);
    if  (jcopie.jouer(i,c))  { 
      Couleur cgagnant = jcopie.gagnant(); // on teste la grille
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
  Couleur advers = j.couleur_opposee(c);
  for (size_t i(0);i< j.get_taille();i++) {
    Jeu jcopie(j);
    if  (jcopie.jouer(i,advers))  { 
      Couleur cgagnant = jcopie.gagnant(); // on teste la grille
      if (cgagnant == advers) { // jouer cette colonne pour ne pas etre battu 
        if (debug) {
            std::cout << jcopie;
            std::cout << "** [strat_master]: avoid loss : col=" << i+1 << endl;
        }
        return i;
      }
    }
  }
  // rien de décisif, je joue au hasard
  size_t col = rand() % j.get_taille();
  if (debug)
    std::cout << "** [strat_master]: random : col=" << col+1 << endl;
  return col;   
}
