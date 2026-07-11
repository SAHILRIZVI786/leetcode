class Solution {
public:
    bool isPowerOfTwo(int n) {
    if(n==0) return false;
    if(((long long)n&-(long long)n)==(long long)n) return true;
    return false;
    }
};