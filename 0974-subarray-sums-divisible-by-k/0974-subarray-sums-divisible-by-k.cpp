class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int pre=0,cnt=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            pre+=nums[i];
            int mod=pre%k;
            if(mod<0) mod+=k;
            if(mod==0) cnt++;
            if(m[mod]) cnt+=m[mod];
            m[mod]++;            
        }
        return cnt;
    }
};