class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
       vector<bool>vis(n+1,false);
        for(auto it:nums){
            if(it<=0 || it>n) continue;
            vis[it]=true;
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==false) return i;
        }
        return n+1;
    }
};