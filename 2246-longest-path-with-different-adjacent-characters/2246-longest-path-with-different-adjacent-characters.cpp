class Solution {
public:
    int res;
    int DFS(unordered_map<int,vector<int>>&adj,int u,int parent,string &s){
        int lng=0,secLong=0;
        for(auto v:adj[u]){
            if(v==parent) continue;
            int child_len=DFS(adj,v,u,s);
            if(s[v]==s[u]) continue;
            if(child_len>secLong) secLong=child_len;
            if(secLong>lng) swap(lng,secLong);
        }
            //Case-1- sab included
            int lrr=1+lng+secLong;
            //Case-2 Sirf root achha
            int rlr=1;
            //case-3 koi ek achha
            int kea=1+max(lng,secLong);
            res=max({res,lrr,rlr,kea});
            return max(kea,rlr);
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        unordered_map<int,vector<int>>adj;
        res=0;
        for(int i=1;i<n;i++){
            int u=i;
            int v=parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        DFS(adj,0,-1,s);
        return res;
    }
};