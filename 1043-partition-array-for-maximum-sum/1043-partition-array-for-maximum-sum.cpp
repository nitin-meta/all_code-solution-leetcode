class Solution {
public:
    //Partition Problem me kya karna hai ki i=0 se shuruwat karna hai fir ek loop chalana hai j=i se codition tak, aur iss case  me kya hua ki mujhe atmost k partition karna hai, aur fir sabme se jo maximum aaye wo return karna hai
    int memo[501];
    int partitionSum(int i, vector<int>&arr,int k){
        if(i>=arr.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        int cur_sum=0,res=0;
        for(int j=i;j<arr.size()&& j-i+1<=k;j++){
            cur_sum=max(cur_sum,arr[j]);
            res=max(res,cur_sum*(j-i+1)+partitionSum(j+1,arr,k));
        }
        return memo[i]=res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(memo,-1,sizeof(memo));
        return partitionSum(0,arr,k);
    }
};