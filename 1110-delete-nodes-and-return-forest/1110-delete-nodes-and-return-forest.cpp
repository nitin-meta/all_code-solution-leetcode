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
    TreeNode* del(TreeNode*root, unordered_set<int>&st,vector<TreeNode*>&res){
        if(root==nullptr) return nullptr;
        root->left=del(root->left,st,res);
        root->right=del(root->right,st,res);
        if(st.find(root->val)!=st.end()){
            if(root->left!=NULL) res.push_back(root->left);
            if(root->right!=NULL) res.push_back(root->right);
            return nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_del) {
        vector<TreeNode*>res;
        unordered_set<int>st(to_del.begin(),to_del.end());
        del(root,st,res);
        if(st.find(root->val)==st.end()){
            res.push_back(root);
        }
        return res;
    }
};