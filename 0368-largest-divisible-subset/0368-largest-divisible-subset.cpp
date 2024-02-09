class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),prev_i(n,-1),res;
        //prev_i(n,-1);//to keep track of the past taken element
        int lastidx=0;//to keep track of ending subset element
        int maxL=-1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<1+dp[j]){
                        dp[i]=1+dp[j];
                        prev_i[i]=j;
                    }
                    if(maxL<dp[i]){
                        maxL=dp[i];
                        lastidx=i;
                    }
                }
            }
        }
        while(lastidx!=-1){
            res.push_back(nums[lastidx]);
            lastidx=prev_i[lastidx];
        }
        return res;
    }
};