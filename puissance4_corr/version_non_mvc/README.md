
Exemple d'implémentation de puissance 4.

# Main

Le type de partie, à savoir les joueurs 1 et 2 sont ils des humains ou ordinateurs
et la couleur jouée est réglé dans `main.cc`:

~~~
int main()
{
  Partie p( new Humain(jaune) , new Machine(rouge) );
  p.lancer();
  return 0;
}
~~~

# Strategie

La stratégie déterminant le coup de l'ordinateur est fixée
dans la méthode `jouer` de la classe Machine. 
Dans cette méthode un objet `Strategie` est instanciée 
(le booléen n'est là que pour indiquer si il faut 
afficher la réflexion de l'ordinateur à des fins de mise au
point). L'objet Strategie fournit ensuite des méthodes
de jeu qui rendent toutes au final la colonne dans laquelle
l'ordinateur joue.

~~~
void Machine::jouer(Jeu& jeu) const {
      size_t colonne; // la colonne choisie
      Strategie s(false);  // active ou non l'affichage de debug
      colonne = s.strat_master(jeu,couleur);
      if (jeu.jouer(colonne, couleur)) {
            cout << jeu;
            cout << nom << " a joue en " << colonne+1 << endl;
            cerr << colonne+1 << endl;
      }
}
~~~

# Makefile

Un makefile est fourni. Il permet entre autre d'activer le symbole
DEBUG pour obtenir pour de traces lors de l'exécution.




