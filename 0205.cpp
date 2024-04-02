class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::unordered_map<char, char> map1, map2;
        for(int i = 0 ; i < s.size(); i++){
            if(map1.find(s[i]) == map1.end() && map2.find(t[i]) == map2.end()){
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
            else if(map1[s[i]] != t[i] || map2[t[i]] != s[i]){
                return false;
            }
        }
        return true;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
} ();