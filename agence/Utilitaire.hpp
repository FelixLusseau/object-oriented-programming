#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Vehicule.hpp"

class Utilitaire : public Vehicule {
  private:
    double cubage;

  public:
    Utilitaire(string marque, string modele, double cubage, double prix_loc)
        : Vehicule(marque, modele, prix_loc), cubage(cubage) {
        cout << "-> Utilitaire " << marque << " " << modele << " créé" << endl;
    }
    ~Utilitaire() {}
    void afficher() {
        cout << "[Utilitaire] marque : " << marque << ", modèle : " << modele
             << " (prix jour : " << prix_loc << " Eur (" << cubage << " m3)"
             << endl;
    }
};