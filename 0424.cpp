class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> map1;
        int start = 0, end = 0, max = 0, answer = 0;
        for(end = 0; end < s.length(); end++){
            map1[s[end]]++;
            max = std::max(max, map1[s[end]]);
            if((end - start + 1) - max > k){
                map1[s[start]]--;
                start++;
            }
            else{
                answer = std::max(answer, (end - start + 1));
            }
        }
        return answer;
    }
};