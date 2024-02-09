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

//Morris Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        TreeNode* cur=root;
        while(cur!=NULL){
            if(cur->left==nullptr){
                res.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* leftC=cur->left;
                while(leftC->right!=nullptr){
                    leftC=leftC->right;
                }
                leftC->right=cur;
                //Left wale ko delete kardo
                TreeNode* temp=cur;
                cur=cur->left;
                temp->left=nullptr;
            }
        }
        return res;
    }
};