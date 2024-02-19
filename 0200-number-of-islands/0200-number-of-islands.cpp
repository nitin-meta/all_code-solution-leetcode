class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int delta_row[] = {-1, 0, 1, 0};
            int delta_col[] = {0, 1, 0, -1};
            
            // //traverse in alll 8 direction as per gfg question
            // for(int a=-1;a<=1;a++){
            //     for(int b=-1;b<=1;b++){
            //         int siderow=row+a;
            //        int sidecol=col+b;
            //         if(siderow>=0 && siderow<n && sidecol>=0 &&
            //          sidecol<m && grid[siderow][sidecol]=='1' && !vis[siderow][sidecol] ){
            //             vis[siderow][sidecol]=1;
            //             q.push({siderow,sidecol});
            //         }
            //     }
            // }
            for(int i=0;i<4;i++){
                int siderow=row+delta_row[i];
                int sidecol=col+delta_col[i];
                if(siderow>=0 && siderow<n && sidecol>=0 &&
                      sidecol<m && grid[siderow][sidecol]=='1' && !vis[siderow][sidecol] ){
                         vis[siderow][sidecol]=1;
                         q.push({siderow,sidecol});
                     }
                
                }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};