#pragma once
#include "couleur.h"

/// \cond
#include <vector>
/// \endcond

/**
 * @brief Cette classe gère la structure interne des données du jeu.
 * Les méthodes permettent
 *  - de poser un pion en colonne j : jouer(j)
 *  - connaitre le pion à la case i,j : get_contents(i,j)
 *  - connaitre la taille de la grille : get_taille()
 *  - savoir si la grille est pleine : fini()
 *  - savoir si une position est gagnante : gagnant()
 **/
class JeuModel {
  public:
    /**
     * @brief constructeur par défaut fixant la taille du jeu et la couleur d'affichage.
     **/
    JeuModel(size_t taille = 8);
    JeuModel(JeuModel const &jorig);
    ~JeuModel();

  private:
    int cherche_ligne(size_t i);

  public:
    /**
     * rend la taille de la grille
     **/
    size_t get_taille() const { return grille.size(); }

    /**
     * @brief rend l'élément à l'emplacement i,j
     * @return rend une des couleurs possible ou vide.
     **/
    Couleur get_contents(size_t i, size_t j) const {
        Couleur val = grille[i][j];
        return val;
    }

    /**
     * renvoie la couleur opposée
     **/
    Couleur couleur_opposee(Couleur c) { return (c == rouge ? jaune : rouge); }

    /**
     * @brief jouer : pose d'un pion de couleur c en colonne i. Si la pose est valide, la grille est modifiée
     * @param i la colonne où est posée le pion
     * @param c la couleur du pion
     * @return vrai si pose valide, faux sinon
     **/
    bool jouer(size_t, Couleur);

    /**
     * Si une position est gagnante, rend la couleur qui gagne,
     * sinon rend la couleur 'vide'
     **/
    Couleur gagnant() const;

    /**
     * fini rend vrai si aucune case n'est vide, faux sinon.
     **/
    bool fini(Couleur &) const;

  private:
    /**
     * @brief compte le nombre de pions d'une même couleur dans une direction donnée
     * et à partir d'une coordonnée donnée.
     * @param couleur la couleur
     * @param i le numéro de ligne de la coordonnée
     * @param j le numéro de colonne de la coordonnée
     * @param di le delta en lignes du vecteur de direction
     * @param dj le delta en colonnes du vecteur de direction
     * @return le nombre de pions de la même couleur dans la direction donnée à partir de i,j
     **/
    unsigned int compte(Couleur, size_t, size_t, int, int) const;

    // ---------- attributs ------------
  private:
    // @brief le stockage de la grille de jeu.
    std::vector<std::vector<Couleur>> grille;
};
