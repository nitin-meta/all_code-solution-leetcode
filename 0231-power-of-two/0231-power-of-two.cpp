class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return 0;
        else if((n&(n-1))==0) return 1;
        return 0;
    }
};