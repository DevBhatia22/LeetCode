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
    int helpHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return std::max(helpHeight(root->left), helpHeight(root->right)) + 1;
    }
    int helpLol(TreeNode* root, int start, int &infHeight, bool &l){
        if(root == NULL){
            return 0;
        }
        if(root->val == start){
            l = true;
            return (-1) * (helpHeight(root) - 1);
        }
        bool lef = false;
        bool r = false;
        int left = helpLol(root->left, start, infHeight, lef);
        int right = helpLol(root->right, start, infHeight, r);
        if(lef){
            l = true;
            infHeight++;
            if(std::abs(left) > (right + infHeight)){
                return (left);
            }
            else{
                return (-1) * (infHeight + right);
            }
        }
        else if(r){
            l = true;
            infHeight++;
            if(std::abs(right) > (left + infHeight)){
                return right;
            }
            else{
                return (-1) * (infHeight + left);
            }
        }
        return std::max(left, right) + 1;
    }
    int amountOfTime(TreeNode* root, int start) {
        int temp = 0;
        bool temp2 = false;
        int answer =  helpLol(root, start, temp, temp2);
        if(answer > 0){
            return answer;
        }
        return (-1) * answer;
    }
};