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
    int kthSmallest(TreeNode* root, int &k) {
        int temp = 0;
        if(root->left){
            temp = kthSmallest(root->left, k);
            if(k == 0){
                return temp;
            }
        }
        k--;
        if(k == 0){
            return root->val;
        }
        else{
            if(root->right){
                temp = kthSmallest(root->right, k);
            }
            else{
                temp = root->val;
            }
        }
        return temp;
    }
};