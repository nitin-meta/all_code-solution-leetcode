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
void rview(TreeNode* root, int level,int &maxLevel,vector<int>&ans){
    if(root==nullptr) return;
    if(maxLevel<level){
        ans.push_back(root->val);
        maxLevel=level;
    }
    rview(root->right,level+1,maxLevel,ans);
    rview(root->left,level+1,maxLevel,ans);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int maxLevel=-1;
        rview(root,0,maxLevel,ans);
        return ans;
    }
};