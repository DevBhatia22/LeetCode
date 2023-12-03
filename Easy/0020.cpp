class Solution {
public:
    bool isValid(string s) {
        std::ios_base::sync_with_stdio(false);
        std::stack<int> stk;
        for(char i:s){
            if(i==')' && !stk.empty() && stk.top()=='('){
                stk.pop();
            }
            else if(i=='}' && !stk.empty() && stk.top()=='{'){
                stk.pop();
            }
            else if(i==']' && !stk.empty() && stk.top()=='['){
                stk.pop();
            }
            else if(i=='(' || i=='{' || i=='['){
                stk.push(i);
            }
            else{
                return 0;
            }
        }
        if(stk.empty())
        return 1;
        else{return 0;}
    }
};