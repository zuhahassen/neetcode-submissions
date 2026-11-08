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
    int dfs(TreeNode* root, int& res) {
        if (!root) return 0; 

        int leftSum = max(dfs(root->left, res), 0); 
        int rightSum = max(dfs(root->right, res), 0);

        res = max(res, root->val + rightSum  + leftSum);

        return root->val + max(leftSum, rightSum); 
    }

    int maxPathSum(TreeNode* root) {
        int res = root->val; 
        dfs(root, res);
        return res; 
    }
};
