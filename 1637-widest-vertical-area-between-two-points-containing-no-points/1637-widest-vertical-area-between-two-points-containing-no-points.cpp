class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n=points.size(),res=0;
        sort(points.begin(),points.end());
        for(int i=1;i<n;i++){
            int width=points[i][0]-points[i-1][0];
            res=max(res,width);
        }
        return res;
    }
};