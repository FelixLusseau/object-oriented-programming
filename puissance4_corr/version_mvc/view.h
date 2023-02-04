#ifndef _VIEW_H_ 
#define _VIEW_H_
#include "model.h"
#include "couleur.h"
/// \cond
#include <iostream>
/// \endcond

class JeuView {

private:
    JeuModel const & model; // The view does not modify the data
    std::string couleur_affiche; 


public:
    JeuView(JeuModel const & model, std::string couleur_affiche = ANSI_COLOR_RESET) 
    : model(model),couleur_affiche(couleur_affiche){}

    std::ostream & affiche(std::ostream & out) const;
};

// prototype surcharge << externe
std::ostream & operator<<(std::ostream & out, JeuView const & view);

#endif