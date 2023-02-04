public class Utilitaire extends Vehicule {
    private double cubage;

    public Utilitaire(String marque, String modele, double cubage, double prix_loc) {
        super(marque, modele, prix_loc);
        this.cubage = cubage;
        System.out.println("-> Utilitaire " + marque + " " + modele + " créé");
    }

    public void afficher() {
        System.out.println("[Utilitaire] marque : " + marque + ", modèle : " + modele
                + " (prix jour : " + prix_loc + " Eur (" + cubage + " m3)");
    }
}
