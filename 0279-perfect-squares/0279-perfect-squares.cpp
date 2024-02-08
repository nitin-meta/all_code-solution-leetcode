class Solution {
public:
    int memo[10001];
    int f(int n){
        int cnt=0,res=1e9;
        if(n==0) return 0;
        if(n==1) return 1;
        if(memo[n]!=-1) return memo[n];
        for(int i=1;i*i<=n;i++){
            int a=i*i;
            cnt=1+f(n-a);
            res=min(res,cnt);
        }
        return memo[n]=res;
    }
    int numSquares(int n) {
        memset(memo,-1,sizeof(memo));
        return f(n);
    }
};