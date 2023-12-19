class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>m;
        int sum=0,cnt=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k) 
                cnt++;
            if(m[sum-k]){
                cnt+=m[sum-k];
            }
               m[sum]++;
        }
        return cnt;
    }
};