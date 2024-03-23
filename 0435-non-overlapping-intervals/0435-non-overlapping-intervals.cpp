class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n= intervals.size();
        sort(intervals.begin(),intervals.end());
        int i=0,j=1,cnt=0;
        while(j<n){
            auto itx=intervals[i];
            auto ity=intervals[j];
            int ps=itx[0],pe=itx[1];
            int cs=ity[0],ce=ity[1];
            if(pe<=cs)i=j,j++;
            else if(pe>ce){
                i=j,j++;
                cnt++;
            }
            else if(ce>=pe){
                j++;
                cnt++;
            }
        }
        return cnt;
    }
};