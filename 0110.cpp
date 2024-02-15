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
    int help(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int x = help(root->left);
        if(x == -1){
            return -1;
        }
        int y = help(root->right);
        if(y == -1){
            return -1;
        }
        if(abs(x - y) > 1){
            return -1;
        }
        return x > y? x + 1: y + 1;
    }
    bool isBalanced(TreeNode* root) {
        int x = help(root);
        if(x != -1){
            return 1;
        }
        return 0;
    }
};