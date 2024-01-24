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
    std::unordered_map<int, int> map;
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        map[root->val]++;
        if(root->left == NULL && root->right == NULL){
            bool oneOdd = false;
            for(std::pair<int, int> i:map){
                if(i.second % 2 == 0){
                    continue;
                }
                else if(oneOdd){
                    map[root->val]--;
                    return 0;
                }
                else{
                    oneOdd = true;
                }
            }
            map[root->val]--;
            return 1;
        }
        int answer = pseudoPalindromicPaths(root->left) + pseudoPalindromicPaths(root->right);
        map[root->val]--;
        return answer;
    }
};