class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        std::vector<std::vector<std::string>> answer;
        for(std::string i:strs){
            std::string temp;
            temp = i;
            std::sort(temp.begin(), temp.end());
            map[temp].push_back(i);
        }
        for(std::pair<std::string, std::vector<std::string>> i:map){
            std::vector<string> temp;
            for(std::string j:i.second){
                temp.push_back(j);
            }
            answer.push_back(temp);
        }
        return answer;
    }
};