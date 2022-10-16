class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans=0;
        int mid=0;
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
         mid=s+(e-s)/2;
            if(mid==0){
                mid=1;
            }
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
               ans=mid;   
                break;
            }
              else if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1]){
               e=mid-1;               
            }
                else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1]){
               s=mid+1;               
            }
            
             mid=s+(e-s)/2;
            
        }
        return ans;
    }
};
