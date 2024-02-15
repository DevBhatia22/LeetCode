class Solution {
public:
    bool makeEqual(vector<string>& words) {
        std::unordered_map<char, int> map1;
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                map1[words[i][j]]++;
            }
        }
        for(auto i:map1){
            if(i.second % words.size()){
                return false;
            }
        }
        return true;
    }
};