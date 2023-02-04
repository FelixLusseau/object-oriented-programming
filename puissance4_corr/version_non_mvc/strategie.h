#pragma once
#include "couleur.h"
#include "jeu.h"
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief contient les stratégies que l'ordinateur peut jouer.
 **/ 
class Strategie {

public:
    Strategie(bool debug=false);
    /** Une strategie stupide: un coup au hasard
 	* @param jeu la grille
 	* @param c la couleur du joueur qui joue
 	* @return un entier positif désignant la colonne dans laquelle la strategie a joué
	**/
    size_t strat_alea(Jeu const & jeu, Couleur const c);

    /**
 	* Une stratégie défensive : tente d'abord de déterminer si un coup
 	* de l'adversaire peut faire perdre, et joue pour contrer ce coup.
 	* Si aucun coup adverse ne peut faire perdre, joue dans une colonne
 	* au hasard.
 	* @param jeu la grille
 	* @param c la couleur du joueur qui joue
 	* @return un entier positif désignant la colonne dans laquelle la strategie a joué
 	**/
    size_t strat_defense(Jeu const & jeu, Couleur const c);

    /**
 	* Une stratégie défensive et offensive : tente d'abord de déterminer si un coup
 	* de l'adversaire peut faire perdre, et joue pour contrer ce coup.
 	* Si aucun coup adverse ne peut faire perdre, cherche un coup qui serait gagnant.
 	* @param jeu la grille
 	* @param c la couleur du joueur qui joue
 	* @return un entier positif désignant la colonne dans laquelle la strategie a joué
 	**/
    size_t strat_master(Jeu const & j, Couleur const c);

//------ attributs -------
private:   bool debug;
};
