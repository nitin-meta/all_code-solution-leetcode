class Solution {
public:
    char DFS(unordered_map<char,vector<char>>&adj,char u,vector<bool>&vis){
        vis[u-'a']=true;
        char mini=u;
        for(auto v:adj[u]){
            if(!vis[v-'a']){
                mini=min(mini,DFS(adj,v,vis));
            }
        }
        return mini;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string res;
        int n=s1.length(),m=baseStr.length();
        unordered_map<char,vector<char>>adj;
        for(int i=0;i<n;i++){
            char u=s1[i],v=s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<m;i++){
            char u=baseStr[i];
            vector<bool>vis(26,false);
            char mini=DFS(adj,u,vis);
            res.push_back(mini);
        }
        return res;
    }
};