#include "couleur.h"
#include "joueur.h"
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
size_t Humain::jouer() const {
  size_t lu;
  cout << "Joueur " << nom << ", entrez un numero de colonne: ";
  cin >> lu; // on pourrait faire ici la validation de la lecture
  lu--; // pour avoir des indices demarrant a 0 
  return lu;
}


// ------------------------------------------------------------
size_t Machine::jouer() const {
	// ici l'algorithme du joueur machine 
	size_t colonne; // la colonne choisie
#ifdef DEBUG
	Strategie s(model,true);  // active ou non l'affichage de debug (cc -DDEBUG)
#else
	Strategie s(model,false);  // active ou non l'affichage de debug
#endif
	colonne = s.strat_master(couleur);
	cout << nom << " a joue en " << colonne+1 << endl;
	return colonne;
}

