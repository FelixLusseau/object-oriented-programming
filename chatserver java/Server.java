import java.io.IOException;
import java.io.BufferedInputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.*;
import java.time.LocalDateTime;

public class Server {
    private Vector<Client> clients;
    private Vector<Message> messages;
    private int port;
    private ServerSocket serverSock;

    private void send(LocalDateTime date, String pseudo, Socket sock, String message) {
        try {
            PrintWriter writer = new PrintWriter(sock.getOutputStream());
            writer.write(date + " : [" + pseudo + "] " + message);
            writer.flush();
        } catch (IOException e) {
            System.err.println("* Error trying to reach " + pseudo + " to send a message.");
        }
    }

    public Server(int port) {
        this.port = port;
        clients = new Vector<Client>();
        messages = new Vector<Message>();
        try {
            serverSock = new ServerSocket(port);
        } catch (IOException e) {
            System.err.println("* Error creating server socket.");
        }
        Listener listener = new Listener(this);
        Thread t = new Thread(listener);
        t.start();
    }

    public Server() {
        this.port = 3100;
        clients = new Vector<Client>();
        messages = new Vector<Message>();
        try {
            serverSock = new ServerSocket(port);
            System.out.println("* Server socket opened.");
        } catch (IOException e) {
            System.err.println("* Error creating server socket.");
        }
        Listener listener = new Listener(this);
        Thread t = new Thread(listener);
        t.start();
    }

    public void publish(Client cli, String str) {
        Message message = new Message(cli, str);
        messages.add(message);
        for (Client client : clients) {
            send(message.getDate(), cli.getPseudo(), client.getSocket(), message.to_string());
        }
    }

    public void history(Client cli) {
        for (Message message : messages) {
            send(message.getDate(), cli.getPseudo(), cli.getSocket(), message.to_string());
        }
    }

    public void register(Client cli) {
        clients.add(cli);
        System.out.println("* " + cli.getPseudo() + " is now connected.");
    }

    public void unregister(Client cli) {
        clients.remove(cli);
    }

    public ServerSocket getServerSocket() {
        return serverSock;
    }
}
