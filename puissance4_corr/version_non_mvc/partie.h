
#include "jeu.h"
#include "joueur.h"
#include <array>
using namespace std;

/**
 * @brief modélise une partie, avec les joueurs participants, et le démarrage de la partie.
 **/
class Partie {
public:
  // ctor
  Partie(Joueur * j1, Joueur * j2, size_t taille = 8);
  // lance la partie
  void lancer();

private:
  Joueur * jcurr;    // le joueur dont c'est le tour
  Joueur * j1;
  Joueur * j2;
  Jeu jeu;
};

