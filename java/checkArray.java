/brute force
import java.util.*;

class checkArray {

    static int compare(int arr[], int arr1[]) {
        int j = 0;
        for (int i = 0; i < arr1.length; i++) {
            for (j = 0; j < arr.length; j++) {
                if (arr1[i] == arr[j]) {
                    break;
                }

            }
            if (j == arr.length)
                return 0;

        }
        return 1;

    }

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int arr1[] = { 12, 7, 9 };
        int arr[] = { 3, 5, 7, 8, 9, 12 };
        int d = compare(arr, arr1);
        System.out.println(d);
    }
}
