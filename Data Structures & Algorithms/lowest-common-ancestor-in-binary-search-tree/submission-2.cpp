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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode* curNode = root; 

        while (curNode) {

            TreeNode* left = curNode->left; 
            TreeNode* right = curNode->right; 

            if (p->val < curNode->val && q->val < curNode->val) {
                curNode = left; 
            } else if (p->val > curNode->val && q->val > curNode->val){
                curNode = right; 
            } else {
                return curNode;
            }
        }

        return nullptr; 
    }
};
