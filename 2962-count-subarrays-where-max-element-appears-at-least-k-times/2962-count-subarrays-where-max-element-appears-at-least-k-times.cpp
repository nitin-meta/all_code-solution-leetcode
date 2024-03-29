class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        long long high=0,low=0,cntMax=0,res=0;
        int maxE=*max_element(nums.begin(),nums.end());
        for(;high<n;high++){
            if(nums[high]==maxE){
                cntMax++;
            }
            while(cntMax>=k){
                res+=(n-high);
                if(nums[low]==maxE){
                    cntMax--;
                }
                low++;
            }
        }
        return res;
    }
};