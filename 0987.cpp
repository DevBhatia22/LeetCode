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
    void help(std::map<int, std::map<int, std::vector<int>>> &map1, TreeNode* root, int vl, int l){
        if(root == NULL){
            return;
        }
        map1[vl][l].push_back(root->val);
        help(map1, root->left, vl - 1, l + 1);
        help(map1, root->right, vl + 1, l + 1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        std::map<int, std::map<int, std::vector<int>>> map1;
        help(map1, root, 0, 0);
        std::vector<std::vector<int>> answer;
        for(auto i:map1){
            std::vector<int> temp;
            for(auto j:i.second){
                sort(j.second.begin(), j.second.end());
                for(int k:j.second){
                    temp.push_back(k);
                }
            }
            answer.push_back(temp);
        }
        return answer;
    }
};