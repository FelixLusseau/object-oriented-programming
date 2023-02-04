#include <iostream>
#include <string>
#include <vector>
#include "couleur.h"
#include "joueur.h"
#include "jeu.h"
#include "strategie.h"
using namespace std;

string Joueur::get_nom() const { 
	switch (couleur) {
		case rouge : return(ANSI_COLOR_RED + nom + ANSI_COLOR_RESET); break;
		case jaune : return(ANSI_COLOR_YELLOW + nom + ANSI_COLOR_RESET);break; 
		case vide : return(nom);break;  
	}
	return nom; 
}
// ------------------------------------------------------------
void Humain::jouer(Jeu& jeu) const {
  size_t lu;
  bool valide;
  do {
	    cout << "Joueur " << nom << ", entrez un numero de colonne" << endl
			<< "  (entre 1 et " << jeu.get_taille() << ") : ";
	    cin >> lu; // on pourrait faire ici la validation de la lecture
	    lu--; // pour avoir des indices demarrant a 0 
	    valide = jeu.jouer(lu, couleur);
	    if (not valide) cout << "-> Coup NON valide." << endl;
  } while (not valide);
}


// ------------------------------------------------------------
void Machine::jouer(Jeu& jeu) const {
	// ici l'algorithme du joueur machine 
	size_t colonne; // la colonne choisie
#ifdef DEBUG
	Strategie s(true);  // active ou non l'affichage de debug (cc -DDEBUG)
#else
	Strategie s(false);  // active ou non l'affichage de debug
#endif
	colonne = s.strat_master(jeu,couleur);
	if (jeu.jouer(colonne, couleur)) {
		cout << jeu;
		cout << nom << " a joue en " << colonne+1 << endl;
		cerr << colonne+1 << endl;
	}
}

