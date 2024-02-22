class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int cnt[1001];
        for(auto it:trust){
            int u=it[0],v=it[1];
            /*
            3
           / \
           1  2
           1-> and 2->3 aur 3 judge hai
            
            */
            cnt[u]--;//nikal rha directed edge towards v
            cnt[v]++;
        }
        for(int i=1;i<=n;i++){
            if(cnt[i]==n-1)//exactly 1 people who doesnt trust anyone
                return i;
        }
        return -1;
    }
};