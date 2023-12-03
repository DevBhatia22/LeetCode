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
    TreeNode* prev = NULL;
    TreeNode* curr = NULL;
    void help(TreeNode* root, TreeNode* &errorFirst, TreeNode* &errorLast){
        if(!root){
            return;
        }
        help(root->left, errorFirst, errorLast);
        prev = curr;
        curr = root;
        if(!prev){
            help(root->right, errorFirst, errorLast);
            return;
        }
        if(prev->val > curr->val){
            if(!errorFirst){
                errorLast = curr;
                errorFirst = prev;
            }
            else{
                errorLast = root;
            }
        }
        
        help(root->right, errorFirst, errorLast);
        return;
    }
    void recoverTree(TreeNode* root) {
        if(!root){
            return;
        }
        TreeNode* errorFirst = NULL;
        TreeNode* errorLast = NULL;
        help(root, errorFirst, errorLast);
        std::swap(errorFirst->val, errorLast->val);
        return;
    }
};