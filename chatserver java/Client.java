import java.net.Socket;

public class Client {
    private String pseudo;
    private Socket sock;

    public Client(String pseudo, Socket sock) {
        this.pseudo = pseudo;
        this.sock = sock;
    }

    public Socket getSocket() {
        return sock;
    }

    public String getPseudo() {
        return pseudo;
    }
}
