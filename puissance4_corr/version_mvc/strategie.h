#ifndef _STRATEGIE_H_
#define _STRATEGIE_H_
#include "couleur.h"
#include "model.h"

/**
 * @brief contient les stratégies que l'ordinateur peut jouer.
 **/ 
class Strategie {

public:
    /* constructeur */
    Strategie(JeuModel & model, bool debug=false);
    
    /* strategie stupide, un coup au hasard */
    size_t strat_alea(Couleur const c);
    /* strategie defensive */
    size_t strat_defense(Couleur const c);
    /* strategie offensive et defensive, a meilleure */
    size_t strat_master(Couleur const c);

//------ attributs -------
private:
    JeuModel & model;
    bool debug;
};
#endif