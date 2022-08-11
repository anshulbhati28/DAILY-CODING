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
    
//     bool isValidBST(TreeNode* root, long minval, long maxval){
//         if(root == NULL) return true;
//         if(root->val >= maxval || root->val <= minval) return false;
//     return isValidBST(root->left,minval,root->val) && isValidBST(root->right,root->val,maxval);
//     }
    
//     bool isValidBST(TreeNode* root) {
//         return isValidBST(root,INT_MIN,INT_MAX);
//     }
    
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
    bool isValidBST(TreeNode* root, long min, long max){
        if(root==NULL) return true;
        
        //not in range
        if(root->val >= max || root->val<=min) return false;
        
        // check on left, if it's lesser than root->val
        // check on right, if it's greater than root->val
        // keep a recursive check on subtree's left & right
        bool left=isValidBST(root->left, min, root->val);
        bool right=isValidBST(root->right, root->val,max);
        
        return left && right; // if both L & R say it's a BST, then it's BST 
    }
    
    
};