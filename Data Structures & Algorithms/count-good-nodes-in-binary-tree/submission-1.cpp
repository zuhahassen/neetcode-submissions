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
    int goodNodes(TreeNode* root) {
        int count = 0; 
        int max_num = root->val; 
        dfs(root, count, max_num);
        return count; 
    }
private: 
    void dfs(TreeNode* node, int& count, int max_num) {
        if (!node) {
            return;
        }

        if (node->val >= max_num) {
            count++;
        }

        max_num = max(max_num, node->val);

        dfs(node->left, count, max_num);
        dfs(node->right, count, max_num);
    }
};
