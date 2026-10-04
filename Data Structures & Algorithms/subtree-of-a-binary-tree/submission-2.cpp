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
    bool isSame(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true; 
        }

        if (!p || !q) {
            return false; 
        } 
        
        if (p->val == q->val) {
            return isSame(p->left, q->left) && isSame(p->right, q->right);
        }
        return false; 
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true; 
        }
        if (!subRoot) {
            return true;
        }
        if (!root) {
            return false;
        }

        if (root->val == subRoot->val) {
            if (isSame(root, subRoot)) {
                return true;
            }
        }

        return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
        
    }
};
