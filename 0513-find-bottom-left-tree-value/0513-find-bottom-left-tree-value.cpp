/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxi,ans;
    //maxi= to keep track of current depth 
    //ans if depth>maxi then ans=root->val
    void dfs(TreeNode * root, int depth){
        if(!root) return;
        if(depth>maxi){
            maxi=depth;
            ans=root->val;
        }
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        maxi=-1;
        dfs(root,0);
        return ans;
    }
};