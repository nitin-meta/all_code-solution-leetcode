class Solution {
public:
     void combsum1(int i,int target,int reqSum,vector<int>&arr,vector<int>&subset,vector<vector<int>>&ans){
        if(reqSum==target){
            ans.push_back(subset);
            return;
        }
        if(reqSum>target) return ;
        if(i>=arr.size()) return;
        //Picking
        reqSum+=arr[i];
        subset.push_back(arr[i]);
        combsum1(i+1,target,reqSum,arr,subset,ans);
        reqSum-=arr[i];
        subset.pop_back();
        //Not Picking
        while(i+1<arr.size() && arr[i]==arr[i+1]) i++;
        combsum1(i+1,target,reqSum,arr,subset,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int>subset;
        int reqSum=0;
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        combsum1(0,target,reqSum,arr,subset,ans);
        return ans;
    }
};