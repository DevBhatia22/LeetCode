class Solution {
public:
    int minLength(string s) {
        std::stack<char> s1;
        for(char i:s){
            if(i!='B' && i!='D' || s1.empty()){
                s1.push(i);
            }
            else if(i=='B'){
                if(s1.top()=='A'){
                    s1.pop();
                }
                else{
                    s1.push(i);
                }
            }
            else{
                if(s1.top()=='C'){
                    s1.pop();
                }
                else{
                    s1.push(i);
                }
            }
        }
        return s1.size();
    }
};