CC=g++
DFLAGS=DEBUG 
CFLAGS=--std=c++11 -Wall -g $(DEBUG)

target : puissance4

puissance4 : main.cc  joueur.o controller.o model.o view.o strategie.o couleur.h
	$(CC) $(CFLAGS) main.cc  joueur.o controller.o model.o view.o strategie.o -o $@

controller.o : controller.cc controller.h model.h view.h  joueur.h couleur.h
	$(CC) $(CFLAGS) -c controller.cc

model.o : model.cc model.h  joueur.h couleur.h
	$(CC) $(CFLAGS) -D$(DFLAGS) -c $<

view.o : view.cc view.h model.h joueur.h couleur.h
	$(CC) $(CFLAGS) -c $<

strategie.o : strategie.cc strategie.h couleur.h
	$(CC) $(CFLAGS) -D$(DFLAGS) -c $<

joueur.o : joueur.cc joueur.h couleur.h
	$(CC) $(CFLAGS) -D$(DFLAGS) -c $<

doc:
	doxygen config

clean:
	rm -rf *.dSYM *.o puissance4 *~


