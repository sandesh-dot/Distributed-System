import java.io.*;
import java.net.*;

class cli {
    public static void main(String[] args) throws Exception {
        Socket sock = new Socket("localhost", 3000);
        BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));
        OutputStream ostream = sock.getOutputStream();
        PrintWriter pwrite = new PrintWriter(ostream, true);
        InputStream istream = sock.getInputStream();
        BufferedReader receiveRead = new BufferedReader(new InputStreamReader(istream));
        System.out.println("Client ready, type and press Enter key");
        String receiveMessage, sendMessage1, sendMessage2, sendMessage3, temp;
        // while(true)
        // {
        System.out.println("\nEnter operation to perform(add,sub,mul,div)....");
        temp = keyRead.readLine();
        sendMessage1 = temp.toLowerCase();

        System.out.println("Enter first parameter :");
        sendMessage2 = keyRead.readLine();

        System.out.println("Enter second parameter : ");
        sendMessage3 = keyRead.readLine();

        pwrite.println(sendMessage1);
        pwrite.println(sendMessage2);
        pwrite.println(sendMessage3);

        if ((receiveMessage = receiveRead.readLine()) != null)
            System.out.println(receiveMessage);
        // }
    }
}