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
    int height(TreeNode* root) {
        if (!root) {
            return 0; 
        }

        return 1 + max(height(root->left), height(root->right));
    }
    vector<int> dfs(TreeNode* root) {
        if (!root) {
            return {1, 0};
        }

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right); 

        bool balanced = (left[0] == 1 && right[0] == 1) && (abs(left[1] - right[1]) <= 1);

        int height = 1 + max(left[1], right[1]); 
        
        if (balanced) {
            return {1, height};
        }

        return {0, height};
    }

    bool isBalanced(TreeNode* root) {
        // if (!root) {
        //     return true; 
        // }

        // int left = height(root->left);
        // int right = height(root->right);

        // if (abs(left - right) > 1) {
        //     return false; 
        // }

        // return isBalanced(root->right) && isBalanced(root->left); 

        return dfs(root)[0] == 1; 
    }
};
