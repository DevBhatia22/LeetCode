class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()){
            return 0;
        }
        std::vector<int> vec1(26, 0), vec2(26, 0);
        std::set<char> set1, set2;
        std::map<int, int> map;
        for(char i:word1){
            vec1[i - 'a']++;
            set1.insert(i);
        }
        for(char i:word2){
            vec2[i - 'a']++;
            set2.insert(i);
        }
        if(set1 != set2){
            return 0;
        }
        for(int i:vec1){
            if(i == 0){
                continue;
            }
            map[i]++;
        }
        for(int i:vec2){
            if(i == 0){
                continue;
            }
            map[i]--;
        }
        for(std::pair<int, int> pair:map){
            if(pair.second != 0){
                return 0;
            }
        }
        return 1;
    }
};
auto init = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
} ();