#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Vehicule.hpp"

class Agence {
  private:
    string nom;
    vector<Vehicule *> flotte;

  public:
    Agence(string nom) : nom(nom) {}
    ~Agence() { cout << "-> L'agence " << nom << " ferme ses portes." << endl; }
    void ajouter_flotte(Vehicule *vehicule) { flotte.push_back(vehicule); }
    void afficher_flotte() {
        for (auto e : flotte) {
            e->afficher();
        }
    }
};