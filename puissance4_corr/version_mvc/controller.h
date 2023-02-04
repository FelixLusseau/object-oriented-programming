#include "model.h"
#include "view.h"
#include "joueur.h"
/// \cond
#include <string>
#include <vector>
/// \endcond



/**
 * @brief Classe qui 
 *  - coordonne la logique du jeu 
 *  - et met à jour l'état du jeu en faisant appel aux méthodes du Model
 **/
class JeuController {
public:
  /**
   * @brief constructeur par défaut initialisant
   *        - les joueurs
   *        - le model, pour obtenir des méthodes d'accès aux données
   *        - la vue, pour obtenir une methode 
   **/
  JeuController(Joueur & j1, Joueur & j2, JeuModel & model, JeuView & view);
  
  ~JeuController();
  
  void lancer();

  
// ---------- attributs ------------

private:
  // @brief le stockage de la grille de jeu.
  std::vector< std::vector< Couleur > > grille;
  // @brief la couleur d'affichage du jeu à l'écran.
  std::string couleur_affiche;  

  Joueur & j1;
  Joueur & j2;
  Joueur * jcurr;

  JeuModel & model;
  JeuView  & view;
};
