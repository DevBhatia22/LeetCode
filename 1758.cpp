class Solution {
public:
    int minOperations(string s) {
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] - '0' == i%2){
                count++;
            }
        }
        int temp = s.length() - count;
        return std::min(temp, count);
    }
};