class Solution {
public:
    void dfs(vector<vector<int>>& adj,int src,int target,vector<vector<int>>&res,vector<int>&temp){
        temp.push_back(src);
        if(src==target) res.push_back(temp);
        else{
            for(auto v:adj[src]){
                dfs(adj,v,target,res,temp);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<vector<int>> res;
        vector<int>temp;
        int src=0,target=V-1;
        dfs(adj,src,target,res,temp);
        return res;
    }
};