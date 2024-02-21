class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        std::string l = (std::bitset<32>(left)).to_string();
        std::string r = (std::bitset<32>(right)).to_string();
        if(l == r){
            return right;
        }
        bool ones = false;
        int answer = 0;
        for(int i = 0; i < 32; i++){
            if((l[i] == r[i]) && (l[i] == '0') && !ones){
                continue;
            }
            ones = true;
            if(l[i] == r[i] && l[i] == '1'){
                answer += std::pow(2, 32 - i - 1);
            }
            if(l[i] != r[i]){
                break;
            }
        }
        return answer;
    }
};