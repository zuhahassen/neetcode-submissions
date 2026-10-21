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
    unordered_map<int, int> inMap; 
    int index = 0; 
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left > right) {
            return nullptr; 
        }

        TreeNode* root = new TreeNode(preorder[index]);
        int pos = inMap[preorder[index]]; 
        index++; 

        root->left = build(preorder, inorder, left, pos - 1);
        root->right = build(preorder, inorder, pos + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i; 
        }

        return build(preorder, inorder, 0, preorder.size() - 1); 
    }
};
