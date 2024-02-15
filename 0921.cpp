class Solution {
public:
    int minAddToMakeValid(string s) {
        std::stack<char> stk;
        int count=0;
        for(char i:s){
            if(i==')'){
                if(stk.empty()){
                    count++;
                }
                else{
                    stk.pop();
                }
            }
            else{
                stk.push(i);
            }
        }
        return count+stk.size();
    }
};