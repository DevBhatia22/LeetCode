class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        std::vector<int> vec(26, 0);
        for(int i = 0; i < s.length(); i++){
            vec[t[i] - 'a']--;
            vec[s[i] - 'a']++;
        }
        for(int j = 0; j < 26; j++){
            if(vec[j]){
                return 0;
            }
        }
        return true;
    }
};