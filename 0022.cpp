class Solution {
public:
    int BD_god(int N, string s, vector<string> &vec, int o = 0, int c = 0){
    
        if(N == o){
            while(!(s.length() == 2 * N)){
                s += ')';
            }
            vec.push_back(s);
            return 0;
        }
        if(s == ""){
            BD_god(N, s + '(', vec, o + 1, c);
        }
        else if(s.back() == '('){
            BD_god(N, s + '(', vec, o + 1, c);
            BD_god(N, s + ')', vec, o, c + 1);
        }
        else if(o == c){
            BD_god(N, s + '(', vec, o + 1, c);
        }
        else{
            BD_god(N, s + '(', vec, o + 1, c);
            BD_god(N, s + ')', vec, o, c + 1);
        }
        return 0;
    }
    vector<string> generateParenthesis(int N){
        
        // Write your code here.
        std::vector<string> vec;
        string s = "";
        BD_god(N, s, vec);
        return vec;
        
    }
};