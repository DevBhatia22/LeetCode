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
    std::string dfs(TreeNode* root, std::unordered_map<std::string, int>& map, std::vector<TreeNode*>& answers){
        if(!root){
            return ".";
        }
        std::string temp = dfs(root->left, map, answers);
        temp += std::to_string(root->val);
        temp += dfs(root->right, map, answers);
        if(map[temp] == 1){
            answers.push_back(root);
        }
        map[temp]++;
        return temp + "0";
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        std::vector<TreeNode*> answers;
        std::unordered_map<std::string, int> map;
        dfs(root, map, answers);
        return answers;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();