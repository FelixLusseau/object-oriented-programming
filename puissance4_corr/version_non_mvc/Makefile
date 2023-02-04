CC=g++
CFLAGS=--std=c++11 -Wall -g
DFLAGS=DEBUG

target : puissance4

puissance4 : main.cc jeu.o joueur.o partie.o strategie.o couleur.h
	$(CC) $(CFLAGS) main.cc jeu.o joueur.o partie.o strategie.o -o $@

partie.o : partie.h partie.cc jeu.h joueur.h couleur.h
	$(CC) $(CFLAGS) -c partie.cc

jeu.o : jeu.h jeu.cc couleur.h strategie.h
	$(CC) $(CFLAGS) -c jeu.cc

strategie.o : strategie.h strategie.cc couleur.h
	$(CC) $(CFLAGS) -c strategie.cc

joueur.o : joueur.h joueur.cc couleur.h
	$(CC) $(CFLAGS) -D$(DFLAGS) -c joueur.cc

clean:
	rm -rf *.dSYM *.o puissance4 *~


