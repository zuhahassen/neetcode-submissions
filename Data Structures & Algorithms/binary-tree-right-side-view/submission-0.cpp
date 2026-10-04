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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if (!root) {
            return res; 
        } 

        //res.push_back(root->val);

        queue<TreeNode*> track; 
        track.push(root);

        while(!track.empty()) {
            int size = track.size(); 
            int lastNum; 
            for (int i = 0; i < size; i++) {
                TreeNode* node = track.front(); 
                track.pop(); 

                lastNum = node->val; 

                if (node->left) track.push(node->left);
                if (node->right) track.push(node->right);
            }

            res.push_back(lastNum);
        }

        return res; 
    }
};
