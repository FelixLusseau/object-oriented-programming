#pragma once

#include "couleur.h"
#include "jeu.h"
#include <string>
using namespace std;


/**
 * @brief classe abstraite qui représente les caractéristiques communes à n'importe quel joueur, qu'il soit
 * humain ou ordinateur.
 **/ 
class Joueur {
public:

  Joueur(const string& un_nom, const Couleur& une_couleur = rouge)
    : nom(un_nom), couleur(une_couleur) {}
  virtual ~Joueur() {}
  /* @brief méthode abstraite qui initie le jeu. */
  virtual void jouer(Jeu &) const = 0;
  /* @brief rend le nom du joueur */
  string get_nom() const;
  /* @brief rend la couleur du joueur */
  Couleur get_couleur() const { return couleur; }

protected:
  string nom;
  const Couleur couleur;
};

/**
 * @brief classe concrète qui modélise un joueur humain.
 **/ 
class Humain : public Joueur {
public:
  Humain(Couleur une_couleur = rouge) : Joueur("quidam", une_couleur) {
    cout << "Entrez votre nom : " << flush;
    cin >> nom;
  }
  /* @brief l'action de jeu d'un humain : saisie de son coup au clavier.*/
  void jouer(Jeu &) const;
};

/**
 * @brief classe concrète qui modélise un joueur ordinateur.
 **/ 
class Machine : public Joueur {
 public:
    Machine(Couleur couleur = jaune) : Joueur("Le programme", couleur) {}
  /* @brief l'action de jeu d'une machine : appliquer une des strategies disponibles.*/
    void jouer(Jeu&) const;
};
