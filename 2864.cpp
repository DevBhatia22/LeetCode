class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int num = 0;
        for(char i:s){
            if(i == '1'){
                num++;
            }
        }
        for(int i = 0; i < s.size(); i++){
            if(i < num - 1){
                s[i] = '1';
            }
            else{
                s[i] = '0';
            }
        }
        s[s.size() - 1] = '1';
        return s;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();