class Solution {
public:
    string largestOddNumber(string num) {
        std::ios_base::sync_with_stdio(false);
        int i = 0;
        
        for(i = num.length()-1; i > -1; i--){
            int last_number = num[i] - '0';
            if(last_number%2){
                break;
            }
        }
        
        for(int j = num.length()-1; j > i; j--){
            num.pop_back();
        }
        return num;
    }
};