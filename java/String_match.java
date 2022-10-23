import java.util.*;
 class NotMatchException extends Exception 
{
 public NotMatchException(String str2) 
  {
   System.out.println(str2);     
  }   
}
public class String_match
{
  public static void main(String args[]) 
  {
   Scanner sc = new Scanner(System.in);
  System.out.print("Enter a STRING : ");
  String str1  = sc.next();
  try 
   {
   if(str1.equals("India"))
    System.out.println("String matched !!!");
   else
    throw new NotMatchException("String not matched ???");     
   }
  catch (NotMatchException e) 
   {
   System.out.println(e);    
   }    
  }    
}
