class Solution {
public:
    int n;
    void dfs(vector<int>&vis,vector<int>&d,int node,vector<int>& edges){
        vis[node]=1;
        int v=edges[node];
        if(v!=-1 && !vis[v]){
            vis[v]=1;
            d[v]=1+d[node];
            dfs(vis,d,v,edges);
        }        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        //Takeway: Distance from one node to another and stored in vector
        n=edges.size();
        vector<int>d1(n,1e9),d2(n,1e9);//Distance Vector
        d1[node1]=0,d2[node2]=0;//Khud se khud ka duri 0 hoga na
        vector<int>vis1(n,0),vis2(n,0);
        dfs(vis1,d1,node1,edges);
        dfs(vis2,d2,node2,edges);
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