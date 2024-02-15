class Solution {
public:
    int lengthOfLastWord(string s) {
        bool word = false;
        int count = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(word && s[i] == ' '){
                break;
            }
            if(s[i] != ' '){
                word = true;
            }
            if(word){
                count++;
            }
        }
        return count;
    }
};