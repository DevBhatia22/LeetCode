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
    TreeNode* help(TreeNode* root){
        if(root == NULL){
            return NULL;
        }
        if(root->left != NULL){
            TreeNode* temp = help(root->left);
            TreeNode* currentRight = root->right;
            root->right = root->left;
            temp->right = currentRight;
            root->left = NULL;
            
            if(temp->right){
                return help(temp->right);
            }
            else{
                return temp;
            }
        }
        else if(root->right == NULL){
            return root;
        }
        else{
            return help(root->right);
        }
        return NULL;
    }
    void flatten(TreeNode* root) {
        help(root);
        return;
    }
};