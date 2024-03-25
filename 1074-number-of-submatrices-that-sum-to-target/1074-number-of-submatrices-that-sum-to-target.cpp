//Same question like subarray sum equals k(LC:560)
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int rows=mat.size(),cols=mat[0].size();
        //computed the cumulative sum in row-wise manner
        for(int row=0;row<rows;row++){
            for(int col=1;col<cols;col++){
                mat[row][col]+=mat[row][col-1];
            }
        }
        //Going parallely in column wise and checking same in map if present then add up and while moving to next col, we have to subtract the cumulative sum from previous starting column
        int cnt=0;
        for(int sc=0;sc<cols;sc++){
            for(int j=sc;j<cols;j++){
                unordered_map<int,int>mp;
                mp[0]=1;
                int sum=0;
                for(int row=0;row<rows;row++){
                    sum+=mat[row][j]-(sc>0?mat[row][sc-1]:0);
                    if(mp.find(sum-target)!=mp.end()){
                        cnt+=mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }
        return cnt;
    }
};