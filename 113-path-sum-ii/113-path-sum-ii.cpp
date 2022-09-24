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
    vector<vector<int>> ans;
    
    void help(TreeNode* root, int targetSum,int sum, vector<int> output){
        if(!root) return ;
        output.push_back(root->val);
        sum += root->val;
        if(!root->left && !root->right && sum == targetSum) ans.push_back(output);
        else {
            help(root->left,targetSum,sum,output);
            help(root->right,targetSum,sum,output);
        }
        output.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> output;
        help(root,targetSum,0,output);
        return ans;
    }
};