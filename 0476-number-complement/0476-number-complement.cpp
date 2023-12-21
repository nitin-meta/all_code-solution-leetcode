class Solution {
public:
    int findComplement(int n) {
        int m = n;
        int bit = 0;
        
        if(n == 0)
            return 1;
        
        while(m)
        {
            bit = (bit << 1) | 1;
            m = m >> 1;        
        }
        return (~n) & bit;
    }
};