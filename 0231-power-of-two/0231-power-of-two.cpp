class Solution {
public:
    bool isPowerOfTwo(int n) {
       long long int s=1;
      for(int i=0;s<=n;i++){
        if(s==n) return true;
        s=s*2;
      }  
      return false;
    }
};