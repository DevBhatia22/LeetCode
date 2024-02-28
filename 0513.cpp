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
    int findBottomLeftValue(TreeNode* root) {
        std::queue<std::pair<TreeNode*, bool>> q;
        q.push({root, 1});
        int answer = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front().first;
                bool yes = q.front().first;
                q.pop();
                if(yes){
                    answer = temp->val;
                }
                if(temp->right){
                    q.push({temp->right, 0});
                }
                if(temp->left){
                    q.push({temp->left, 1});
                }
            }
        }
        return answer;
    }
};