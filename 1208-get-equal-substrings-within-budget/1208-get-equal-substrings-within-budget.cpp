class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int head=0,tail=0,ans=0,cost=0;
        for(head=0;head<s.size();head++){
            cost+=abs(s[head]-t[head]);
            if(cost>maxCost){
                cost-=abs(s[tail]-t[tail]);
                tail++;
            }
            ans=max(ans,head-tail+1);
        }
        return ans;
    }
};