/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL){
            return "";
        }
        std::string str;
        std::queue<TreeNode*> queue;
        queue.push(root);
        std::vector<int> vec;
        vec.push_back(root->val);
        while(!queue.empty()){
            if(queue.front()->left){
                vec.push_back(queue.front()->left->val);
                queue.push(queue.front()->left);
            }
            else{
                vec.push_back(1001);
            }
            if(queue.front()->right){
                vec.push_back(queue.front()->right->val);
                queue.push(queue.front()->right);
            }
            else{
                vec.push_back(1001);
            }
            queue.pop();
        }
        int i;
        for(i = vec.size() - 1; i > -1; i--){
            if(vec[i] != 1001){
                break;
            }
        }
        for(int j = 0; j <= i; j++){
            str += to_string(vec[j]) + " ";
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == ""){
            return NULL;
        }
        std::vector<int> vec;
        std::string temp;
        for(char i:data){
            if(i == ' '){
                vec.push_back(std::stoi(temp));
                temp = "";
            }
            else{
                temp += i;
            }
        }
        TreeNode* root = new TreeNode(vec[0]);
        std::queue<TreeNode*> queue;
        queue.push(root);
        int i = 0;
        while(i < vec.size()){
            if(i < vec.size() - 1 && vec[i + 1] != 1001){
                queue.front()->left = new TreeNode(vec[i + 1]);
                queue.push(queue.front()->left);
            }
            else{
                queue.front()->left = NULL;
            }
            i++;
            if(i < vec.size() - 1 && vec[i + 1] != 1001){
                queue.front()->right = new TreeNode(vec[i + 1]);
                queue.push(queue.front()->right);
            }
            else{
                queue.front()->right = NULL;
            }
            i++;
            queue.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));