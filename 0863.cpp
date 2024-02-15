/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void rootSearching(TreeNode* root, int k, std::vector<int>& answer) {
        if (root == NULL) {
            return;
        }
        if (k == 0) {
            answer.push_back(root->val);
        }
        rootSearching(root->left, k - 1, answer);
        rootSearching(root->right, k - 1, answer);
        return;
    }
    bool help(TreeNode* root, TreeNode* target, int& k,
              std::vector<int>& answer) {
        if (root == NULL) {
            return 0;
        }
        if (root == target) {
            rootSearching(root, k, answer);
            k--;
            return 1;
        }
        bool left = help(root->left, target, k, answer);
        if (left) {
            if (k == 0) {
                answer.push_back(root->val);
            } else {
                rootSearching(root->right, k - 1, answer);
            }
            k--;
            return 1;
        }
        bool right = help(root->right, target, k, answer);
        if (right) {
            if (k == 0) {
                answer.push_back(root->val);
            } else {
                rootSearching(root->left, k - 1, answer);
            }
            k--;
            return 1;
        }
        return 0;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        std::vector<int> answer;
        help(root, target, k, answer);
        return answer;
    }
};