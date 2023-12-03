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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> vec;
        if(root == NULL){
            return vec;
        }
        std::queue<TreeNode*> queue;
        queue.push(root);
        int n = 1;
        std::vector<int> temp;
        temp.push_back(root->val);
        temp.erase(temp.begin(), temp.end());
        while(queue.empty() == false){
            if(n == 0){
                n = queue.size();
                vec.push_back(temp);
                temp.erase(temp.begin(), temp.end());
            }
            else{
                TreeNode* current = queue.front();
                if(current->left){
                    queue.push(current->left);
                }
                if(current->right){
                    queue.push(current->right);
                }
                n--;
                temp.push_back(current->val);
                queue.pop();
            }
        }
        vec.push_back(temp);
        for(int i = 1; i < vec.size(); i += 2){
            std::reverse(vec[i].begin(), vec[i].end());
        }
        return vec;
    }
};