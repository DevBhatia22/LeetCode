class Solution {
public:
    int minSteps(string s, string t) {
        std::vector<int> map2(26, 0);
        for(int i = 0; i < s.length(); i++){
            map2[t[i] - 'a']++;
            map2[s[i] - 'a']--;
        }
        int count = 0;
        for(int i:map2){
            count += std::abs(i);
        }
        return count / 2;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();