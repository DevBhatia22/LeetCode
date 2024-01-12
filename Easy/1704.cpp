class Solution {
public:
    bool helpAreVowels(char temp){
        if(temp == 'a' || temp == 'A' || temp == 'e' || temp == 'E' || temp == 'i' || temp == 'I' || temp == 'o' || temp == 'O' || temp == 'u' || temp == 'U'){
            return true;
        }
        return 0;
    }
    bool halvesAreAlike(string s) {
        int firstHalf = 0;
        int secondHalf = 0;
        for(int i = 0; i < s.length(); i++){
            if(i < s.length() / 2){ 
                if(helpAreVowels(s[i])){
                    firstHalf++;
                }
            }
            else{
                if(helpAreVowels(s[i])){
                    secondHalf++;
                }
            }
        }
        return firstHalf == secondHalf;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();