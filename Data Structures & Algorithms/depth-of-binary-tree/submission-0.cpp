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
        if(root == NULL){
            return 0;
        }

        int max_left_subtree = maxDepth(root->left);
        int max_right_subtree = maxDepth(root->right);

        int max_Depth = max(max_left_subtree,max_right_subtree);
        int total = 1+ max_Depth;

        return total;
    }
};
