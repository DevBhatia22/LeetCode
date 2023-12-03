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
class bstIteratorForward{
    public:
    std::stack<TreeNode* > stk;
    
    void help(TreeNode* root){
        
        if(!root){
            return;
        }
        
        while(root){
            stk.push(root);
            root = root->left;
        }
        
        return;
    }
    
    bstIteratorForward(TreeNode* root){
        
        help(root);
        
    }
    
    TreeNode* next(){
        TreeNode* temp = stk.top();
        stk.pop();
        help(temp->right);
        return temp;
    }
};

class bstIteratorBackward{
    public:
    std::stack<TreeNode* > stk;
    
    void help(TreeNode* root){
        if(!root){
            return;
        }
        
        while(root){
            stk.push(root);
            root = root->right;
        }
        
        return;
    }
    
    bstIteratorBackward(TreeNode* root){
        help(root);
    }
    
    TreeNode* back(){
        TreeNode* temp = stk.top();
        stk.pop();
        help(temp->left);
        return temp;
    }
};
class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return false;
        }
        
        bstIteratorForward* i = new bstIteratorForward(root);
        bstIteratorBackward* j = new bstIteratorBackward(root);
        TreeNode* front = i->next();
        TreeNode* back = j->back();
        while(front != back){
            if(front->val + back->val == k){
                return true;
            }
            if(front->val + back->val > k){
                back = j->back();
            }
            else{
                front = i->next();
            }
        }
        return false;
    }
};