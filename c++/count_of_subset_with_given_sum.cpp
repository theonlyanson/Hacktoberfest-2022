#include <bits/stdc++.h>
using namespace std;

// 1st Method :-  By recursion

int subset_rec(int arr[],int size,int sum)
{
    if(sum==0)
        return 1;
    if(size==0)
        return 0;
    if(arr[size-1]<=sum)
        return subset_rec(arr,size-1,sum-arr[size-1]) + subset_rec(arr,size-1,sum);
    else 
        return subset_rec(arr,size-1,sum);
}

// 2nd Method:- By recursion + Memoization

int subset_rec_mem(int arr[],int size,int sum,vector<vector<int>> t)
{
    if(sum==0)
        return true;
    if(size==0)
        return false;
    if(t[size][sum]!=-1)
        return t[size][sum];
    
    if(arr[size-1]<=sum)
        return t[size][sum] = subset_rec(arr,size-1,sum-arr[size-1]) + subset_rec(arr,size-1,sum);
    else 
        return t[size][sum] = subset_rec(arr,size-1,sum);
}


// 3rd Method :- BY DP

int subset_dp(int arr[],int size,int sum)
{
    int dp[size + 1][sum + 1];
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= size; i++)
        dp[i][0] = 1;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;
 
    // Fill the subset table in bottom up manner
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1]<=j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
 
       // uncomment this code to print table
     for (int i = 0; i <= size; i++)
     {
        for (int j = 0; j <= sum; j++){
            cout<<" "<<dp[i][j]<<" ";
        }
        cout<<endl;
     }
 
    return dp[size][sum];
}


int main(){
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);

    int arr[]={2,3,5,6,8,10};
    int size=sizeof(arr)/sizeof(arr[0]);

    int sum=10;

    cout<<"Answer by recursion = "<<subset_rec(arr,size,sum)<<endl;       // by recursion

    vector<vector<int>> t(size+1, vector<int> (sum+1,-1));
    cout<<"Answer by recursion + memoization = "<<subset_rec_mem(arr,size,sum,t)<<endl;       // by recursion + memoization

    cout<<"Answer by DP = "<<subset_dp(arr,size,sum)<<endl;       // by DP

    
return 0;
}