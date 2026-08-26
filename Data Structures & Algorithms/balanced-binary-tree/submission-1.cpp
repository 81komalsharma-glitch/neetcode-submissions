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

    int height(TreeNode* root){
         if(root == NULL){
            return 0;
        }

        int left_subtree = height(root->left);
        if(left_subtree == -1){
            return -1;
        }
        int right_subtree = height(root->right);
        if(right_subtree == -1){
            return -1;
        }

       if(abs(left_subtree - right_subtree) > 1){
        return -1;
       } 

       return 1 + max(left_subtree,right_subtree);

    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
       
    }
};