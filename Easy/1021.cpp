class Solution {
public:
    string removeOuterParentheses(string s){
        std::ios_base::sync_with_stdio(false);
        std::string str_re="";
        std::stack<int> stack1;
        for(char i:s){
            if(i=='('){
                stack1.push(i);
            }
            if(stack1.size()>1){
                str_re.push_back(i);
            }
            if(i==')'){
                stack1.pop();
            }
        }
        return str_re;
    }
};