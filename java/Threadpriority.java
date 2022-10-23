class thread1 extends Thread
{
   public void run()
   {
	System.out.println("Minimum priority thread");
   }
}
class thread2 extends Thread
{
   public void run()
   {
	System.out.println("normal priority thread");
   }
}
class thread3 extends Thread
{
   public void run()
   {
	System.out.println("Maximum priority thread");
   }
}

class Threadpriority
{
     public static void main(String args[])
     {
      thread1 t1=new thread1();
      thread2 t2=new thread2();
      thread3 t3=new thread3();

      t1.setPriority(Thread.MIN_PRIORITY);
      t2.setPriority(Thread.NORM_PRIORITY);
      t3.setPriority(Thread.MAX_PRIORITY);

      t1.start();
      t2.start();
      t3.start();
     }
} 