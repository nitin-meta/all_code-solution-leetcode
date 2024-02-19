class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int inc = m, dec = n;
        for(auto it : ops){
            if(it[0] < inc)
                inc = it[0];
            if(it[1] < dec)
                dec = it[1];
        }
        return inc*dec;
    }
};