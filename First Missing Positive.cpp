class Solution {
public:
   int firstMissingPositive(vector<int> a) {
    
    int i,n=a.size();
    for(i=0;i<n;i++)
        if(a[i]<=0 || a[i]>n)
            a[i] = INT_MAX;

    a.push_back(INT_MAX);
    for(i=0;i<n;i++)
    {
        if(abs(a[i])==INT_MAX) continue;
        
        if(a[abs(a[i])]>0)
            a[abs(a[i])] *= -1;
    }
    for(i=1;i<=n;i++)
        if(a[i]>0)
            break;
    
    return i;
}
};
