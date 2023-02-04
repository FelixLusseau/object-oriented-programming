#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Vehicule.hpp"

class Voiture : public Vehicule {
  private:
    size_t nb_portes;

  public:
    Voiture(string marque, string modele, size_t nb_portes, double prix_loc)
        : Vehicule(marque, modele, prix_loc), nb_portes(nb_portes) {
        cout << "-> Voiture " << marque << " " << modele << " créée" << endl;
    }
    ~Voiture() {}
    void afficher() {
        cout << "[Voiture] marque : " << marque << ", modèle : " << modele
             << " (prix jour : " << prix_loc << " Eur (" << nb_portes
             << " portes)" << endl;
    }
};