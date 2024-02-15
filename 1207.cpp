class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> map;
        std::unordered_set<int> set;
        for(int i:arr){
            map[i]++;
        }
        for(std::pair<int, int> i:map){
            if(set.find(i.second) == set.end()){
                set.insert(i.second);
            }
            else{
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