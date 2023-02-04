public class ChatServer {

    public static void main(String[] args) {
        Server serv;

        if (args.length == 1) {
            try {
                int portRequested = Integer.parseInt(args[0]);
                serv = new Server(portRequested);
            } catch (NumberFormatException e) {
                System.err.println("* Error bad port number. Switching to default port");
                serv = new Server();
            }
        } else
            serv = new Server();
    }
}
