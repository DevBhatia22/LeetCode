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
    TreeNode* help(std::vector<int> &pre, int start, int end){
        if(start > end){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[start]);
        if(start == end){
            return root;
        }
        int i = start + 1;
        while(i <= end && pre[i] < pre[start]){
            i++;
        }
        root->left = help(pre, start + 1, i - 1);
        root->right = help(pre, i, end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return help(preorder, 0, preorder.size() - 1);
    }
};