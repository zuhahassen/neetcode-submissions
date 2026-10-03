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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, int>> track; 
        track.push({root,1}); 
        int maxDepth = 0; 

        while (!track.empty()) {
            auto node = track.front(); 
            track.pop(); 

            maxDepth = max(maxDepth, node.second); 

            if (node.first->left) {
                track.push({node.first->left, node.second + 1});
            }

            if (node.first->right) {
                track.push({node.first->right, node.second + 1});
            }
        
        }

        return maxDepth;
    }
};
