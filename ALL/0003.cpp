class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0){
            return 0;
        }
        std::map<char,bool> mp;
        mp[s[0]] = true;
        int i = 0, j = 0, count = 1, max = 1;
        while(i < s.length() - 1){
            if(j >= s.length() - 1 || mp[s[j + 1]]){
                mp[s[i]] = false;
                i++;
                count--;
            }
            else{
                mp[s[j + 1]] = true;
                j++;
                count++;
            }
            if(count > max){
                max = count;
            }
            std::cout<<count<<"--"<<i<<"--"<<j<<"--";
        }
        return max;
    }
};