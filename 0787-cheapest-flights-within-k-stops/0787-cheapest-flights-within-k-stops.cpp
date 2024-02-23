class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,1e5);
        //adjacency list
        unordered_map<int,vector<pair<int,int>>>adj; //u->v with cost
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v,cost});
        }
        //Normal BFS
        queue<pair<int,int>>q;//node aur cost store kar lete hai
        q.push({src,0});
        dist[src]=0;
        int cnt=0; //taki k node se jyada na visit kar paye uske liye 
        while(!q.empty() && cnt<=k){
            int sz=q.size();
            while(sz--){
            int u=q.front().first;
            int cost=q.front().second;
            q.pop();
            for(auto it:adj[u]){
                int v=it.first;
                int price=it.second;
                if(dist[v]>cost+price){
                    dist[v]=cost+price;
                    q.push({v,cost+price});
                }
            }   
            }
            cnt++;
        }
        return dist[dst]==1e5?-1:dist[dst];
    }
};