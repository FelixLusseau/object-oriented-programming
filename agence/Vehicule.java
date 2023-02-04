public class Vehicule {
    protected String marque;
    protected String modele;
    double prix_loc;

    public Vehicule(String marque, String modele, double prix_loc) {
        this.marque = marque;
        this.modele = modele;
        this.prix_loc = prix_loc;
    }

    public void afficher() {
        System.out.println("[Vehicule] marque : " + marque + ", modèle : " + modele
                + " (prix jour : " + prix_loc + " Eur)");
    }
}
