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
private: 
    void invert(TreeNode* root) {
        if (!root) {
            return;
        }

        TreeNode* right = root->right;
        TreeNode* left = root->left; 
        root->right = left; 
        root->left = right; 
        invert(root->left); 
        invert(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        // invert(root);
        // return root;
        if (!root) return root; 
        queue<TreeNode*> track;
        track.push(root); 

        while (!track.empty()) {
            TreeNode* tree = track.front(); 
            track.pop(); 

            TreeNode* right = tree->right; 
            TreeNode* left = tree->left; 

            if (right) track.push(right);
            if (left) track.push(left); 

            tree->right = left; 
            tree->left = right; 
        }

        return root; 
    }
};
