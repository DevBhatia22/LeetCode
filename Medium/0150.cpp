class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stk;
        for(string i:tokens){
            if(i == "+"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(y + x);
            }
            else if(i == "-"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(y - x);
            }
            else if(i == "*"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(y * x);
            }
            else if(i == "/"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(y / x);
            }
            else{
                stk.push(std::stoi(i));
            }
        }
        return stk.top();
    }
};