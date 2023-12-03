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
    int help(TreeNode* root, int &dia){
        if(root == NULL){
            return 0;
        }
        int x = root->left ? help(root->left, dia) : 0;
        int y = root->right ? help(root->right, dia) : 0;
        dia = std::max(dia, x + y);
        return max(x, y) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int x = 0;
        help(root, x);
        return x;
    }
};