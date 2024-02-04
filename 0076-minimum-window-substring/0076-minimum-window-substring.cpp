class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int n=s.length(),m=t.length();
        if(m>n) return "";
        for(auto ch:t) mp[ch]++;
        int i=0,j=0,win_len=INT_MAX,str_start=0;
        while(j<n){
            char ch=s[j];
            if(mp[ch]>0) m--;
            mp[ch]--;
            //Maan Lo m 0 ho gya tab window to piche se shrink karenge
            while(m==0){
                int cur_len=j-i+1;
                if(win_len>cur_len){
                    win_len=cur_len;
                    str_start=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    m++;
                }
                i++;
            }
           j++;             
        }
        return win_len==INT_MAX?"": s.substr(str_start,win_len);
    }
};