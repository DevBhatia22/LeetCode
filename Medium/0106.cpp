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
    TreeNode* help(vector<int>& inorder, std::vector<int>& postorder, int start, int end, int &postIndex){
        if(start > end){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postIndex]);
        int i = start;
        while(inorder[i] != postorder[postIndex]){
            i++;
        }
        postIndex--;
        root->right = help(inorder, postorder, i + 1, end, postIndex);
        root->left = help(inorder, postorder, start, i - 1, postIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int temp = inorder.size() - 1;
        return help(inorder, postorder, 0, inorder.size() - 1, temp);
    }
};