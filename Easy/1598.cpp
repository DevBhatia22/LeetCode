class Solution {
public:
    int minOperations(vector<string>& logs){
        std::ios_base::sync_with_stdio(false);
        std::stack<string> s;
        for(std::string i:logs){
            if(i=="./"){
                continue;
            }
            else if(i=="../"){
                if(s.empty()){
                    
                }
                else{
                    s.pop();
                }
            }
            else{
                s.push(i);
            }
        }
        return s.size();
    }
};