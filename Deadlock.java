

import static deadlock.Deadlock.lock1;
import static deadlock.Deadlock.lock2;

/**
 *
 * @author Lakshitha Samod
 */
public class Deadlock {

    public static String lock1 = "Sam";
    public static String lock2 = "Kamal";

    public static void main(String[] args) {
        Thread1 t1 = new Thread1();
        t1.start();
        
        Thread2 t2 = new Thread2();
        t2.start();
                

    }

}


    class Thread1 extends Thread {

        @Override
        public void run() {
            System.out.println("start executing thread 1");
            synchronized (lock1) {
                System.out.println("Thread 1 holding lock 1...");
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException ex) {

                }
                System.out.println("thread 1 is waiting for the lock 2");

                synchronized (lock2) {
                    System.out.println("Thread 1 holding lock 1 and lock 2...");
                }

            }

        }
    }

    class Thread2 extends Thread {

        @Override
        public void run() {
            System.out.println("start executing thread 2");
            synchronized (lock2) {
                System.out.println("Thread 2 holding lock 2...");
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException ex) {

                }
                System.out.println("thread 2 is waiting for the lock 1");

                synchronized (lock1) {
                    System.out.println("Thread 2 holding lock 1 and lock 2...");
                }

            }
        }
    }
