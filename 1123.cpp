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
private:
    std::pair<int, TreeNode*> dfs(int height, TreeNode* root){
        if(!root){
            return {0, NULL};
        }
        if(!root->left && !root->right){
            return{height, root};
        }
        std::pair<int, TreeNode*> left = dfs(height + 1, root->left);
        std::pair<int, TreeNode*> right = dfs(height + 1, root->right);
        if(left.first > right.first){
            return left;
        }
        if(left.first < right.first){
            return right;
        }
        return {left.first, root};

    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(0, root).second;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();