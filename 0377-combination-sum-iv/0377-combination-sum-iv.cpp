class Solution {
public:
    int cnt;
    int memo[1001];
    int combSum4(int i,int target,int reqSum,vector<int>&nums){
        if(reqSum==target){            
            return 1;
        }
        if(i==nums.size()|| reqSum>target) return 0;
        int &cntRef=memo[reqSum];
        if(cntRef!=-1) return cntRef;
        //taking the elements
        reqSum+=nums[i];
        int ways=combSum4(0,target,reqSum,nums);//Restarted from beginning(thou giving TLE)
        reqSum-=nums[i];//Backtracking
        //Not Taking the elements
        ways+=combSum4(i+1,target,reqSum,nums);
        cntRef=ways;
        return ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(memo,-1,sizeof(memo));
        cnt=0;
        cnt+=combSum4(0,target,0,nums);
        return cnt;
    }
};