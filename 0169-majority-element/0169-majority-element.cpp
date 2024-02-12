// Moore's Voting Algorithm for O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size(),cnt=1,cand=nums[0];
        for(int i=1;i<n;i++){
            if(cnt==0){
                cnt=1;
                cand=nums[i];
            }
            else if(nums[i]==cand) cnt++;
            else cnt--;
        }
        return cand;
    }
};