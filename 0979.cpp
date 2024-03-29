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
    int dfs(TreeNode* root, int& answer){
        if(!root){
            return 0;
        }
        int left = dfs(root->left, answer);
        int right = dfs(root->right, answer);
        answer += std::abs(left) + std::abs(right);
        return right + left + root->val - 1;
    }
    int distributeCoins(TreeNode* root) {
        int answer = 0;
        dfs(root, answer);
        return answer;
    }
};