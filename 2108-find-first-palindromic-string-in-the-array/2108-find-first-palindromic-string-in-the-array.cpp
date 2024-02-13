class Solution {
public:
    int n;
    bool isPal(string s){
        int n=s.length();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]) return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        n=words.size();
        for(int i=0;i<n;i++){
            if(isPal(words[i])) return words[i];
        }
        return "";
    }
};