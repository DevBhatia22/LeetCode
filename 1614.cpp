class Solution {
public:
    int maxDepth(string s) {
        std::ios_base::sync_with_stdio(false);
        std::stack<int> stack1;
        int max=0;
        for(char i:s){
            if(i=='('){
                stack1.push(i);
            }
            else if(i==')'){
                stack1.pop();
            }
            if(stack1.size()>max){
                max=stack1.size();
            }
        }
        return max;
    }
};