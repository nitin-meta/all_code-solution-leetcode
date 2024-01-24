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
    void f(TreeNode* root, vector<int>&cnt,int &res){
        if(root==nullptr) return;
        cnt[root->val]++;
        
        if(!root->left && !root->right){
            int oddFreq=0;
            for(int i=1;i<=9;i++){
                if(cnt[i]%2!=0) oddFreq++;
            }
            if(oddFreq<=1) res+=1;
        }
        f(root->left,cnt,res);
        f(root->right,cnt,res);
        cnt[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>cnt(10,0);
        int res=0;
        f(root,cnt,res);
        return res;
    }
};