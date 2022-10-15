import java.util.Arrays;
import java.util.Scanner;

public class Binary_search {
    public static void main(String[] args) {
      
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] arr = new int[N];
        for(int i=0;i<N;i++){
            arr[i]=i;
        }
        System.out.println(Arrays.toString(arr));

        System.out.println("Enter a key");
        int key = sc.nextInt();

        int low = 0;
        int high = N-1;
        int flag=0;

        while(low<=high){
            int mid=(low+high)/2;
            if (arr[mid]==key) {
                flag=1;
                break;
            }else{
                if(arr[mid]<key){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }

        if(flag==1){
            System.out.println("Key is found");
        }

    }
}
