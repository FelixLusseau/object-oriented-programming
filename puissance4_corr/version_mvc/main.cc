
#include "couleur.h"
#include "model.h"
#include "view.h"
#include "controller.h"
#include "joueur.h" 

int main() {

  JeuModel model(8);  // default is size 8x8

  Humain  j1(model);
  Machine j2(model);

  JeuView view(model);
  JeuController controller(j1,j2,model,view);
  
  controller.lancer();
  return 0;
}
