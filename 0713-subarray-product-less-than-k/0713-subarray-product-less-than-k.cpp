class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int head=0,tail=0,ans=0,prod=1;
        if(k<=1) return 0;// edge case to think of looking at example-2
        //what if k=0, does it makes any sense??\U0001f914\U0001f914
        for(head=0;head<size(nums);head++){
            prod*=nums[head];
            while(prod>=k){
                prod/=nums[tail];
                tail++;
            }
            ans+=head-tail+1;
        }
        return ans;
    }
};