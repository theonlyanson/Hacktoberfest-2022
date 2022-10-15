import java.util.Scanner;

public class Username
{
    public static void main (String [] args){
    Scanner sc=new Scanner(System.in);
    
    System.out.println("Welcome to the Username Creator! Enter your full name.");
    
    String fullName = sc.nextLine();
    int spot= fullName.indexOf(" ");
    String fName = fullName.substring(0, spot);
    
        fullName= fullName.substring(spot + 1); // James Edward Silvi
       spot = fullName.indexOf(" ");
       String mName= "";
       String lName="";
       
       if(spot>0){
        
        mName = fullName.substring(0,spot);
         mName = mName.substring(0,1);
         lName= fullName.substring(spot+1);
        
        }else{
           lName= fullName;
            
        
        }
       
        
       String username = lName.substring(0,4);
       
       int length = lName.length();
       
       
       if(lName.length()<4){
        
         lName = lName.substring(0,4);
        
        }else{
            lName = lName.substring(0, lName.length()); 
        }
       
       
       fName = fName.substring(0,1);
      
       lName = lName.substring(0,4);
       
       System.out.println("Now enter your Graduation year.");
    
    String gradYear = sc.nextLine();
    
    String gYear = gradYear.substring(2,4);
    
    System.out.println(lName + fName + mName + gYear);
    
  }
}
