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
    bool isEvenOddTree(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        bool level = true;
        while(!q.empty()){
            level ^= 1;
            int size = q.size();
            int prev;
            prev = level ? 1e6 + 1 : 0;
            for(int i = 0; i < size; i++){
                if(level){
                    if(prev <= q.front()->val || (q.front()->val % 2)){
                        return 0;
                    }
                    prev = q.front()->val;
                }
                else{
                    if(prev >= q.front()->val || !(q.front()->val % 2)){
                        return 0;
                    }
                    prev = q.front()->val;
                }
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
        return 1;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();