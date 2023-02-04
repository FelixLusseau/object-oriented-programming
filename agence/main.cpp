#include "Agence.hpp"
#include "Utilitaire.hpp"
#include "Vehicule.hpp"
#include "Voiture.hpp"

#include <iostream>
#include <vector>
using namespace std;

int main() {

    Agence malocation("MaLocation");

    // description des utilitaires et voitures a enregistrer dans l'agence

    vector<Utilitaire> utilitaires;
    // constructeur marque,modele,cubage,prix
    utilitaires.push_back(Utilitaire("Mercedes", "Vito", 9., 50.));
    utilitaires.push_back(Utilitaire("Peugeot", "Master", 9., 45.));
    utilitaires.push_back(Utilitaire("Renault", "Kangoo", 4., 35.));

    vector<Voiture> voitures;
    // constructeur marque,modele,portes,prix
    voitures.push_back(Voiture("Peugeot", "207", 5, 25.));
    voitures.push_back(Voiture("Renault", "Clio", 3, 25.));

    // ajout de ces vehicules à la flotte de l'agence.
    for (size_t i(0); i < utilitaires.size(); i++)
        malocation.ajouter_flotte(&utilitaires[i]);

    for (size_t i(0); i < voitures.size(); i++)
        malocation.ajouter_flotte(&voitures[i]);

    // affiche la flotte enregistree pour l'agence malocation
    malocation.afficher_flotte();

    return 0;
}