#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
class Auteur {
  private:
    string nom;
    bool prime;

  public:
    Auteur(string nom, bool prime = false) : nom(nom), prime(prime) {}
    Auteur(Auteur const &auteur)
        : nom(auteur.getNom()), prime(auteur.get_prix()) {}
    string getNom() const { return nom; }
    bool get_prix() const { return prime; }
};
class Oeuvre {
  private:
    string nom;
    Auteur auteur;
    string langue;

  public:
    Oeuvre(string nom, Auteur const &auteur, string langue)
        : nom(nom), auteur(auteur), langue(langue) {}
    ~Oeuvre() {
        std::cout << "L'oeuvre \"" << nom << ", " << auteur.getNom() << ", en "
                  << langue << "\" n'est plus disponible" << endl;
    }
    string getTitre() const { return nom; }
    Auteur const &getAuteur() const { return auteur; }
    string getLangue() const { return langue; }
    void affiche() const {
        std::cout << nom << ", " << auteur.getNom() << ", en " << langue
                  << endl;
    }
};

class Exemplaire {
  private:
    Oeuvre const &oeuvre;

  public:
    Exemplaire(Oeuvre const &oeuvre) : oeuvre(oeuvre) {
        std::cout << "Nouvel exemplaire de : " << oeuvre.getTitre() << ", "
                  << oeuvre.getAuteur().getNom() << ", en "
                  << oeuvre.getLangue() << endl;
    }
    ~Exemplaire() {
        std::cout << "Un exemplaire de \"" << oeuvre.getTitre() << ", "
                  << oeuvre.getAuteur().getNom() << ", en "
                  << oeuvre.getLangue() << "\" a été jeté ! " << endl;
    }
    Exemplaire(Exemplaire const &exemplaire) : oeuvre(exemplaire.oeuvre) {
        std::cout << "Copie d'un exemplaire de \"" << oeuvre.getTitre() << ", "
                  << oeuvre.getAuteur().getNom() << ", en "
                  << oeuvre.getLangue() << "\"" << endl;
    }
    Oeuvre const &getOeuvre() const { return oeuvre; }
};

class Bibliotheque {
  private:
    string nom;
    vector<Exemplaire *> exemplaires;

  public:
    Bibliotheque(string nom) : nom(nom) {
        std::cout << "La bibliothèque " << nom << " est ouverte ! " << endl;
    }
    ~Bibliotheque() {
        std::cout << "La bibliothèque " << nom
                  << " ferme ses portes, et détruit des exemplaires : " << endl;
        for (auto e : exemplaires)
            delete e;
    }
    string getNom() { return nom; }
    void stocker(Oeuvre const &oeuvre, int nb = 1) {
        for (int k = 0; k < nb; k++)
            exemplaires.push_back(new Exemplaire(oeuvre));
    }
    void lister_exemplaires(string langue) {
        for (auto e : exemplaires)
            if (langue == e->getOeuvre().getLangue())
                std::cout << "Exemplaire de : " << e->getOeuvre().getTitre()
                          << ", " << e->getOeuvre().getAuteur().getNom()
                          << ", en " << e->getOeuvre().getLangue() << endl;
    }
    void lister_exemplaires() {
        for (auto e : exemplaires)
            std::cout << "Exemplaire de : " << e->getOeuvre().getTitre() << ", "
                      << e->getOeuvre().getAuteur().getNom() << ", en "
                      << e->getOeuvre().getLangue() << endl;
    }
    void afficher_auteurs(bool prime = false) {
        for (auto e : exemplaires)
            if (prime && e->getOeuvre().getAuteur().get_prix())
                std::cout << e->getOeuvre().getAuteur().getNom() << endl;
            else if (prime == false)
                std::cout << e->getOeuvre().getAuteur().getNom() << endl;
    }
    int compter_exemplaires(Oeuvre const &oeuvre) {
        int compteur = 0;
        for (auto e : exemplaires)
            if (e->getOeuvre().getTitre() == oeuvre.getTitre()) {
                compteur++;
            }
        return compteur;
    }
};
/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main() {
    Auteur a1("Victor Hugo"), a2("Alexandre Dumas"),
        a3("Raymond Queneau", true);

    Oeuvre o1("Les Misérables", a1, "français"),
        o2("L'Homme qui rit", a1, "français"),
        o3("Le Comte de Monte-Cristo", a2, "français"),
        o4("Zazie dans le métro", a3, "français"),
        o5("The Count of Monte-Cristo", a2, "anglais");

    Bibliotheque biblio("municipale");
    biblio.stocker(o1, 2);
    biblio.stocker(o2);
    biblio.stocker(o3, 3);
    biblio.stocker(o4);
    biblio.stocker(o5);

    cout << "La bibliothèque " << biblio.getNom()
         << " offre les exemplaires suivants :" << endl;
    biblio.lister_exemplaires();

    const string langue("anglais");
    cout << " Les exemplaires en " << langue << " sont :" << endl;
    biblio.lister_exemplaires(langue);

    cout << " Les auteurs à succès sont :" << endl;
    biblio.afficher_auteurs(true);

    cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
         << o3.getTitre() << endl;

    return 0;
}