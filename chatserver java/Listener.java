import java.net.Socket;
import java.io.IOException;
import java.io.BufferedInputStream;

public class Listener implements Runnable {
    private Server server;
    private boolean isRunning;
    private Socket sockclient;

    private final int MAX_PSEUDO_LEN = 20;

    private String headerRead(Socket sock) throws IOException {
        BufferedInputStream reader = new BufferedInputStream(sock.getInputStream());
        String pseudo = "";
        int stream;
        byte[] b = new byte[MAX_PSEUDO_LEN];
        stream = reader.read(b, 0, MAX_PSEUDO_LEN);
        pseudo = new String(b, 0, stream);
        return pseudo.trim();
    }

    public Listener(Server server) {
        this.server = server;
        this.isRunning = true;
    }

    public void run() {
        while (isRunning == true) { // should probably stay always true
            System.out.println("* Listener opened.");
            try {
                // Wait for an incoming client connection
                Socket sockclient = server.getServerSocket().accept();
                System.out.println("Client connects.");
                // ok, we have a socket for that client.
                // Read what it sent to me as a header (I expect its pseudo as first string)
                String pseudo = headerRead(sockclient);
                // and create one Client, register it on the server.
                Client cli = new Client(pseudo, sockclient);
                server.register(cli);
                // Create a thread to handle client requests
                // Pass the client object and myself as server attached to this client
                Thread t = new Thread(new ClientConnect(cli, server));
                t.start();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        try {
            server.getServerSocket().close();
        } catch (IOException e) {
            e.printStackTrace();
            server = null;
        }
    } // end void run()
}
