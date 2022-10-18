
/**
 *
 * @author fxowl97
 */
import java.io.DataInputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;

public class DaytimeClient {

    public static final int SERVICE_PORT = 13;

    public static void main(String[] args) {

        System.out.println("Warming up...");
        connectThreadedServer(10);

        System.out.println("Measuring performance...");
        connectThreadedServer(100);

    }

    public static void connectThreadedServer(int n) {

        double totalTime = 0, min = 0, max = 0;

        for (int i = 0; i < n; i++) {

            long timeStamp = System.nanoTime();

            try {

                Socket client = new Socket(InetAddress.getLocalHost(), SERVICE_PORT);

                DataInputStream in = new DataInputStream(client.getInputStream());
                in.readUTF();

                client.close();

            } catch (IOException e) {
                e.printStackTrace();
            }

            double timeTaken = (System.nanoTime() - timeStamp) / 1000000.0;

            if (max < timeTaken)
                max = timeTaken;

            if (min > timeTaken || min == 0)
                min = timeTaken;

            totalTime += timeTaken;

        }

        System.out.printf("Average time for %d requests is: %.2f ms\nminimum time is : %.2f ms\nMaximum time: %.2f ms\n\n", n,
                (totalTime / n), min, max);

    }

}
