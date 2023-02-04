#include <iostream>
#include <string>

#include "joueur.h"
#include "partie.h"

using namespace std;

int main() {
    Partie p(new Machine(rouge), new Humain(jaune));
    p.lancer();
    return 0;
}