#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ======================================================================
class Article {
  public:
    Article(string nom, double prix, bool en_solde = false)
        : nom(nom), prix(prix), en_solde(en_solde) {}
    string get_nom() { return nom; }
    double get_prix() { return prix; }
    string get_en_solde() {
        if (en_solde == true)
            return "   (en solde)";
        else
            return "";
    }

  private:
    string nom;
    double prix;
    bool en_solde;
};
class Achat {
  public:
    Achat(Article nom, int quantite) : article(nom), quantite(quantite) {}
    double cout() {
        if (article.get_en_solde() == "   (en solde)")
            return quantite * article.get_prix() / 2;
        else
            return quantite * article.get_prix();
    }
    void afficher() {
        std::cout << article.get_nom() << " : " << article.get_prix() << " x "
                  << quantite << " = " << cout() << " Eur"
                  << article.get_en_solde() << endl;
    }

  private:
    Article article;
    int quantite;
};
class Caddie {
  private:
    vector<Achat> les_achats;

  public:
    void remplir(Article nom, int quantite = 1) {
        les_achats.push_back(Achat(nom, quantite));
    }
    vector<Achat> caddie_get() { return les_achats; }
};
class Caisse {
  private:
    double montant;

  public:
    void scanner(Caddie caddie) {
        for (auto e : caddie.caddie_get()) {
            e.afficher();
            montant += e.cout();
        }
        std::cout << "-----" << endl
                  << "Total à payer : " << montant << " Eur." << endl;
    }
    void afficher() { std::cout << montant << " Eur"; }
};
// ======================================================================

int main() {
    // Les articles vendus dans le supermarché
    Article choufleur("Chou-fleur extra", 3.50);
    Article roman("Les malheurs de Sophie", 16.50, true);
    Article camembert("Cremeux 100%MG", 5.80);
    Article cdrom("C++ en trois jours", 48.50);
    Article boisson("Chocolats", 2.50, true);
    Article petitspois("Pois surgeles", 4.35);
    Article poisson("Sardines", 6.50);
    Article biscuits("Cookies de grand-mere", 3.20);
    Article poires("Poires Williams", 4.80);
    Article cafe("100% Arabica", 6.90, true);
    Article pain("Pain d'epautre", 6.90);

    // Les caddies du supermarché, disons 3 ici
    vector<Caddie> caddies(3);

    // Les caisses du supermarché, disons 2
    vector<Caisse> caisses(2);

    // Les clients font leurs achats :
    // le second argument de la méthode remplir correspond à une quantité

    // remplissage du 1er caddie
    caddies[0].remplir(choufleur, 2);
    caddies[0].remplir(cdrom);
    caddies[0].remplir(biscuits, 4);
    caddies[0].remplir(boisson, 6);
    caddies[0].remplir(poisson, 2);

    // remplissage du 2eme caddie
    caddies[1].remplir(roman);
    caddies[1].remplir(camembert);
    caddies[1].remplir(petitspois, 2);
    caddies[1].remplir(poires, 2);

    // remplissage du 3eme caddie
    caddies[2].remplir(cafe, 2);
    caddies[2].remplir(pain);
    caddies[2].remplir(camembert, 2);

    // Les clients passent à la caisse :
    caisses[0].scanner(caddies[0]);
    cout << "=========================================" << endl;
    caisses[0].scanner(caddies[1]);
    cout << "=========================================" << endl;
    caisses[1].scanner(caddies[2]);
    cout << "=========================================" << endl;

    // Affichage du résultat des caisses
    cout << "Résultats du jour :" << endl;
    for (size_t i(0); i < caisses.size(); ++i) {
        cout << "Caisse " << i + 1 << " : ";
        caisses[i].afficher();
        cout << endl;
    }
    return 0;
}