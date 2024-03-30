class Solution {
public:
    int sliding_wind_temp(vector<int>&nums,int k){
        int n=nums.size(),i=0,j=0,cnt=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sliding_wind_temp(nums,k)-sliding_wind_temp(nums,k-1);
    }
};