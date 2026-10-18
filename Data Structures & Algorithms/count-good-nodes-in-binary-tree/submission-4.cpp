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
    int dfs (TreeNode* node, int largest) {
        if (!node) {
            return 0; 
        }

        if (node->val >= largest) {
            return 1 + dfs(node->left, node->val) + dfs(node->right, node->val);
        }

        return dfs(node->left, largest) + dfs(node->right, largest);
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};
