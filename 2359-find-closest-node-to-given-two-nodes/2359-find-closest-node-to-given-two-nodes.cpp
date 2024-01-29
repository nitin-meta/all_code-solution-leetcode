//Using BFS
class Solution {
public:
    int n;
    void bfs(vector<int>&d,int node,vector<int>& edges){
        queue<int>q;
        d[node]=0;
        vector<bool>vis(n,false);
        q.push(node);
        vis[node]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            int v=edges[u];
            if(v!=-1 && !vis[v]){
                vis[v]=true;
                d[v]=1+d[u];
                q.push(v);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        //Takeway: Distance from one node to another and stored in vector
         n=edges.size();
        vector<int>d1(n,1e9),d2(n,1e9);//Distance Vector
        bfs(d1,node1,edges);
        bfs(d2,node2,edges);
        int res=-1,minD=1e9;
        for(int i=0;i<n;i++){
            int maxi=max(d1[i],d2[i]);
            if(minD>maxi){
                minD=maxi;
                res=i;
            }
        }
        return res;
    }
};