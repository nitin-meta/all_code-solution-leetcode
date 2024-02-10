class Solution {
public:
    void pali(string &s, int i,int j,int n,int &cnt){
        while(i>=0 && j<n &&s[i]==s[j]){
            cnt++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        int n=s.length(),cnt=0;
        for(int i=0;i<n;i++){
            pali(s,i,i,n,cnt);
            pali(s,i,i+1,n,cnt);
        }
        return cnt;
    }
};