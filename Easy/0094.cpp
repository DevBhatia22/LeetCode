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
    void arrayUpdate(std::vector<int> &answer, TreeNode* root){
        if(root == NULL){
            return;
        }
        
        if(root->left){
            arrayUpdate(answer, root->left);
        }
        answer.push_back(root->val);
        if(root->right){
            arrayUpdate(answer, root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> answer;
        arrayUpdate(answer, root);
        return answer;
    }
};