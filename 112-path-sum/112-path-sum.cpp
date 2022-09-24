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
    
    bool rec(TreeNode* root, int targetSum,int sum){
        if(!root) return false;
        sum += root->val;
        if(!root->left && !root->right && sum == targetSum) return true;
       return rec(root->left,targetSum,sum) ||
        rec(root->right,targetSum,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return rec(root,targetSum,0);
    }
};