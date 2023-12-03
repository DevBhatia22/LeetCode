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
    void help(std::map<int, int> &map1, TreeNode* root, int height){
        if(root == NULL){
            return;
        }
        
        map1[height] = root->val;
        
        help(map1, root->left, height + 1);
        help(map1, root->right, height + 1);
        
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        std::map<int, int> map1;
        int height = 0;
        std::vector<int> answer;
        
        help(map1, root, 0);
        
        for(auto i:map1){
            answer.push_back(i.second);
        }
        
        return answer;
    }
};