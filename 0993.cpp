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
    bool isCousins(TreeNode* root, int x, int y) {
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, 0});
        int returner = 0;
        while(!q.empty()){
            int size = q.size();
            int perentId = 1;
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front().first;
                int per = q.front().second;
                q.pop();
                if((temp->val == x || temp->val == y) && returner == 0){
                    returner = per;
                }
                else if(temp->val == x || temp->val == y){
                    if(returner == per){
                        return 0;
                    }
                    else{
                        return 1;
                    }
                }
                if(temp->right){
                    q.push({temp->right, perentId});
                }
                if(temp->left){
                    q.push({temp->left, perentId});
                }
                perentId++;
            }
            if(returner){
                return 0;
            }
        }
        return false;
    }
};