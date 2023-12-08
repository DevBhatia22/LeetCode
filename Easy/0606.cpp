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
    void help(TreeNode* root, std::string &str){
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        if(root == NULL){
            return;
        }
        str += std::to_string(root->val);
        if(root->left != NULL){
            str += "(";
            help(root->left, str);
            str += ")";
        }
        else if(root->right != NULL){
            str += "()";
        }
        if(root->right != NULL){
            str += "(";
            help(root->right, str);
            str += ")";
        }
        return;
    }
public:
    string tree2str(TreeNode* root) {
        std::string answer;
        help(root, answer);
        return answer;
    }
};