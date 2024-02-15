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
    std::pair<int, int> help(TreeNode* root, int &max) {
        if(root == NULL){
            return std::pair<int, int>(INT_MAX, INT_MIN);
        }
        std::pair<int, int> left = help(root->left, max);
        std::pair<int, int> right = help(root->right, max);
        int max1 = std::max(root->val, std::max(left.second, right.second));
        int min1 = std::min(root->val, std::min(left.first, right.first));
        max = std::max(max, std::max(std::abs(root->val - min1), std::abs(root->val - max1)));
        return std::pair<int, int>(min1, max1);
    }
    int maxAncestorDiff(TreeNode* root) {
        int max = 0;
        help(root, max);
        return max;
    }
};