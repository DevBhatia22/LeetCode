class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        std::unordered_set<std::string> set;
        for(std::vector<std::string> i:paths){
            set.insert(i[0]);
        }
        for(std::vector<std::string> i:paths){
            if(set.find(i[1]) == set.end()){
                return i[1];
            }
        }
        return NULL;
    }
};