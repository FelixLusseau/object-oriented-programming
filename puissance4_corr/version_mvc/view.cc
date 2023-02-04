#include "view.h"
/// \cond
#include <iostream>
using namespace std;
/// \endcond

ostream & operator<<(ostream& out, JeuView const & view) {
  return view.affiche(out);
}

ostream& JeuView::affiche(ostream& out) const {
  string cross    = "\u254B";   // ╋
  string vert     = "\u2503";   // ┃
  string hori     = "\u2501";   // 
  string vert_r   = "\u2520";   // ┠
  string vert_l   = "\u252B";   // ┫

  if (model.get_taille() > 0) {
    size_t j(model.get_taille()-1);
    out << couleur_affiche; 
    do {
      cout << vert;
      for (size_t i(0); i < model.get_taille(); ++i) {
        switch (model.get_contents(i,j)) {
        case vide  : out << "   " << vert; break;
        case rouge : out << " " << ANSI_COLOR_RED << '#' << couleur_affiche << " " << vert; break;
        case jaune : out << " " << ANSI_COLOR_YELLOW << 'O' << couleur_affiche << " " << vert; break;
        }
      }
      out << endl;
    } while (j-- != 0);
    // bottom bar 
    cout << vert_r;
    for (size_t i(0); i <  model.get_taille()-1; ++i) 
      out << hori << hori << hori << cross;
    out << hori << hori << hori << vert_l << endl;
    // affichage numero lignes
    out << vert;
    for (size_t i(1); i <= model.get_taille(); ++i) 
        out << " " << i << " " << vert;
    out << endl;
  }
  out << ANSI_COLOR_RESET;
  return out;
}

