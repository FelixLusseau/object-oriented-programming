#include "jeu.h"
#include "couleur.h"
#include <cstdlib> // pour rand()
#include <ctime>

/**
 * constructor
 **/
Jeu::Jeu(string couleur_affiche, size_t taille)
    : grille(taille, vector<Couleur>(taille)),
      couleur_affiche(couleur_affiche) {
    srand((unsigned)time(0)); // initialise la graine aleatoire
}

Jeu::~Jeu() {}

Jeu::Jeu(Jeu const &jorig)
    : grille(jorig.grille), couleur_affiche(ANSI_COLOR_GREEN) {}
/**
 * rend le numéro de ligne où tombe le pion sur cette colonne,
 * -1 si la colonne est pleine.
 * @param i le numero de colonne
 **/
int Jeu::cherche_ligne(size_t i) {
    size_t j(0);
    while (grille[i][j] != vide)
        j++;
    if (j <= get_taille())
        return j;
    return -1;
}
/**
 * jouer : pose d'un pion de couleur c en colonne i.
 * Si la pose est valide, la grille est modifiée
 * @param i la colonne où est posée le pion
 * @param c la couleur du pion
 * @return vrai si pose valide, faux sinon
 **/
bool Jeu::jouer(size_t i, Couleur c) {
    if (c == vide) // empeche incoherence
        return false;
    if (i > get_taille()) // empeche incoherence
        return false;
    int j = Jeu::cherche_ligne(i);
    if (j == -1)
        return false;
    grille[i][j] = c;
    return true;
}

// ------------------------------------------------------------
bool Jeu::fini(Couleur &resultat) const {
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
Couleur Jeu::gagnant() const {
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
unsigned int Jeu::compte(Couleur couleur, size_t i, size_t j, int di,
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
// ------------------------------------------------------------
ostream &operator<<(ostream &out, const Jeu &jeu) { return jeu.affiche(out); }
ostream &Jeu::affiche(ostream &out) const {
    if (get_taille() > 0) {
        size_t j(get_taille() - 1);
        out << couleur_affiche;
        do {
            out << "|";
            for (size_t i(0); i < get_taille(); ++i) {
                switch (grille[i][j]) {
                case vide:
                    out << " |";
                    break;
                case rouge:
                    out << ANSI_COLOR_RED << '#' << couleur_affiche << "|";
                    break;
                case jaune:
                    out << ANSI_COLOR_YELLOW << 'O' << couleur_affiche << "|";
                    break;
                }
            }
            out << endl;
        } while (j-- != 0);
        out << "+";
        for (size_t i(0); i < get_taille(); ++i)
            out << "-+";
        out << endl;
        // affichage numero lignes
        cout << "|";
        for (size_t i(1); i <= get_taille(); ++i)
            out << i << "|";
        out << endl;
    }
    out << ANSI_COLOR_RESET;
    return out;
}
