class Solution {
public:
    string removeDuplicates(string s) {
        std::ios_base::sync_with_stdio(false);
        std::stack<char> s1;
        for(char i:s){
            if(s1.empty() || s1.top()!=i){
                s1.push(i);
            }
            else{
                s1.pop();
            }
        }
        s="";
        while(!s1.empty()){
            s.push_back(s1.top());
            s1.pop();
        }
        std::reverse(s.begin(),s.end());
        return s;
    }
};