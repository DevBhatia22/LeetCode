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
    bool help(TreeNode* root, long long min, long long max){
        if(root == NULL){
            return true;
        }
        if(root->val <= max || root->val >= min){
            return false;
        }
        return help(root->left, root->val, max) && help(root->right, min, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return help(root, LONG_MAX, LONG_MIN);
    }
};