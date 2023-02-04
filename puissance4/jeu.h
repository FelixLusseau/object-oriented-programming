#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <string>
#include <vector>

#include "couleur.h"

using namespace std;

class Jeu {
  protected:
    vector<vector<Couleur>> grille;
    string couleur_affiche;
    bool debug;

  public:
    Jeu(string couleur_affiche = ANSI_COLOR_RESET, size_t taille = 8)
        : grille(taille, vector<Couleur>(taille, vide)),
          couleur_affiche(couleur_affiche) {}
    Jeu(Jeu const &jorig);
    ~Jeu(){};

    int cherche_ligne(size_t i) {
        size_t j(0);
        while (grille[i][j] != vide)
            j++;
        if (j <= get_taille())
            return j;
        return -1;
    }
    bool jouer(size_t i, Couleur c) {
        if (c == vide) // empeche incoherence
            return false;
        if (i > get_taille() - 1) // empeche incoherence
            return false;
        ssize_t j = cherche_ligne(i);
        if (j == -1)
            return false;
        grille[i][j] = c;
        return true;
    }

    Couleur couleur_opposee(Couleur c) const {
        if (c == rouge)
            return jaune;
        else
            return rouge;
    }

    unsigned int compte(Couleur couleur, size_t i, size_t j, int di,
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

    Couleur gagnant() const {
        Couleur vainqueur(vide);
        for (size_t i(0); i < get_taille(); i++) {
            for (size_t j(0); j < get_taille(); j++) {
                if (grille[i][j] != vide) {
                    vainqueur = grille[i][j];
                    // teste dans les 5 directions possibles (+ (0,0) qui ne
                    // fait rien)
                    for (int di(0); di <= 1; ++di)
                        for (int dj(-1); dj <= 1; ++dj)
                            if (compte(vainqueur, i, j, di, dj) >= 4)
                                return vainqueur;
                }
            }
        }
        return vide;
    }

    bool fini(Couleur &resultat) const {
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

    size_t get_taille() const { return grille.size(); }
    ostream &affiche(ostream &out) const {
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
                        out << ANSI_COLOR_YELLOW << 'O' << couleur_affiche
                            << "|";
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
};

ostream &operator<<(ostream &out, const Jeu &jeu) { return jeu.affiche(out); }

#endif