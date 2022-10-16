import java.util.Arrays;

public class Insertion_sort {
    public static void main(String[] args) {
        int[] arr = {23,78,56,98,13};

        for(int i=1;i<arr.length;i++){
            int current=arr[i];
            int j=i-1;
            while(j>=0 && current<arr[j]){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=current;
        }
 
        System.out.println((Arrays.toString(arr)));

    }
}
