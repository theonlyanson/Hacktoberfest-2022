import java.util.*;
class stringbuffer
{
   public static void main(String args[])
   {
	String a;
	Scanner sc = new Scanner(System.in);
	System.out.println("Enter any String:");
	a=sc.next();
	StringBuffer str=new StringBuffer(a);
	System.out.println("original string:"+str);
	System.out.println("character at position 3 :"+str.charAt(2));
	System.out.println("Length of string:"+str.length());
	System.out.println("caopacity of String :"+str.capacity());
	System.out.println("appended string:"+str.append("markali"));
	System.out.println("Insert sub string:"+str.insert(2,"Hi"));
	System.out.println("Delete string:"+str.delete(2,3));
	System.out.println("Trimed string:"+str.reverse());
    }
}