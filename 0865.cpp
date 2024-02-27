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
    std::pair<TreeNode*, int> dfs(TreeNode* root, int level){
        if(!root){
            return {NULL, 0};
        }
        if(!root->left && !root->right){
            return {root, level};
        }
        std::pair<TreeNode*, int> left= dfs(root->left, level + 1);
        std::pair<TreeNode*, int> right= dfs(root->right, level + 1);
        if(left.second > right.second){
            return left;
        }
        if(right.second > left.second){
            return right;
        }
        return {root, left.second};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root, 0).first;
    }
};