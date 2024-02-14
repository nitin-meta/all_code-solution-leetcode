class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size(),i=1,j=1;//strictly increasing hoga to till i badhega else j aur fir max len till of (i,j)
        for(int k=1;k<n;k++){
            if(nums[k]>nums[k-1]){
                i=j+1;
            }
            else if(nums[k]<nums[k-1]) //both condition should be checked 
                j=i+1;
        }
        return max(i,j);
    }
};
