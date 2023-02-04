#pragma once
#include "couleur.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

/**
 * @brief gére le jeu. Fournit des méthodes pour initier et terminer le jeu.
 **/
class Jeu {
public:
  /**
   * @brief constructeur par défaut fixant la taille du jeu et la couleur d'affichage. 
   **/
  Jeu(string couleur_affiche = ANSI_COLOR_RESET, size_t taille = 8);
  Jeu(Jeu const& jorig);
  ~Jeu();
  /**
   * jouer : pose d'un pion de couleur c en colonne i. Si la pose est valide, la grille est modifiée
   * @param i la colonne où est posée le pion
   * @param c la couleur du pion
   * @return vrai si pose valide, faux sinon
  **/
  bool jouer(size_t, Couleur);

  /** 
  * Si une position est gagnante, rend la couleur qui gagne,
  *sinon rend la couleur `vide`.
  **/
  Couleur gagnant() const;

  /**
   * Rend vrai si le jeu ne peut plus continuer, faux sinon.
   * Le jeu ne peut plus continuer si : soit la grille est pleine,
   * soit car un des joueurs a gagné.
   * @param c est mis à jour en sortie avec la couleur qui a gagné. 
   *        Un retour vrai et une couleur indique un jeu fini par
   *        gain du joueur de Couleur c. Si aucune couleur n'a gagné
   *        (que le retour soit vrai ou faux) la Couleur renvoyée est 
   *        `vide`.
   * @return renvoie vrai si le jeu ne pas continuer, faux sinon. 
  **/
  bool fini(Couleur& c ) const;
  /**
   * rend la taille de la grille
   **/ 
  size_t get_taille() const { return grille.size(); }
  /** 
   * renvoie la couleur opposée
   **/
  Couleur couleur_opposee(Couleur c) const { return (c==rouge ? jaune : rouge); }
  ostream& affiche(ostream& out) const;

private:
  /**
 * @brief compte le nombre de pions d'une même couleur dans une direction donnée
 * et à partir d'une coordonnée donnée.
 * @param couleur la couleur
 * @param i le numéro de ligne de la coordonnée
 * @param j le numéro de colonne de la coordonnée
 * @param di le delta en lignes du vecteur de direction
 * @param dj le delta en colonnes du vecteur de direction
 * @return le nombre de pions de la même couleur dans la direction donnée à partir de i,j
 **/
  unsigned int compte(Couleur, size_t, size_t,int, int) const;

  // ---------- attributs ------------
private:
  int cherche_ligne(size_t i);

protected:
  // @brief le stockage de la grille de jeu.
  vector< vector< Couleur > > grille;
  // @brief la couleur d'affichage du jeu à l'écran.
  string couleur_affiche;  
  bool debug;
};

// prototype surcharge << externe
ostream& operator<<(ostream& out, const Jeu& jeu);
