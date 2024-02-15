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
        int x = help(root->left, dia);
        int y = help(root->right, dia);
        x = x > 0 ? x : 0;
        y = y > 0 ? y : 0;
        int z = std::max(x, y);
        int case1 = x + y + root->val;
        int case2 = z + root->val;
        dia = std::max(dia ,std::max(root->val, std::max(case1, case2)));
        return z + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int x = root->val;
        help(root, x);
        return x;
    }
};