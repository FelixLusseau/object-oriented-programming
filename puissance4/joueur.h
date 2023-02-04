#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <string>

#include "jeu.h"
#include "strategie.h"

using namespace std;

class Joueur {
  protected:
    string nom;
    Couleur couleur;

  public:
    Joueur(string nom, Couleur couleur = rouge) : nom(nom), couleur(couleur) {}
    ~Joueur() {}
    virtual void jouer(Jeu &jeu) = 0;
    string get_nom() const { return nom; }
    Couleur get_couleur() const { return couleur; }
};

class Humain : public Joueur {
  public:
    Humain(Couleur couleur = rouge) : Joueur("humain", couleur) {
        cout << "Entrez votre nom : " << flush;
        cin >> nom;
    }
    void jouer(Jeu &jeu) override {
        size_t colonne;
        while (1) {
            cout << endl << "Donner un numéro de colonne : " << flush;
            cin >> colonne;
            if (jeu.jouer(colonne - 1, couleur) == false) {
                cout << "Saisie invalide !" << endl;
            } else
                break;
        }
    }
};

class Machine : public Joueur {
  public:
    Machine(Couleur couleur = jaune) : Joueur("machine", couleur) {}
    void jouer(Jeu &jeu) override {
        jeu.jouer(strat_alea() % jeu.get_taille(), couleur);
    }
    size_t strat_alea() {
        srand(time(NULL));
        return rand();
    }
    //  size_t strat_defense(Couleur c) {}
};

#endif