#pragma once 
#include "couleur.h"
#include "model.h"

/// \cond
#include <string>
#include <iostream>
/// \endcond

/**
 * @brief classe abstraite qui représente les caractéristiques communes à n'importe quel joueur, qu'il soit
 * humain ou ordinateur.
 **/ 
class Joueur {
public:

  Joueur(const std::string& un_nom, const Couleur& couleur, JeuModel & model)
    : nom(un_nom), couleur(couleur), model(model) 
    {}

  virtual ~Joueur() {}

  /* @brief méthode abstraite declenche le coup d'un joueur */
  virtual size_t jouer() const = 0;
  /* @brief rend le nom du joueur */
  std::string get_nom() const;
  /* @brief rend la couleur du joueur */
  Couleur get_couleur() const { return couleur; }

protected:
  std::string nom;
  const Couleur couleur;
  JeuModel & model;
};

/**
 * @brief classe concrète qui modélise un joueur humain.
 **/ 
class Humain : public Joueur {
public:
  Humain(JeuModel & model, Couleur une_couleur = rouge) : Joueur("Quidam", une_couleur, model) {
    std::cout << "Entrez votre nom : " << std::flush;
    std::cin >> nom;
  }
  /** 
   * @brief l'action de jeu d'un humain : saisie de son coup au clavier.
   * @return rend le numéro de colonne (entre 0 et 7) joué.
  */
  size_t jouer() const override;
};

/**
 * @brief classe concrète qui modélise un joueur ordinateur.
 **/ 
class Machine : public Joueur {
 public:
    Machine(JeuModel & model,Couleur couleur = jaune) : Joueur("Le programme", couleur,model) {}
  /** 
   * @brief l'action de jeu d'une machine : appliquer une des strategies disponibles.
   * @return rend le numéro de colonne (entre 0 et 7) joué.
   */
    size_t jouer() const override;
};
