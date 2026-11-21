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
    void dfs (TreeNode* root, int& good, int maxN) {
        if (!root) return; 
        if (root->val >= maxN) good++; 
        int nxtMax = max(maxN, root->val);

        dfs(root->left, good, nxtMax);
        dfs(root->right, good, nxtMax);

    }

    int goodNodes(TreeNode* root) {
        int good = 0; 
        dfs(root, good, INT_MIN);
        return good;
    }
};
