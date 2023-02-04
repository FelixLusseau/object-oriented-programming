public class Voiture extends Vehicule {
    private int nb_portes;

    public Voiture(String marque, String modele, double prix_loc, int nb_portes) {
        super(marque, modele, prix_loc);
        this.nb_portes = nb_portes;
        System.out.println("-> Voiture " + marque + " " + modele + " créée");
    }

    public void afficher() {
        System.out.println("[Voiture] marque : " + marque + ", modèle : " + modele
                + " (prix jour : " + prix_loc + " Eur (" + nb_portes
                + " portes)");
    }
}
