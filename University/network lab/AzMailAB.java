import java.io.*;
import java.net.*;
import java.util.*;
import javax.net.ssl.*;

class AzMailAB {

    private static DataOutputStream dos;
    public static BufferedReader br;

    public static void main(String argv[]) throws Exception {

        String user = "s2310876111@ru.ac.bd";

        // Google App Password
        String pass = "uknhkyewiaamcfsu";


        // =========================================================
        // BASE64 ENCODE USERNAME AND PASSWORD
        // =========================================================

        String username = new String(
                Base64.getEncoder().encode(user.getBytes())
        );

        String password = new String(
                Base64.getEncoder().encode(pass.getBytes())
        );


        // =========================================================
        // CONNECT TO GMAIL SMTP SERVER
        // =========================================================

        System.out.println("Connecting to Gmail SMTP server...");

        SSLSocket s = (SSLSocket) SSLSocketFactory
                .getDefault()
                .createSocket("smtp.gmail.com", 465);

        // Prevent the program from waiting forever
        s.setSoTimeout(10000);

        dos = new DataOutputStream(s.getOutputStream());

        br = new BufferedReader(
                new InputStreamReader(s.getInputStream())
        );


        // =========================================================
        // AUTOMATICALLY GET MAC ADDRESS
        // =========================================================

        String macAddress = getMacAddress(s.getLocalAddress());

        System.out.println("MAC Address: " + macAddress);


        // =========================================================
        // SMTP SERVER GREETING
        // =========================================================

        readResponse();

        send("EHLO smtp.gmail.com\r\n");
        readResponse();


        // =========================================================
        // AUTHENTICATION
        // =========================================================

        send("AUTH LOGIN\r\n");
        readResponse();

        // Send username
        send(username + "\r\n");
        readResponse();

        // Send App Password
        send(password + "\r\n");

        int authCode = readResponse();


        // =========================================================
        // CHECK AUTHENTICATION
        // =========================================================

        if (authCode != 235) {

            System.out.println();
            System.out.println("Authentication failed!");
            System.out.println("Please check your Gmail/App Password.");
            System.out.println();

            send("QUIT\r\n");

            br.close();
            dos.close();
            s.close();

            return;
        }


        System.out.println();
        System.out.println("Authentication successful!");
        System.out.println();


        // =========================================================
        // MAIL FROM
        // =========================================================

        send("MAIL FROM:<" + user + ">\r\n");
        int mailFromCode = readResponse();

        if (mailFromCode != 250) {
            System.out.println("MAIL FROM failed.");
            return;
        }


        // =========================================================
        // RECIPIENT / SIR'S EMAIL
        // =========================================================

        String receiver = "mahmudulhasanmasum666@gmail.com";

        send("RCPT TO:<" + receiver + ">\r\n");
        int recipientCode = readResponse();

        if (recipientCode != 250 && recipientCode != 251) {
            System.out.println("Recipient rejected.");
            return;
        }


        // =========================================================
        // START EMAIL DATA
        // =========================================================

        send("DATA\r\n");
        int dataCode = readResponse();

        if (dataCode != 354) {
            System.out.println("DATA command failed.");
            return;
        }


        // =========================================================
        // EMAIL HEADER
        // =========================================================

        send("FROM: " + user + "\r\n");
        send("TO: " + receiver + "\r\n");
        send("Subject: TestMail\r\n");

        // Blank line separates header and body
        send("\r\n");


        // =========================================================
        // EMAIL BODY
        // =========================================================

        send("name: mahamudul hasan Masum\r\n");
        send("ID: 2310876111\r\n");
        send("MAC Address: " + macAddress + "\r\n");


        // =========================================================
        // END OF EMAIL
        // =========================================================

        send(".\r\n");

        int mailCode = readResponse();


        // =========================================================
        // CHECK EMAIL STATUS
        // =========================================================

        if (mailCode == 250) {

            System.out.println();
            System.out.println("======================================");
            System.out.println("Email sent successfully!");
            System.out.println("======================================");
            System.out.println();

        } else {

            System.out.println();
            System.out.println("Email was NOT sent.");
            System.out.println();
        }


        // =========================================================
        // CLOSE SMTP CONNECTION
        // =========================================================

        send("QUIT\r\n");
        readResponse();

        br.close();
        dos.close();
        s.close();
    }


    // =============================================================
    // METHOD 1: SEND SMTP COMMAND
    // =============================================================

    private static void send(String message) throws Exception {

        dos.writeBytes(message);
        dos.flush();

        System.out.println("CLIENT: " + message.trim());

        Thread.sleep(500);
    }


    // =============================================================
    // METHOD 2: READ SMTP SERVER RESPONSE
    // =============================================================

    private static int readResponse() throws Exception {

        String line;
        int responseCode = -1;

        while ((line = br.readLine()) != null) {

            System.out.println("SERVER: " + line);

            // Get SMTP response code
            if (line.length() >= 3) {

                try {
                    responseCode = Integer.parseInt(
                            line.substring(0, 3)
                    );
                } catch (NumberFormatException e) {
                    responseCode = -1;
                }
            }

            // SMTP multiline response ends
            // when the 4th character is a space
            if (line.length() >= 4 && line.charAt(3) == ' ') {
                break;
            }
        }

        return responseCode;
    }


    // =============================================================
    // METHOD 3: AUTOMATICALLY GET MAC ADDRESS
    // =============================================================

    private static String getMacAddress(InetAddress localAddress)
            throws Exception {

        // Find the network interface used by this connection
        NetworkInterface networkInterface =
                NetworkInterface.getByInetAddress(localAddress);

        if (networkInterface == null) {
            return "MAC Address Not Found";
        }

        byte[] mac = networkInterface.getHardwareAddress();

        if (mac == null) {
            return "MAC Address Not Found";
        }

        StringBuilder macAddress = new StringBuilder();

        for (int i = 0; i < mac.length; i++) {

            macAddress.append(
                    String.format(
                            "%02X%s",
                            mac[i],
                            (i < mac.length - 1) ? ":" : ""
                    )
            );
        }

        return macAddress.toString();
    }
}