#ifndef VEHICULE_HPP
#define VEHICULE_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicule {
  protected:
    string marque;
    string modele;
    double prix_loc;

  public:
    Vehicule(string marque, string modele, double prix_loc)
        : marque(marque), modele(modele), prix_loc(prix_loc) {}
    virtual ~Vehicule() {}
    virtual void afficher() {
        cout << "[Vehicule] marque : " << marque << ", modèle : " << modele
             << " (prix jour : " << prix_loc << " Eur)" << endl;
    }
};

#endif