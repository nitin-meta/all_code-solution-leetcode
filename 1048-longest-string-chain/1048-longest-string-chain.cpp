//LIS Variant Code hai Same to Same Dimaag kholkar banao

class Solution {
public:
    int n;
    int memo[1001][1001];
    bool isPredecessor(string &prev,string &curr){
        int lenP=prev.length(),lenC=curr.length();
        if(lenP>lenC || lenC-lenP!=1) return false;
        int i=0,j=0;
        while(i<lenP && j<lenC){
            if(prev[i]==curr[j]) i++;
            j++;
        }
        return i==lenP;
    }
    // int LisVar(int curr,vector<string>&words,int prev){
    //     if(curr==n) return 0;
    //     if(prev!=-1 &&memo[prev][curr]!=-1) return memo[prev][curr];
    //     int take=0;
    //     if(prev==-1 || isPredecessor(words[prev],words[curr])){
    //         take=1+LisVar(curr+1,words,curr);
    //     }
    //     int nottake=LisVar(curr+1,words,prev);
    //     return prev!=-1? memo[prev][curr]=max(take,nottake):max(take,nottake);
    // }
    int longestStrChain(vector<string>& words) {
        n=words.size();
        sort(words.begin(),words.end(),[&](string &s1,string &s2){
            return s1.length()<s2.length();
        });
        // memset(memo,-1,sizeof(memo));
        vector<int>dp(n,1);
        int maxLen=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isPredecessor(words[j],words[i])){
                    dp[i]=max(dp[i],1+dp[j]);
                    maxLen=max(maxLen,dp[i]);
                }
            }
        }
        
        return maxLen;
    }
};