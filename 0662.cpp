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
    int widthOfBinaryTree(TreeNode* root) {
        std::queue<std::pair<TreeNode*, long long>> queue;
        queue.push(std::pair<TreeNode*, long long>(root, 0));
        int answer = 1;
        
        while(!queue.empty()){
            if(queue.back().second - queue.front().second + 1 > answer){
                answer = queue.back().second - queue.front().second + 1;
            }
            int length = queue.size();
            int lol = queue.front().second;
            for(int i = 0; i < length; i++){
                TreeNode* temp = queue.front().first;
                queue.front().second -= lol;
                if(temp->left){
                    queue.push(std::pair<TreeNode*, long long>(temp->left, 2 * queue.front().second - lol));
                }
                if(temp->right){
                    queue.push(std::pair<TreeNode*, long long>(temp->right, 2 * queue.front().second + 1 - lol));
                }
                std::cout<<queue.front().second<<" ";
                queue.pop();
            }
            std::cout<<std::endl;
        }
        // std::cout<<answer;
        return answer;
    }
};