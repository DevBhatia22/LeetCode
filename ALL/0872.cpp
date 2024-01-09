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
    void help(TreeNode* root, std::vector<int> &vec){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            vec.push_back(root->val);
            return;
        }
        help(root->left, vec);
        help(root->right, vec);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> vec1, vec2;
        help(root1, vec1);
        help(root2, vec2);
        if(vec1.size() != vec2.size()){
            return 0;
        }
        for(int i = 0; i < vec2.size(); i++){
            if(vec1[i] != vec2[i]){
                return 0;
            }
            std::cout<<vec1[i];
        }
        return 1;
    }
};