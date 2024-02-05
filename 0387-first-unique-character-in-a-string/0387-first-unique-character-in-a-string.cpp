class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.length();
        vector<int>cnt(26,0);
        for(auto it:s){
            cnt[it-'a']++;
        }
        for(int i=0;i<n;i++){
            if(cnt[s[i]-'a']==1) return i;
        }
        return -1;
    }
};