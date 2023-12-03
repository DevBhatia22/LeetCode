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
    bool help(TreeNode* rootLeft, TreeNode* rootRight){
        if(rootLeft == NULL && rootRight == NULL){
            return true;
        }
        else if(rootLeft == NULL || rootRight == NULL){
            return false;
        }
        
        if(rootLeft->val != rootRight->val){
            return false;
        }
        
        return help(rootLeft->left, rootRight->right) && help(rootLeft->right, rootRight->left);
    }
    bool isSymmetric(TreeNode* root) {
        return help(root->left, root->right);
    }
};