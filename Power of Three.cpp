//Question Link : https://leetcode.com/problems/power-of-three/
//Question Name : 326. Power of Three
class Solution {
public:
    bool isPowerOfThree(int n) {
      if(n==0){
        return false;
    }
    
    while(n!=1){
        
        if(n%3!=0){
            return false;
        }
        
        n=n/3;
        
    }
    
    return true;  
}
    
};
