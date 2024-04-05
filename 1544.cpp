class Solution {
public:
    string makeGood(string s) {
        std::stack<char> stk;
        for(char i:s){
            if(stk.empty()){
                stk.push(i);
            }
            else{
                if(std::abs(stk.top() - i) == 'a' - 'A'){
                    stk.pop();
                }
                else{
                    stk.push(i);
                }
            }
        }
        s = "";
        while(!stk.empty()){
            s = stk.top() + s;
            stk.pop();
        }
        return s;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 'c';
} ();