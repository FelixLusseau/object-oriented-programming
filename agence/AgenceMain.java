import java.util.Vector;

public class AgenceMain {

    public static void main(String args[]) {
        Agence malocation = new Agence("MaLocation");

        Vector<Utilitaire> utilitaires = new Vector<Utilitaire>();
        // constructeur marque,modele,cubage,prix
        utilitaires.add(new Utilitaire("Mercedes", "Vito", 50., 9.));
        utilitaires.add(new Utilitaire("Peugeot", "Master", 45., 9.));
        utilitaires.add(new Utilitaire("Renault", "Kangoo", 35., 4.));

        Vector<Voiture> voitures = new Vector<Voiture>();
        // constructeur marque,modele,portes,prix
        voitures.add(new Voiture("Peugeot", "207", 25., 5));
        voitures.add(new Voiture("Renault", "Clio", 25., 3));

        for (Utilitaire u : utilitaires)
            malocation.ajouter_flotte(u);
        for (Voiture v : voitures)
            malocation.ajouter_flotte(v);
        malocation.afficher_flotte();
    }
}
