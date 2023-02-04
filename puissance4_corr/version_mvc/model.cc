#include "model.h"
#include "couleur.h"
/// cond
#include <cstdlib> // for rand()
#include <ctime>
#include <vector>
/// endcond

/**
 * constructor
 **/
JeuModel::JeuModel(size_t taille)
    : grille(taille, std::vector<Couleur>(taille, vide)) {
    srand((unsigned)time(0)); // initialise la graine aleatoire
}

JeuModel::~JeuModel() {}

JeuModel::JeuModel(JeuModel const &jorig) : grille(jorig.grille) {}
/**
 * rend le numéro de ligne où tombe le pion sur cette colonne,
 * -1 si la colonne est pleine.
 * @param i le numero de colonne
 **/

int JeuModel::cherche_ligne(size_t i) {
    size_t j(0);
    while (grille[i][j] != vide)
        j++;
    if (j <= get_taille())
        return j;
    return -1;
}

/**
 * jouer : accepte la pose d'un pion de couleur c en colonne i.
 * Si la pose est valide, la grille est modifiée
 * @param i la colonne où est posée le pion
 * @param c la couleur du pion
 * @return vrai si pose valide, faux sinon
 **/
bool JeuModel::jouer(size_t i, Couleur c) {
    if (c == vide) // empeche incoherence
        return false;
    if (i > get_taille()) // empeche incoherence
        return false;
    int j = cherche_ligne(i);
    if (j == -1)
        return false;
    grille[i][j] = c;
    return true;
}

// ------------------------------------------------------------
bool JeuModel::fini(Couleur &resultat) const {
    resultat = gagnant();
    if (resultat == vide) { // si pas de couleur gagnante
        // est-ce plein ?
        for (auto ligne : grille) {
            for (auto square : ligne) { // "case" est un mot réservé
                if (square == vide)
                    return false;
            }
        }
    }
    return true;
}

/**
 * gagnant : teste si une couleur gagne le jeu.
 * @return couleur du joueur gagnant, ou vide si pas de position gagnante.
 **/
Couleur JeuModel::gagnant() const {
    Couleur vainqueur(vide);
    for (size_t i(0); i < get_taille(); i++) {
        for (size_t j(0); j < get_taille(); j++) {
            if (grille[i][j] != vide) {
                vainqueur = grille[i][j];
                // teste dans les 5 directions possibles (+ (0,0) qui ne fait
                // rien)
                for (int di(0); di <= 1; ++di)
                    for (int dj(-1); dj <= 1; ++dj)
                        if (compte(vainqueur, i, j, di, dj) >= 4)
                            return vainqueur;
            }
        }
    }
    return vide;
}

/**
 * @brief compte le nombre de pions d'une même couleur dans une direction donnée
 * et à partir d'une coordonnée donnée.
 * @param couleur la couleur
 * @param i le numéro de ligne de la coordonnée
 * @param j le numéro de colonne de la coordonnée
 * @param di le delta en lignes du vecteur de direction
 * @param dj le delta en colonnes du vecteur de direction
 * @return le nombre de pions de la même couleur dans la direction donnée à
 *partir de i,j
 **/
unsigned int JeuModel::compte(Couleur couleur, size_t i, size_t j, int di,
                              int dj) const {
    unsigned int n(1);
    if ((di != 0) or (dj != 0)) {
        for (i += di, j += dj; (i < get_taille()) and (j < get_taille()) and
                               (grille[i][j] == couleur);
             i += di, j += dj)
            ++n;
    }
    return n;
}
