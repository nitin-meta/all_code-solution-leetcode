class Solution {
public:
    const int M = 1e9+7;
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {

        ll ax = 0,bx = 0;
        for(long long i = 49; i >= n; i--) {
            int aset = (a >> i) & 1; 
            int bset = (b >> i) & 1;
            if(aset) ax ^= (1ll << i);
            if(bset) bx ^= (1ll << i);
        }
        
        for (long long i = n-1; i >= 0; i--) {
            int aset = (a >> i) & 1; 
            int bset = (b >> i) & 1;
            if(aset == bset) {
                ax ^= (1ll << i);
                bx ^= (1ll << i);
                continue;
            }
            
            if(ax>bx) bx ^= (1ll << i); 
            else ax ^= (1ll << i);
        }   

        ax%= M;
        bx%= M;
        return (ax*bx)%M;
    }
};