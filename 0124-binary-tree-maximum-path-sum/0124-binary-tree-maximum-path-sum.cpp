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
    int maxSum;
    int mps(TreeNode* root){
        if(!root) return 0;
        int left=mps(root->left);
        int right=mps(root->right);
        //Case 1- Jab left+right+root se acha mil jaye
        int lrr=left+right+root->val;
        //Case 2=- Jab koi left,right me achha ho
        int l_r_achha=max(left,right)+root->val;
        //case 3- Jab left,right dono me ki achha na ho
        int ek_achha=root->val;
        maxSum=max({maxSum,lrr,l_r_achha,ek_achha});
        //Ab Case 1 me sab path explore kar liye to return nhi kar sakte isliye case 2 aur case 3 se return kar denge answer
        return max(l_r_achha,ek_achha);
        
    }
    int maxPathSum(TreeNode* root) {
        maxSum=-1e9;
        mps(root);
        return maxSum;
        
    }
};