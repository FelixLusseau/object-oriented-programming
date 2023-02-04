import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.SocketException;
import java.net.ServerSocket;

public class ClientConnect implements Runnable {
    // attributes
    private Client cli_; // the client i'm looking after
    private Server myserver_; // the server i'm attached to
    private Socket sock; // the socket i'm listening on

    /**
     * @brief : constructor
     */
    // ...
    public ClientConnect(Client cli, Server myserver) {
        this.cli_ = cli;
        this.myserver_ = myserver;
        sock = cli.getSocket();
    }

    /**
     * @brief: handles a connected client, listening and managing
     *         its requests
     **/
    public void run() {
        System.err.println("Starting client management thread");

        // iterate on listening incoming connections
        // sock is of type Socket, and supposed to be opened to the client
        while (!sock.isClosed()) {
            try {
                // reads client's request
                String clientInput = read(sock);
                if (clientInput.equals("/hist")) {
                    myserver_.history(cli_);
                } else
                    myserver_.publish(cli_, clientInput);

            } catch (SocketException e) {
                System.err.println("Connection cut.");
                break;
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private String read(Socket sock) throws IOException {
        String response = "";
        int bytesRead;
        int MAX_MSG_LEN = 2048;
        BufferedInputStream reader = new BufferedInputStream(sock.getInputStream());
        byte[] buff = new byte[MAX_MSG_LEN];
        // Reads bytes into the specified byte array,
        // starting at the given offset.
        // Return -1 if the end of the stream is reached.
        bytesRead = reader.read(buff, 0, MAX_MSG_LEN);
        if (bytesRead != -1)
            response = new String(buff, 0, bytesRead);
        return response;
    }

}