class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(std::string i:words){
            std::string temp = i;
            std::reverse(i.begin(), i.end());
            if(i == temp){
                return temp;
            }
        }
        return "";
    }
};