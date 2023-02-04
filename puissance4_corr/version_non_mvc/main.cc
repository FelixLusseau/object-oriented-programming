
#include "joueur.h" 
#include "partie.h"

int main()
{
  Partie p( new Humain(jaune) , new Machine(rouge) );
  p.lancer();
  return 0;
}
