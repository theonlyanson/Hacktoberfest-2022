import java.util.*;
class vector1
{
    public static void main(String args[])
    {
	Vector v1=new Vector();
	System.out.println("size of vector="+v1.size());
	System.out.println("size of vector="+v1.capacity());
        
        v1.addElement(10);
	v1.addElement(20);
	v1.addElement(30.5f);
	v1.addElement("Vikram");
	
	System.out.println(" after adding size of vector="+v1.size());
	System.out.println("after adding capacity of vector="+v1.capacity());
	System.out.println("Vector Elements are:"+v1);
	System.out.println("First Vector Element are:"+v1.firstElement());
	System.out.println("Last Vector Element are:"+v1.lastElement());
        v1.removeElement(30.5f);
	System.out.print("Vector Elements are:"+v1);
    }
}