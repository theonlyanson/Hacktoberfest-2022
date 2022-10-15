import java.util.Arrays;

// Time Complexity : O(n^2)

public class Selection_sort {
    public static void main(String[] args) {
        int[] arr = {23,78,56,98,13};

        for(int i=0;i<arr.length-1;i++){
            // min is index here
            int min=i;
            for(int j=i+1;j<arr.length;j++){
                if(arr[min]>arr[j]){
                    min=j;
                }
            }
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }

        System.out.println((Arrays.toString(arr)));
 
    }
}
