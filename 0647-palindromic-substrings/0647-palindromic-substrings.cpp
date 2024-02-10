class Solution {
public:
    bool pali(string &s, int i,int j){
        if(i>=j) return true;
        if(s[i]!=s[j]) return false;
        return pali(s,i+1,j-1);
    }
    int countSubstrings(string s) {
        int n=s.length(),cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(pali(s,i,j)) cnt++;
            }
        }
        return cnt;
    }
};