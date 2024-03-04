class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size(),score=0,maxi=0;
        int i=0,j=n-1;
        sort(tokens.begin(),tokens.end());
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i],score++;
                i++;
                maxi=max(maxi,score);
            }
            else if(power<tokens[i] && score>=1){
                power+=tokens[j],score--;//maximum token lena chahenge na lalchi banna hai
                j--;
            }
            else return maxi;
        }
        return maxi;
    }
};