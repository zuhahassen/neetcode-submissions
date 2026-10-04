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
    bool dfs (TreeNode* root, int minN, int maxN) {
        if (!root) {
            return true;
        }

        if (root->val <= minN || root->val >= maxN) {
            return false; 
        }

        return dfs(root->right, root->val, maxN) && dfs(root->left, minN, root->val);
    }

    bool isValidBST(TreeNode* root) {
        int minN = INT_MIN; 
        int maxN = INT_MAX; 
        return dfs(root, minN, maxN);
    }
};
