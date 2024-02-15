class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long sum=0,ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]<sum){
                ans=sum+nums[i];
            }
            sum+=nums[i];
        }
        return ans==0?-1:ans;
    }
};