/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* help(std::vector<int> inorder, std::vector<int> preorder,
                        int start, int end, int& value) {
        if (start > end) {
            return NULL;
        }
        if (value >= preorder.size()) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[value]);
        if (start >= end) {
            value++;
            return root;
        }
        int checkPoint = 0;
        while (inorder[checkPoint] != preorder[value]) {
            checkPoint++;
        }
        value++;
        root->left = help(inorder, preorder, start, checkPoint - 1, value);
        root->right = help(inorder, preorder, checkPoint + 1, end, value);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int x = 0;
        TreeNode* root = help(inorder, preorder, 0, inorder.size() - 1, x);
        return root;
    }
};