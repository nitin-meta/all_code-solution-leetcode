class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int head=0,tail=0,ans=0;
        for(head=0;head<s.size();head++){
            mp[s[head]]++;
            while(mp[s[head]]>1){
                mp[s[tail]]--;
                tail++;
            }
            ans=max(ans,head-tail+1);              //to figure it out why (head-tail+1)
        }
        return ans;               //here why (head-tail)
    }
};