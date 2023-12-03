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
class BSTIterator {
public:
std::stack<TreeNode*> inOrder;
    void help(TreeNode* root){
        while(root){
            inOrder.push(root);
            root = root->left;
        }
        return;
    }
    BSTIterator(TreeNode* root) {
        help(root);
    }
    
    int next() {
        TreeNode* answer = inOrder.top();
        inOrder.pop();
        std::cout<<answer->val;
        help(answer->right);
        return answer->val;
    }
    
    bool hasNext() {
        return !inOrder.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */