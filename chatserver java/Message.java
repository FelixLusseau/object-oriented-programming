import java.time.LocalDateTime;

public class Message {
    private Client cli;
    private String mesg;
    private LocalDateTime date;

    public Message(Client cli, String mesg) {
        this.cli = cli;
        this.mesg = mesg;
        date = LocalDateTime.now();
    }

    public Client getClient() {
        return cli;
    }

    public String to_string() {
        return mesg;
    }

    public LocalDateTime getDate() {
        return date;
    }
}
