/* Properties of Valid Binary Tree
1. every child->only one parent
2. Only one root->it has no parent
3. Connected-> only one component
*/

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int u=i;
            int left=leftChild[i];
            int right=rightChild[i];
            if(left!=-1){
                adj[u].push_back(left);
                if(mp.find(left)!=mp.end()) return false;
                mp[left]=u;
            }
             if(right!=-1){                 
                 adj[u].push_back(right);
                if(mp.find(right)!=mp.end()) return false;
                mp[right]=u;
            }
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(mp.find(i)==mp.end()){
                if(root!=-1) return false;
                root=i;
            }
        }
        if(root==-1) return false;
        int cnt=1;
        queue<int>q;
        vector<int>vis(n,0);
        q.push(root);
        vis[root]=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:adj[u]){
                if(!vis[v]){
                    vis[v]=1;
                    cnt++;
                    q.push(v);
                }
            }
        }
        cout<<cnt;
        return cnt==n;
    }
};